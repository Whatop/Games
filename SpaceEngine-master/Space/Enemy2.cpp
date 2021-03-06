#include "stdafx.h"
#include "Enemy2.h"

Enemy2::Enemy2()
{
	m_Idle = new Animation();
	m_Idle->SetParent(this);
	m_Idle->Init(10, true);
	m_Idle->AddContinueFrame(L"Painting/Enemy2/idle-", 1, 4);

	m_Walk = new Animation();
	m_Walk->SetParent(this);
	m_Walk->Init(3, true);
	m_Walk->AddContinueFrame(L"Painting/Enemy2/walk-", 1, 6);

	m_Jump = new Animation();
	m_Jump->SetParent(this);
	m_Jump->Init(3, true);
	m_Jump->AddContinueFrame(L"Painting/Enemy2/jump-", 1, 5);


	m_Attack_A = new Animation();
	m_Attack_A->SetParent(this);
	m_Attack_A->Init(5, true);
	m_Attack_A->AddContinueFrame(L"Painting/Enemy2/attack-A", 1, 12);


	m_Attack_B = new Animation();
	m_Attack_B->SetParent(this);
	m_Attack_B->Init(5, true);
	m_Attack_B->AddContinueFrame(L"Painting/Enemy2/attack-B", 1, 7);


	m_Hit = new Animation();
	m_Hit->SetParent(this);
	m_Hit->Init(7, true);
	m_Hit->AddContinueFrame(L"Painting/Enemy2/hit-", 1, 3);

	m_Dead = new Animation();
	m_Dead->SetParent(this);
	m_Dead->Init(7, true);
	m_Dead->AddContinueFrame(L"Painting/Enemy2/dead-", 1, 4);


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

	m_Shield_Skull = m_Idle;
	m_Shield_Skull->SetParent(this);
	m_EnemyStatus2 = EnemyStatus::IDLE;

	SetPosition(1920 / 2, 1500);

	m_BaseAngle = 0;
	m_LandAngle = 0 + m_BaseAngle;
	m_BaseAngle = 90;

	m_Hp = 100;
	m_MaxHp = 100;

	m_Speed = 400.f;

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

Enemy2::~Enemy2()
{
}

void Enemy2::Move()
{
}
//점프 박자로 공격하는 패턴 만들어 볼까? 재밌을 것 같은딥
void Enemy2::Attack()
{
	if (m_EnemyStatus2 != EnemyStatus::ATTACK_A && m_EnemyStatus2 != EnemyStatus::JUMP)
	{
		m_EnemyStatus2 = EnemyStatus::ATTACK_A;
	}

	if (m_EnemyStatus2 == EnemyStatus::ATTACK_A)
	{
		m_Shield_Skull = m_Attack_A;

		if (m_Shield_Skull->m_CurrentFrame == 12 - 1)
		{
			m_AttackLate = 0.3f;
			m_Attack_A->m_CurrentFrame = 0;
			m_EnemyStatus2 = EnemyStatus::IDLE;
			m_Shield_Skull = m_Idle;
		}
	}
}

void Enemy2::Jump()
{
	if (m_EnemyStatus2 != EnemyStatus::JUMP && m_JumpLate <= 0.f)
	{
		m_JumpTime = 0;
		Pos = m_Position;
		m_EnemyStatus2 = EnemyStatus::JUMP;
		//ObjMgr->AddObject(new EffectMgr(L"Painting/Enemy1/attack-A", 1, 7, 5, m_Position), "Effect");
	}
	if (m_EnemyStatus2 == EnemyStatus::JUMP)
	{
		static float minus;
		m_Shield_Skull = m_Jump;

		m_PrevAccel = m_JumpAccel;

		m_JumpAccel = ((-GR) / 2 * m_JumpTime * m_JumpTime) + (m_JumpPower * m_JumpTime);
		m_JumpTime += dt * 20.f;
		m_Position.y = Pos.y - m_JumpAccel;

		if (m_PrevAccel > m_JumpAccel)
		{
			m_isFall = true;
		}

		if (m_JumpAccel < 0.f)
		{
			minus = m_JumpAccel;
		}
		if (m_JumpAccel >= 0.f)
		{
			if (PlayerPos.x > m_Position.x)
			{
				if (!m_RightCol)
					Translate(m_Speed * dt, m_Speed * dt);
				m_LastDireIsRight = true;
			}
			if (PlayerPos.x < m_Position.x)
			{
				m_LastDireIsRight = false;
				if (!m_LeftCol)
					Translate(-m_Speed * dt, m_Speed * dt);
			}
		}
		if (m_JumpAccel < 0.f || (m_isFall && m_isGround))
		{
			m_PrevAccel = 0.f;
			m_JumpLate = 0.1f;
			m_Shield_Skull = m_Idle;
			m_EnemyStatus2 = EnemyStatus::IDLE;
			m_Position.y += minus;
		}
	}
}

void Enemy2::SetLookingDirection()
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

void Enemy2::Gravity()
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

void Enemy2::SetDirection()
{
	Vec2 rot;
	rot.x = cos(D3DXToRadian((float)m_LandAngle));
	rot.y = sin(D3DXToRadian((float)m_LandAngle));

	m_Directon = m_Position - rot;

	D3DXVec2Normalize(&m_Directon, &rot);
}

void Enemy2::Update(float deltaTime, float Time)
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

	if (m_EnemyStatus2 != EnemyStatus::JUMP)
		Gravity();

	SetDirection();
	SetLookingDirection();

	//if()
	if (m_EnemyStatus2 != EnemyStatus::ATTACK_A && m_EnemyStatus2 != EnemyStatus::ATTACK_B)
	{
		Move();
		Jump();
	}
	//if()플레이어가 일정거리 이상 왔을때 공격
	if (m_AttackLate <= 0)
		Attack();


	m_Shield_Skull->Update(deltaTime, Time);

	m_ColBox->m_Position = Vec2(m_Position.x, m_Position.y);
	m_HeadCol->m_Position = Vec2(m_Position.x, m_ColBox->m_Position.y);
	m_FootCol->m_Position = Vec2(m_Position.x, m_ColBox->m_Position.y);
	m_Left->m_Position = Vec2(m_Position.x - m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
	m_Right->m_Position = Vec2(m_Position.x + m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);

}

void Enemy2::Render()
{
	m_Shield_Skull->Render();
	m_ColBox->Render();
	m_HeadCol->Render();
	m_FootCol->Render();
	m_Left->Render();
	m_Right->Render();
}

void Enemy2::OnCollision(Object* other)
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
