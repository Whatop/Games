#include "stdafx.h"
#include "Pillar.h"

Pillar::Pillar(Vec2 Pos)
{
	m_Pillar = Sprite::Create(L"Painting/Map/Last_Pillars.png", COLORKEY_WHITE);//따로 기둥을 만들어서 움직이게
	m_Pillar->SetParent(this);
	//m_Pillar->SetScale(1, 1);
	ptime = 0;
	m_Pillar->SetPosition(Pos);
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
	m_Pillar->SetPosition(500 - (Pos.x * 0.8f) + m_Pos, 0);

	if (SceneDirector::GetInst()->m_scene == scene::dialogscene)
	{
		ptime += dt;
		if(ptime > 2 && ptime < 7)
		m_Pos -= (70 * dt);
	}
	printf("%f", m_Pillar->m_Position.x);
}

void Pillar::Render()
{
	m_Pillar->Render();
}

void Pillar::OnCollision(Object* other)
{
}
