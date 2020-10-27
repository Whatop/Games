#include "stdafx.h"
#include "Enemy3.h"

Enemy3::Enemy3()
{
	m_Idle = new Animation();
	m_Idle->SetParent(this);
	m_Idle->Init(10, true);
	m_Idle->AddContinueFrame(L"Painting/Enemy3/idle-", 1, 4);

	m_Walk = new Animation();
	m_Walk->SetParent(this);
	m_Walk->Init(10, true);
	m_Walk->AddContinueFrame(L"Painting/Enemy3/walk-", 1, 4);

	m_Attack_A = new Animation();
	m_Attack_A->SetParent(this);
	m_Attack_A->Init(5, true);
	m_Attack_A->AddContinueFrame(L"Painting/Enemy3/attack-A", 1, 10);


	m_Attack_B = new Animation();
	m_Attack_B->SetParent(this);
	m_Attack_B->Init(5, true);
	m_Attack_B->AddContinueFrame(L"Painting/Enemy3/attack-B", 1, 11);

	m_Attack_C = new Animation();
	m_Attack_C->SetParent(this);
	m_Attack_C->Init(5, true);
	m_Attack_C->AddContinueFrame(L"Painting/Enemy3/attack-C", 1, 8);

	m_Hit = new Animation();
	m_Hit->SetParent(this);
	m_Hit->Init(7, true);
	m_Hit->AddContinueFrame(L"Painting/Enemy3/hit-", 1, 3);

	m_Dead = new Animation();
	m_Dead->SetParent(this);
	m_Dead->Init(7, true);
	m_Dead->AddContinueFrame(L"Painting/Enemy3/dead-", 1, 4);


	m_ColBox = Sprite::Create(L"Painting/Player/ColBox.png");
	m_ColBox->m_Position = m_Position;

	m_HeadCol = Sprite::Create(L"Painting/Player/Head.png");
	m_HeadCol->m_Position = m_Position;

	m_FootCol = Sprite::Create(L"Painting/Player/Foot.png");
	m_FootCol->m_Position = m_Position;

	m_Left = Sprite::Create(L"Painting/Player/Side.png");
	m_Left->m_Position = m_Position;

	m_Right = Sprite::Create(L"Painting/Player/Side.png");
	m_Right->m_Position = m_Position;

	m_Slime = m_Idle;
	m_Slime->SetParent(this);
	m_EnemyStatus3 = EnemyStatus::IDLE;

	SetPosition(1920 / 2, 1500);

	m_BaseAngle = 0;
	m_LandAngle = 0 + m_BaseAngle;
	m_BaseAngle = 90;

	m_Hp = 100;
	m_MaxHp = 100;

	m_Speed = 200.f;

	m_JumpPower = 60.f;
	m_JumpTime = 0;
	m_JumpAccel = 0.f;
	m_PrevAccel = 0.f;

	m_isFall = false;
	m_isGround = false;//땅
	m_LastDireIsRight = true;

	m_RightCol = false;
	m_LeftCol = false;

	m_Layer = 3;

	m_AttackLate = 0.f;
	m_JumpLate = 0.f;

	m_ColBox->A = 0;
	m_HeadCol->A = 0;
	m_FootCol->A = 0;
	m_Left->A = 0;
	m_Right->A = 0;
}

Enemy3::~Enemy3()
{
}

void Enemy3::Move()
{
	if (PlayerPos.x > m_Position.x)
	{
		m_LastDireIsRight = false;
			m_Slime = m_Walk;
			m_EnemyStatus3 = EnemyStatus::WALK;
		
		if (!m_RightCol)
			Translate(m_Directon.x * m_Speed * dt, m_Directon.y * -m_Speed * dt);
	}
	if (PlayerPos.x < m_Position.x)
	{
		m_LastDireIsRight = true;
		m_Slime = m_Walk;
		m_EnemyStatus3 = EnemyStatus::WALK;

		if (!m_RightCol)
			Translate(m_Directon.x * -m_Speed * dt, m_Directon.y * m_Speed * dt);
	}
}
//점프 박자로 공격하는 패턴 만들어 볼까? 재밌을 것 같은딥
void Enemy3::Attack()
{
	if (m_EnemyStatus3 != EnemyStatus::ATTACK_A && m_EnemyStatus3 != EnemyStatus::WALK)
	{
		m_EnemyStatus3 = EnemyStatus::ATTACK_A;
	}

	if (m_EnemyStatus3 == EnemyStatus::ATTACK_A)
	{
		m_Slime = m_Attack_A;

		if (m_Slime->m_CurrentFrame == 10 - 1)
		{
			m_AttackLate = 0.3f;
			m_Attack_A->m_CurrentFrame = 0;
			m_EnemyStatus3 = EnemyStatus::IDLE;
			m_Slime = m_Idle;
		}
	}
}

void Enemy3::SetLookingDirection()
{
	if (m_LastDireIsRight)
	{
		m_Scale.x = 1;
	}
	else if (!m_LastDireIsRight)
	{
		m_Scale.x = -1;
	}
}

void Enemy3::Gravity()
{
	static float vy = 0;

	vy += GR * dt;

	if (!m_isGround)
	{
		m_Position.y += vy;
	}
	else
		vy = 0.f;
}

void Enemy3::SetDirection()
{
	Vec2 rot;
	rot.x = cos(D3DXToRadian((float)m_LandAngle));
	rot.y = sin(D3DXToRadian((float)m_LandAngle));

	m_Directon = m_Position - rot;

	D3DXVec2Normalize(&m_Directon, &rot);
}

void Enemy3::Update(float deltaTime, float Time)
{
	for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
		{
			PlayerPos = iter->m_Position;
		}
	}
	m_isGround = false;
	m_RightCol = false;
	m_LeftCol = false;

	if (m_AttackLate > 0)
		m_AttackLate -= dt;
	if (m_JumpLate > 0)
		m_JumpLate -= dt;

	ObjMgr->CollisionCheak(this, "Ground");
	ObjMgr->CollisionCheak(this, "Wall");

	if (m_EnemyStatus3 != EnemyStatus::JUMP)
		Gravity();

	SetDirection();
	SetLookingDirection();

	//if()
	if (m_EnemyStatus3 != EnemyStatus::ATTACK_A && m_EnemyStatus3 != EnemyStatus::ATTACK_B)
	{
		Move();
	}
	//if()플레이어가 일정거리 이상 왔을때 공격
	if (m_AttackLate <= 0)
		Attack();


	m_Slime->Update(deltaTime, Time);

	m_ColBox->m_Position = Vec2(m_Position.x, m_Position.y);
	m_HeadCol->m_Position = Vec2(m_Position.x, m_ColBox->m_Position.y);
	m_FootCol->m_Position = Vec2(m_Position.x, m_ColBox->m_Position.y);
	m_Left->m_Position = Vec2(m_Position.x - m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
	m_Right->m_Position = Vec2(m_Position.x + m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);

}

void Enemy3::Render()
{
	m_Slime->Render();
	m_ColBox->Render();
	m_HeadCol->Render();
	m_FootCol->Render();
	m_Left->Render();
	m_Right->Render();
}

void Enemy3::OnCollision(Object* other)
{
	if (other->m_Tag == "Ground")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_FootCol->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			m_isFall = false;
		}
	}
	if (other->m_Tag == "Wall")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
		{
			if (IntersectRect(&rc, &m_Left->m_Collision, &other->m_Collision))
			{
				m_LeftCol = true;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				m_RightCol = true;
			}
		}
	}
}
