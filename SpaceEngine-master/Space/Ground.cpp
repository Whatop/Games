#include "stdafx.h"
#include "Ground.h"

Ground::Ground(int direction)
{
	if (direction == _left) {
		m_Ground = Sprite::Create(L"Painting/Map/Wall.png");
		m_Ground->SetParent(this);
		SetPosition(1810, 1080 / 2);
	}
	if (direction == _right) {
		m_Ground = Sprite::Create(L"Painting/Map/Wall.png");
		m_Ground->SetParent(this);
		SetPosition(3735, 1080 / 2);
	}
	if (direction == _up) {
		m_Ground = Sprite::Create(L"Painting/Map/Ground.png");
		m_Ground->SetParent(this);
		SetPosition(2800, 0);
	}
	if (direction == _down) {
		m_Ground = Sprite::Create(L"Painting/Map/Ground.png");
		m_Ground->SetParent(this);
		SetPosition(2800, 1080);
	}
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
