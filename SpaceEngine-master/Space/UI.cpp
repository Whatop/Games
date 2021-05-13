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
	m_UI = Sprite::Create(L"Painting/Map/UI.png",COLORKEY_BLACK);
	m_Curtain = Sprite::Create(L"Painting/Map/Layer.png",COLORKEY_WHITE);
	m_HpBar = Sprite::Create(L"Painting/UI/MaxHp.png");
	m_HpBar->SetPosition(1500, 950);
	m_SpHp = Sprite::Create(L"Painting/UI/Hp.png");
	m_SpHp->SetPosition(1500, 950);
	//m_Poison = Sprite::Create(L"Painting/UI/Poison.png");
	ztime = 0;
	ptime = 0;
	m_Pos = 0;
	a = false;
	b = false;
	c = false;
	m_Text = new TextMgr();
	m_Text->Init(65, true, false, L"굴림");
	m_Text->SetColor(255, 255, 255, 255);
	m_Curtain->SetPosition(1920/2, 1080/2);
	m_UI->SetPosition(1920/2, 700/2);
	
	if (SceneDirector::GetInst()->GetScene() == scene::mainscene) {
		//ObjMgr->AddObject(m_UI, "UI");
		ObjMgr->AddObject(m_Curtain, "UI");
	}
	else if (SceneDirector::GetInst()->GetScene() == scene::testscene) {
		ObjMgr->AddObject(m_SpHp, "UI");
		ObjMgr->AddObject(m_HpBar, "UI");
	}
	//ObjMgr->AddObject(m_Poison, "UI");
	textTime = 0;
	UpdateText = " *  ";
}

void UI::Release()
{
}

void UI::Update()
{
	SetCursor(NULL);

		if (Game::GetInst()->m_MouseShape == MouseShape::BONESMALL) {
			m_Mouse = Sprite::Create(L"Painting/sans/Attack/Bone_small.png", COLORKEY_BLACK);
		}
		if (Game::GetInst()->m_MouseShape == MouseShape::BONE) {
			m_Mouse = Sprite::Create(L"Painting/sans/Attack/Bone.png", COLORKEY_BLACK);
		}
		if (Game::GetInst()->m_MouseShape == MouseShape::BONEBIG) {
			m_Mouse = Sprite::Create(L"Painting/sans/Attack/Bone_big.png", COLORKEY_BLACK);
		}
		if (Game::GetInst()->m_MouseShape == MouseShape::BONELONG) {
			m_Mouse = Sprite::Create(L"Painting/sans/Attack/Bone_long.png", COLORKEY_BLACK);
		}
		if (Game::GetInst()->m_MouseShape == MouseShape::BONELIE) {
			m_Mouse = Sprite::Create(L"Painting/sans/Attack/Bone_lie.png", COLORKEY_BLACK);
		}
		if (Game::GetInst()->m_MouseShape == MouseShape::GASTERBALSTER) {
			m_Mouse = Sprite::Create(L"Painting/sans/Attack/GasterBlaster/gasterblaster1.png", COLORKEY_GASTER);
		}
		if (Game::GetInst()->m_MouseShape == MouseShape::PLATFORM) {
			m_Mouse = Sprite::Create(L"Painting/platfrom/platfrom.png", COLORKEY_BLACK);
		}

		m_Mouse->SetPosition(INPUT->GetMousePos());
		if (SceneDirector::GetInst()->m_scene != scene::testscene) {
			m_Mouse->m_Visible = false;
		}
		else {
			m_Mouse->m_Visible = true;
		}
		if (Game::GetInst()->Color) {
			m_Mouse->R = 0;
			m_Mouse->G = 168;
			m_Mouse->B = 255;
		}
		else {
			m_Mouse->R = 255;
			m_Mouse->G = 255;
			m_Mouse->B = 255;
		}
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
		SceneDirector::GetInst()->m_scene == scene::dialogscene) {
		m_Curtain->A = 255;
		m_UI->A = 0;
	}
	else {
		m_Curtain->A = 0;
		m_UI->A = 255;
	}
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
	m_Mouse->Render();
		if (d)
			Renderer::GetInst()->GetSprite()->End();
		m_HpGage = m_HpBar->m_Size.x / 92;
		int Hp = 92 - m_Hp;
		if (m_Hp >= 0)
		{
			SetRect(&m_HpBar->m_Collision, m_HpBar->m_Position.x - m_HpBar->m_Size.x / 2, m_HpBar->m_Position.y - m_HpBar->m_Size.y / 2,
				m_HpBar->m_Position.x + m_HpBar->m_Size.x / 2, m_HpBar->m_Position.y + m_HpBar->m_Size.y / 2);

			m_HpBar->m_Rect.right = m_HpBar->m_Size.x - (Hp * m_HpGage);
		}
}
