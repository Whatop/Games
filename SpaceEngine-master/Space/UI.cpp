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
	m_Text->Init(65, true, false, L"����");
	m_Text->SetColor(255, 255, 255, 255);
	ObjMgr->AddObject(m_Curtain, "UI");
	textTime = 0;
	UpdateText = " *  ";
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
			m_Pos -= (71 * dt);
		}

		if (m_Pos <= -350 && a == false)
		{
			ztime += dt;
			if (ztime > 2)
				a = true;
		}

		if (a == true && c == false)
		{
			ObjMgr->AddObject(new Text_Bubbles(Vec2(2175, 1080)), "Chet");
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
		if (textTime > 0.1)
			UpdateText = " *   ��";
		if (textTime > 0.2)
			UpdateText = " *   �פ�";
		if (textTime > 0.3)
			UpdateText = " *   �׳�";
		if (textTime > 0.4)
			UpdateText = " *   �׳� ";
		if (textTime > 0.5)
			UpdateText = " *   �׳� ��";
		if (textTime > 0.6)
			UpdateText = " *   �׳� ��";
		if (textTime > 0.7)
			UpdateText = " *   �׳� ��";
		if (textTime > 0.8)
			UpdateText = " *   �׳� ����";
		if (textTime > 0.9)
			UpdateText = " *   �׳� ����";
		if (textTime > 1.0)
			UpdateText = " *   �׳� ������";
		if (textTime > 1.1)
			UpdateText = " *   �׳� �������� \n.";
		if (textTime > 1.2)
			UpdateText = " *   �׳� �������� \n      ��";
		if (textTime > 1.3)
			UpdateText = " *   �׳� �������� \n      ���";
		if (textTime > 1.4)
			UpdateText = " *   �׳� �������� \n      ��";
		if (textTime > 1.5)
			UpdateText = " *   �׳� �������� \n      ����";
		if (textTime > 1.6)
			UpdateText = " *   �׳� �������� \n      ���ڱ�.";

		m_Text->print(UpdateText, 630, 760);
	}
}

void UI::Render()
{
	m_Curtain->Render();
	if(d)
	Renderer::GetInst()->GetSprite()->End();

}
