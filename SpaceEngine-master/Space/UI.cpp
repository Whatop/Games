#include "stdafx.h"
#include "UI.h"
#include "Pillar.h"
#include "Text_Bubbles.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Init()
{
	m_Curtain = Sprite::Create(L"Painting/Map/Layer.png",COLORKEY_WHITE);
	ztime = 0;
	ptime = 0;
	m_Pos = 0;
	a = false;
	b = false;
	c = false;
	m_Text = new TextMgr();
	m_Text->Init(65, true, true, L"굴림");
	m_Text->SetColor(255, 255, 255, 255);
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
	//m_Curtain->m_Position = Vec2(PlayerPos.x, PlayerPos.y);
	if (SceneDirector::GetInst()->m_scene == scene::dialogscene)
	{
		ptime += dt;
		if (ptime > 2 && ptime < 7) {
			m_Pos -= (70 * dt);
		}
		
	if (m_Pos <= -350 && a == false)
	{
		ztime += dt;
		if (ztime > 2)
			a = true;
	}
	if (a == true && c==false)
	{
		ObjMgr->AddObject(new Text_Bubbles(Vec2(2175, 1080)), "Chet");
		m_Curtain->m_Tag = "UI";
		a = false;
		b = true;
		c = true;
	}
	}
}

void UI::Render()
{
	m_Curtain->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	if (b == true) {
		m_Text->print(" *  그냥 본론으로 \n     들어가자구.", 630, 760);
	}
	Renderer::GetInst()->GetSprite()->End();
}
