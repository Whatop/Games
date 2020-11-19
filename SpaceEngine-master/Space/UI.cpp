#include "stdafx.h"
#include "UI.h"
#include "Pillar.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Init()
{
	m_Curtain = Sprite::Create(L"Painting/Map/Layer.png",COLORKEY_WHITE);
	m_Curtain->m_Layer = 1;

	ObjMgr->AddObject(m_Curtain, "UI");

}

void UI::Release()
{
}

void UI::Update()
{
	for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
			PlayerPos = iter->m_Position;
	}
	m_Curtain->m_Position = Vec2(PlayerPos.x, PlayerPos.y);
}

void UI::Render()
{
}
