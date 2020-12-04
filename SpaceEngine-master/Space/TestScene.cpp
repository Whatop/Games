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
	if (rtime >= 5) {
		int randomx = rand() % 1920;//범위 밖으로
		int randomy = rand() % 1080;
		std::cout << " 생성완료 " << std::endl;
		ObjMgr->AddObject(new GasterBlaster(INPUT->GetMousePos()), "GasterBlaster");
		rtime = 0;
	}
	std::cout << "테스트룸 리스폰 쿨타임 : "<<rtime << std::endl;
}

void TestScene::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + "  " + std::to_string(INPUT->GetMousePos().y) + "\n" + std::to_string(dt) + "  " + std::to_string(gt), 500, 0);
	Renderer::GetInst()->GetSprite()->End();

}
