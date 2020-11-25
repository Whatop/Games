#include "stdafx.h"
#include "Pillar.h"
#include "Text_Bubbles.h"

Pillar::Pillar(Vec2 Pos)
{
	m_Pillar = Sprite::Create(L"Painting/Map/Last_Pillars.png", COLORKEY_WHITE);//���� ����� ���� �����̰�
	m_Pillar->SetParent(this);
	m_Pillar->SetScale(1, 1);
	m_Pos = 0;
	ptime = 0;
	SetPosition(Pos);

}

Pillar::~Pillar()
{
}

void Pillar::Update(float deltaTime, float Time)
{
	if (SceneDirector::GetInst()->m_scene == scene::dialogscene || SceneDirector::GetInst()->m_scene == scene::mainscene)
		m_Pillar->A = 255;
	else
		m_Pillar->A = 0;

		for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
			Pos = iter->m_Position;
	}
	
	if(Pos.x>270)
	SetPosition(386+200-Pos.x*0.75f + m_Pos , 0);

	if (SceneDirector::GetInst()->m_scene == scene::dialogscene)
	{
		ptime += dt;
		if (ptime > 2 && ptime < 7) {
			m_Pos -= (70 * dt);
		}
		
	}
}

void Pillar::Render()
{
	m_Pillar->Render();
}

void Pillar::OnCollision(Object* other)
{
}
