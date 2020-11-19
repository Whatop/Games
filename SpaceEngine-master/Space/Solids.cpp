#include "stdafx.h"
#include "Solids.h"

Solids::Solids(std::wstring fileName, Vec2 Pos)
{
	m_Solids = Sprite::Create(fileName);
	m_Solids->SetParent(this);
	SetPosition(Pos);
	m_Solids->A = 0;
}

Solids::~Solids()
{
}

void Solids::Update(float deltaTime, float Time)
{
}

void Solids::Render()
{
	m_Solids->Render();
}
	
void Solids::OnCollision(Object* other)
{
}
