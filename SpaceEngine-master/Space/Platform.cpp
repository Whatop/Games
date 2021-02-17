#include "stdafx.h"
#include "Platform.h"

Platform::Platform(Vec2 Pos,int direction)
{
	m_platfrom = Sprite::Create(L"Painting/platfrom/platfrom.png");
	//m_pColBox = Sprite::Create(L"Painting/platfrom/ColBox.png");
	m_platfrom->SetParent(this);
	SetPosition(Pos);
//	m_platfrom->SetPosition(Pos);
	m_direction = direction;
	m_Speed = 300.f;
}

Platform::~Platform()
{
}

void Platform::Update(float deltaTime, float Time)
{
	if (m_direction == _left) {
		m_Position.x -= m_Speed * dt;
	}
	else if (m_direction == _right) {
		m_Position.x += m_Speed * dt;
	}
	else if (m_direction == _up) {
		m_Position.y -= m_Speed * dt;
	}
	else if (m_direction == _down) {
		m_Position.y += m_Speed * dt;
	}
	//m_platfrom->SetPosition(m_Position.x,m_Position.y+2);
}

void Platform::Render()
{
	m_platfrom->Render();
//	m_pColBox->Render();
}

void Platform::OnCollision(Object* obj)
{
}
