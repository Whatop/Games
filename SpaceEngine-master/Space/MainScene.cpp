#include "stdafx.h"
#include "MainScene.h"
#include "Player.h"
#include "sans.h"
#include "Dialog.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}
//Determination Mono
void MainScene::Init()
{
	m_BG = Sprite::Create(L"Painting/Map/Last_Corridor.png");
	m_BG->SetPosition(0,0);
	SceneDirector::GetInst()->SetScene(scene::mainscene);
	m_Pillar = Sprite::Create(L"Painting/Map/Last_Pillar.png",COLORKEY_PURPLE);//따로 기둥을 만들어서 움직이게
	m_Pillar->SetPosition(0, 0);

	//ObjMgr->AddObject(m_Conversation, "UI");

	ObjMgr->AddObject(new Player,"Player");
	ObjMgr->AddObject(new Dialog(Vec2(1300, 0)),"Dialog");
	ObjMgr->AddObject(new sans(Vec2(1400, 350)), "sans");


	m_Text = new TextMgr();
	m_Text->Init(32, true, false, L"Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);
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
	m_Pillar->Render();	

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x)+"  "+std::to_string(INPUT->GetMousePos().y)+"\n"+std::to_string(dt)+ "sans" +std::to_string(gt), 0, 0);
	Renderer::GetInst()->GetSprite()->End();
}
