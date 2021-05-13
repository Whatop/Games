#include "stdafx.h"
#include "MainScene.h"
#include "Player.h"
#include "sans.h"
#include "Dialog.h"
#include "Pillar.h"
#include "Chest.h"
#include "Save.h"
#include "Solids.h"
MainScene::MainScene()
{		
}

MainScene::~MainScene()
{
}
//Determination Mono
void MainScene::Init()
{
	SceneDirector::GetInst()->SetScene(scene::mainscene);
	Game::GetInst()->ReleaseUI();
	Game::GetInst()->CreateUI();
	m_BG = Sprite::Create(L"Painting/Map/Last_Corridor.png");
	m_BG->SetPosition(4200/2, 720/2);

	ObjMgr->AddObject(new Chest(Vec2(245, 605)), "Chest");
	ObjMgr->AddObject(new Player, "Player");
	ObjMgr->AddObject(new Save(Vec2(70, 605)), "Save");
	ObjMgr->AddObject(new sans(Vec2(0, -200)), "sans");
	ObjMgr->AddObject(new Dialog(Vec2(2530, 450)), "Dialog");
	//ObjMgr->AddObject(new Solids(L"Painting/Solids/middle.png", Vec2(0, 344)), "Solids");
//	ObjMgr->AddObject(new Solids(L"Painting/Solids/middle.png", Vec2(0, 702/2)), "Solids");

	m_Text = new TextMgr();
	m_Text->Init(32, true, false, L"Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);

	//486 343+72
	/*for (int i = 0; i < 4; i++)
	{
		ObjMgr->AddObject(new Solids(L"Painting/Solids/Small.png", Vec2(-69/2, 420 + (i * 70)+43)), "Solids");
		ObjMgr->AddObject(new Solids(L"Painting/Solids/Small.png", Vec2(4200+69/2, 420 + (i * 70)+43)), "Solids");
	}
	for (int i = 0; i < 15; i++)
	{
		ObjMgr->AddObject(new Solids(L"Painting/Solids/long.png", Vec2(141 + (i * 282), 710+75/2)), "Solids");
	}
	for (int i = 0; i < 15; i++)
	{
		ObjMgr->AddObject(new Solids(L"Painting/Solids/long.png", Vec2(141 + (i * 282), 355+ 75 / 2)), "Solids");
	}*/
	for (int d = 0; d < 8; d++) //8¹ø
	{
		int a = 490+(d*420);
		for (int i = 0; i < 3; i++)
		{
			ObjMgr->AddObject(new Solids(L"Painting/Solids/Small.png", Vec2((a + (i * 69)+37), 343 + 122)), "Solids");
		} 
	}
	ObjMgr->AddObject(new Pillar(Vec2(2300+1100, 720/2)), "Pillar");
	Game::GetInst()->CreateUI();
}
void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
}

void MainScene::Render()
{
	m_BG->Render();
}
