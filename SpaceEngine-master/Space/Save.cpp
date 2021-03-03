#include "stdafx.h"
#include "Save.h"

Save::Save(Vec2 Pos) // 사운드는 눌렀을때 나오기 때문에 Player에 있다.  회복 -> 저장 
//눌렀을때 회복, 저장끝낼떄 저장
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
	