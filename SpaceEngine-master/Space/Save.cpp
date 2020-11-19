#include "stdafx.h"
#include "Save.h"

Save::Save(Vec2 Pos)
{
	m_Save = new Animation();
	m_Save->SetParent(this);
	m_Save->Init(0.2f, true);
	m_Save->AddContinueFrame(L"Painting/Determination", 1, 2, COLORKEY_WHITE);
	SetPosition(Pos);
}

Save::~Save()
{
}

void Save::Update(float deltaTime, float Time)
{
	m_Save->Update(deltaTime, Time);
}

void Save::Render()
{
	m_Save->Render();
}

void Save::OnCollision(Object* other)
{
}
	