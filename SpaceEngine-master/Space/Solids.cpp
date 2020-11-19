#include "stdafx.h"
#include "Solids.h"

Solids::Solids(std::wstring fileName, Vec2 Pos)
{
	m_Solids = Sprite::Create(fileName);
	m_Solids->SetParent(this);
	SetPosition(Pos);
<<<<<<< HEAD
	m_Solids->A = 0;
=======
	//m_Solids->A = 0;
>>>>>>> fb7c4ba8d5f8bb2480b3d5b8d07fa8bc95ebb64a
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
