#include "stdafx.h"
#include "Chest.h"

Chest::Chest(Vec2 Pos)
{
	m_Chest = Sprite::Create(L"Painting/Chest.png");
	m_Chest->SetParent(this);
	SetPosition(Pos);
	//m_ColBox= Sprite::Create(L"Painting/")
}

Chest::~Chest()
{
}

void Chest::Update(float deltaTime, float Time)
{
}

void Chest::Render()
{
	m_Chest->Render();
}

void Chest::OnCollision(Object* other)
{
}
