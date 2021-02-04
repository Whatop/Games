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
	m_Text->Init(65, true, false, L"굴림");
	m_Text->SetColor(255, 255, 255, 255);
	m_Curtain->SetPosition(1920/2, 700/2);
	ObjMgr->AddObject(m_Curtain, "UI");
	textTime = 0;
	UpdateText = " *  ";
}

void UI::Release()
{
}

void UI::Update()
{
	std::cout << m_Pos << std::endl;
	for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
			PlayerPos = iter->m_Position;
	}
	//m_Curtain->m_Position = Vec2(PlayerPos.x, PlayerPos.y);
	if (SceneDirector::GetInst()->m_scene == scene::dialogscene)
	{
		ptime += dt;
		if (ptime > 2 && ptime < 6) {
			m_Pos -= (71 * dt);
		}

		if (m_Pos <= -280 && a == false)
		{
			ztime += dt;
			if (ztime > 2)
				a = true;
		}

		if (a == true && c == false)
		{
			ObjMgr->AddObject(new Text_Bubbles(Vec2(2750, 1265)), "Chet");
			a = false;
			b = true;
			c = true;
			d = true;
		}

	}
	if (SceneDirector::GetInst()->m_scene == scene::mainscene ||
		SceneDirector::GetInst()->m_scene == scene::dialogscene)
		m_Curtain->A = 255;
	else
		m_Curtain->A = 0;

	if (d) {
		Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
		textTime += dt;
		if (textTime > 0.25f)
			UpdateText = " *   그";
		if (textTime > 0.3)
			UpdateText = " *   그냥 ";
		if (textTime > 0.4)
			UpdateText = " *   그냥 본";
		if (textTime > 0.5)
			UpdateText = " *   그냥 본론";
		if (textTime > 0.6)
			UpdateText = " *   그냥 본론으";
		if (textTime > 0.7)
			UpdateText = " *   그냥 본론으로 \n.";
		if (textTime > 0.9)
			UpdateText = " *   그냥 본론으로 \n      들";
		if (textTime > 1.2)
			UpdateText = " *   그냥 본론으로 \n      들어";
		if (textTime > 1.4)
			UpdateText = " *   그냥 본론으로 \n      들어가";
		if (textTime > 1.5)
			UpdateText = " *   그냥 본론으로 \n      들어가자";
		if (textTime > 1.6)
			UpdateText = " *   그냥 본론으로 \n      들어가자구";
		if (textTime > 1.7)
			UpdateText = " *   그냥 본론으로 \n      들어가자구.";
		
		m_Text->print(UpdateText, 600, 780);
	}
}

void UI::Render()
{
	m_Curtain->Render();
	if(d)
	Renderer::GetInst()->GetSprite()->End();

}
