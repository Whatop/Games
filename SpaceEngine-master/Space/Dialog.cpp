#include "stdafx.h"
#include "Dialog.h"

Dialog::Dialog(Vec2 Pos)
{
	m_Dialog = Sprite::Create(L"Painting/Dialog/Dialog.png");
	m_Dialog->SetParent(this);
	SetPosition(Pos);
}

Dialog::~Dialog()
{
}

void Dialog::Move()
{
}

void Dialog::Update(float deltaTime, float Time)
{
}

void Dialog::Render()
{
	m_Dialog->Render();
}

void Dialog::OnCollision(Object* other)
{
	//if (m_Tag == "Player")
	//{
	//		ObjMgr->RemoveObject(this);
	//}
}
