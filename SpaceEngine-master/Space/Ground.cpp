#include "stdafx.h"
#include "Ground.h"

Ground::Ground(int direction)
{
	m_Ground = Sprite::Create(L"Painting/Map/Ground.png");
	m_Ground->SetParent(this);
	if (direction == _left) {
		SetPosition(2000, 1080 / 2);
		m_Rotation = D3DXToRadian(90);
	}
	if (direction == _right) {
		SetPosition(3500, 1080 / 2);
		m_Rotation = D3DXToRadian(90);
	}
	if (direction == _up)
		SetPosition(2800, 0);
	if (direction == _down)
		SetPosition(2800, 1080);
}

Ground::~Ground()
{
}

void Ground::Update(float deltaTime, float Time)
{
}

void Ground::Render()
{
	m_Ground->Render();
}

void Ground::OnCollision(Object* other)
{
}
