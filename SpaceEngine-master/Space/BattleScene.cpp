#include "stdafx.h"
#include "BattleScene.h"
#include "Player.h"

BattleScene::BattleScene()
{
}

BattleScene::~BattleScene()
{
}

void BattleScene::Init()
{
	for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
		{
			PlayerPos = iter->m_Position;
		}
	}
	SceneDirector::GetInst()->SetScene(scene::battlescene);
	ObjMgr->DeleteObject("sans");
	ObjMgr->DeleteObject("Dialog");
	m_BG = Sprite::Create(L"Painting/Map/BattleBG.png", COLORKEY_BALCK);
	m_BG->SetPosition(0,0);
	//ObjMgr->AddObject(m_BG, "Frame");
	//m_StartLine = new LineMgr();
	//m_StartLine->Init(10, true);
	//m_StartLine->SetColor(D3DXCOLOR(255, 255, 23, 255));
	if (SceneDirector::GetInst()->m_scene == scene::start) {

	}
}

void BattleScene::Release()
{
}

void BattleScene::Update(float deltaTime, float time)
{
	//m_BG->SetVertex();
}

void BattleScene::Render()
{
	//m_StartLine->DrawLine(m_BG->m_Vertex, 3);
	m_BG->Render();
}
