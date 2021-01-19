#include "stdafx.h"
#include "Chest.h"

Chest::Chest(Vec2 Pos)
{
	m_Chest = Sprite::Create(L"Painting/Chest.png");
	m_Chest->SetParent(this);
	SetPosition(Pos);
	//m_ColBox= Sprite::Create(L"Painting/")
	SetScale(5.5f, 5.5f);
}

Chest::~Chest()
{
}

void Chest::Update(float deltaTime, float Time)
{
	m_Rotation += D3DXToRadian(30);
}

void Chest::Render()
{
	m_Chest->Render();
}

void Chest::OnCollision(Object* other)
{
}
