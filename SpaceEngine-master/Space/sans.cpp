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
<<<<<<< HEAD
		m_Position = Vec2(Pos.x + 450, Pos.y+2);
=======
		m_Position = Vec2(Pos.x + 470, Pos.y+2);
>>>>>>> fb7c4ba8d5f8bb2480b3d5b8d07fa8bc95ebb64a
}

void sans::Render()
{
	m_ColBox->Render();
}

void sans::OnCollision(Object* other)
{

}