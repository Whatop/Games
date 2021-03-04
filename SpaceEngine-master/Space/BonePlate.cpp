#include "stdafx.h"
#include "BonePlate.h"

BonePlate::BonePlate(Vec2 Pos)
{
	m_BonePlate = Sprite::Create(L"Painting/Map/Bones.png");
	m_BonePlate->SetParent(this);
	SetPosition(Pos);
}

BonePlate::~BonePlate()
{
}

void BonePlate::Update(float deltaTime, float Time)
{

}

void BonePlate::Render()
{
	m_BonePlate->Render();
}
