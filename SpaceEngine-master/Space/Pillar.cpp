#include "stdafx.h"
#include "Pillar.h"

Pillar::Pillar(Vec2 Pos)
{
	m_Pillar = Sprite::Create(L"Painting/Map/Last_Pillars.png", COLORKEY_WHITE);//따로 기둥을 만들어서 움직이게
	m_Pillar->SetParent(this);
<<<<<<< HEAD
	m_Pillar->SetScale(1, 1);
	m_Pos = 0;
	ptime = 0;
	SetPosition(Pos);
=======
	//m_Pillar->SetScale(1, 1);
	ptime = 0;
	m_Pillar->SetPosition(Pos);
>>>>>>> fb7c4ba8d5f8bb2480b3d5b8d07fa8bc95ebb64a
}

Pillar::~Pillar()
{
}

void Pillar::Update(float deltaTime, float Time)
{
	for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
			Pos = iter->m_Position;
	}
<<<<<<< HEAD
	
	if(Pos.x>270)
	SetPosition(386+200-Pos.x*0.75f + m_Pos , 0);
=======
	m_Pillar->SetPosition(500 - (Pos.x * 0.8f) + m_Pos, 0);
>>>>>>> fb7c4ba8d5f8bb2480b3d5b8d07fa8bc95ebb64a

	if (SceneDirector::GetInst()->m_scene == scene::dialogscene)
	{
		ptime += dt;
		if(ptime > 2 && ptime < 7)
		m_Pos -= (70 * dt);
	}
<<<<<<< HEAD
=======
	printf("%f", m_Pillar->m_Position.x);
>>>>>>> fb7c4ba8d5f8bb2480b3d5b8d07fa8bc95ebb64a
}

void Pillar::Render()
{
	m_Pillar->Render();
}

void Pillar::OnCollision(Object* other)
{
}
