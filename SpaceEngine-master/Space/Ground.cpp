#include "stdafx.h"
#include "Ground.h"

Ground::Ground()
{
	m_Ground = Sprite::Create(L"Painting/Map/Ground.png");
	m_Ground->SetParent(this);
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
