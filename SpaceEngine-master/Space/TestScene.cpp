#include "stdafx.h"
#include "TestScene.h"
#include "GasterBlaster.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::Init()
{
	SceneDirector::GetInst()->SetScene(scene::testscene);
	rtime = 0; 
	m_Text = new TextMgr();
	m_Text->Init(32, true, false, L"Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);

}

void TestScene::Release()
{
}

void TestScene::Update(float deltaTime, float time)
{
	rtime += dt;
	if (rtime >= 0.8f) {
		int random = rand() % 5;
		if (random==1){//범위 왼쪽
			randomx = rand() % -320 + -100;
			randomy = rand() % 1280 + -100;
			std::cout << random << ":  왼쪽 " << std::endl;
		}
		else if(random == 2){//범위 오른쪽
			randomx = rand() % 320 + 2120;
			randomy = rand() % 1280 + -100;
			std::cout << random << ":  오른쪽 " << std::endl;
		}
		else if (random == 3) {//범위 위
			randomx = rand() % 2220 + -100;
			randomy = rand() % -320 + -100;
			std::cout << random << ":  위 " << std::endl;
		}
		else if (random == 4) {//범위 아래
			randomx = rand() % 2220 + -100;
			randomy = rand() % 320 + 1180;
			std::cout << random << ":  아래 " << std::endl;
		}
		ObjMgr->AddObject(new GasterBlaster(Vec2(randomx, randomy)), "GasterBlaster");
		rtime = 0;
	}
	
}

void TestScene::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + "  " + std::to_string(INPUT->GetMousePos().y) + "\n" + std::to_string(dt) + "  " + std::to_string(gt), 500, 0);
	Renderer::GetInst()->GetSprite()->End();

}
