#include "stdafx.h"
#include "Barrel.h"

Barrel::Barrel()
{
	m_Barrel = Sprite::Create(L"Painting/Boom.png");
	m_Barrel->SetParent(this);

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

	SetPosition(1920 / 2, 1500);

	m_BaseAngle = 0;
	m_LandAngle = 0 + m_BaseAngle;
	m_BaseAngle = 90;

	m_LastDireIsRight = true;
	m_isGround = false;

	m_RightCol = false;
	m_LeftCol = false;

	m_Speed = 40.f;
	m_ColBox->A = 0;
	m_HeadCol->A = 0;
	m_FootCol->A = 0;
	m_Left->A = 0;
	m_Right->A = 0;
}

Barrel::~Barrel()
{
}

void Barrel::Move()
{
	if (!m_RightCol && RightMove)
		Translate(m_Directon.x * m_Speed * dt, m_Directon.y * -m_Speed * dt);
	if (!m_LeftCol && LeftMove)
		Translate(m_Directon.x * -m_Speed * dt, m_Directon.y * m_Speed * dt);
}

void Barrel::SetLookingDirection()
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

void Barrel::Gravity()
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

void Barrel::SetDirection()
{
	Vec2 rot;
	rot.x = cos(D3DXToRadian((float)m_LandAngle));
	rot.y = sin(D3DXToRadian((float)m_LandAngle));

	m_Directon = m_Position - rot;

	D3DXVec2Normalize(&m_Directon, &rot);
}

void Barrel::Update(float deltaTime, float Time)
{
	m_isGround = false;
	m_RightCol = false;//º®
	m_LeftCol = false;

	ObjMgr->CollisionCheak(this, "Ground");
	ObjMgr->CollisionCheak(this, "Wall");


	Move();

	Gravity();

	SetDirection();
	SetLookingDirection();
	if (m_LastDireIsRight)
	{
		m_ColBox->m_Position = Vec2(m_Position.x, m_Position.y);
		m_HeadCol->m_Position = Vec2(m_Position.x, m_ColBox->m_Position.y);
		m_FootCol->m_Position = Vec2(m_Position.x, m_ColBox->m_Position.y);
		m_Left->m_Position = Vec2(m_Position.x - m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
		m_Right->m_Position = Vec2(m_Position.x + m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
	}
	else if (!m_LastDireIsRight)
	{
		m_ColBox->m_Position = Vec2(m_Position.x, m_Position.y);
		m_HeadCol->m_Position = Vec2(m_Position.x, m_ColBox->m_Position.y);
		m_FootCol->m_Position = Vec2(m_Position.x, m_ColBox->m_Position.y);
		m_Left->m_Position = Vec2(m_Position.x - m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
		m_Right->m_Position = Vec2(m_Position.x + m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
	}
}

void Barrel::Render()
{
	m_Barrel->Render();
	m_ColBox->Render();
	m_HeadCol->Render();
	m_FootCol->Render();
	m_Left->Render();
	m_Right->Render();
}

void Barrel::OnCollision(Object* other)
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
				LeftMove = false;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				m_RightCol = true;
				RightMove = false;
			}
		}
	}

	if (other->m_Tag == "Player")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
		{
			if (IntersectRect(&rc, &m_Left->m_Collision, &other->m_Collision))
			{
				if (INPUT->GetKey('E') == KeyState::DOWN)
				{
					RightMove = true;
					LeftMove = false;
				}
				else if (LeftMove)
				{
					LeftMove = false;
				}
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				if (INPUT->GetKey('E') == KeyState::DOWN)
				{
					LeftMove = true;
					RightMove = false;
				}
				else if (RightMove)
				{
					RightMove = false;
				}
			}
		}
	}
}
