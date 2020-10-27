#include "stdafx.h"
#include "sans.h"

sans::sans(Vec2 Pos)
{
	m_ColBox = Sprite::Create(L"Painting/sans/ColBox.png");
	m_ColBox->SetParent(this);

	m_ColBox->SetPosition(Pos);
}
sans::~sans()
{
}

void sans::Move()
{

}

void sans::Update(float deltaTime, float Time)
{
}

void sans::Render()
{
	m_ColBox->Render();
}

void sans::OnCollision(Object* other)
{

}