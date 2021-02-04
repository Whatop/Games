#include "stdafx.h"
#include "sans.h"

sans::sans(Vec2 Pos)
{
	m_ColBox = Sprite::Create(L"Painting/sans/sans.png");
	m_ColBox->SetParent(this);
	SetPosition(Pos);
}
sans::~sans()
{
}

void sans::Move()
{

}

void sans::Update(float deltaTime, float Time)
{
	for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
			Pos = iter->m_Position;
	}
	if (SceneDirector::GetInst()->m_scene == scene::dialogscene)
		m_Position = Vec2(Pos.x + 420, Pos.y);
}

void sans::Render()
{
	m_ColBox->Render();
}

void sans::OnCollision(Object* other)
{

}