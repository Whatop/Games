#include "stdafx.h"
#include "Liquid.h"

Liquid::Liquid()
{
}

Liquid::~Liquid()
{
}
void Liquid::Move()
{
}

void Liquid::Gravity()
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

void Liquid::SetDirection()
{
	Vec2 rot;
	rot.x = cos(D3DXToRadian((float)m_LandAngle));
	rot.y = sin(D3DXToRadian((float)m_LandAngle));

	m_Directon = m_Position - rot;

	D3DXVec2Normalize(&m_Directon, &rot);
}

void Liquid::Update(float deltaTime, float Time)
{
}

void Liquid::Render()
{
}

void Liquid::OnCollision(Object* other)
{
}
