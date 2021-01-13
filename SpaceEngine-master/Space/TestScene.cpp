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
	SoundMgr::Init();
	SceneDirector::GetInst()->SetScene(scene::testscene);
	rtime = 0; 
	m_Text = new TextMgr();
	m_Text->Init(32, true, false, L"Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);

	//m_Line = new LineMgr();
	//m_Line->Init(4, true);
	//m_Line->SetColor(D3DXCOLOR(255, 255, 255, 255));

	m_TSBgm = new SoundMgr("Sound/TestRoom.mp3", false);
	m_TSBgm->play();
}

void TestScene::Release()
{
	m_TSBgm->Release();
}

void TestScene::Update(float deltaTime, float time)
{
	//m_bgm->Update();
	//rtime += dt;
	//if (rtime >= 0.8f) {
	//	int random = rand() % 5;
	//	if (random==1){//���� ����
	//		randomx = rand() % -320 + -200;
	//		randomy = rand() % 1380 + -200;
	//		std::cout << random << ":  ���� " << std::endl;
	//	}
	//	else if(random == 2){//���� ������
	//		randomx = rand() % 320 + 2120;
	//		randomy = rand() % 1380 + -200;
	//		std::cout << random << ":  ������ " << std::endl;
	//	}
	//	else if (random == 3) {//���� ��
	//		randomx = rand() % 2220 + -100;
	//		randomy = rand() % -320 + -200;
	//		std::cout << random << ":  �� " << std::endl;
	//	}
	//	else if (random == 4) {//���� �Ʒ�
	//		randomx = rand() % 2220 + -100;
	//		randomy = rand() % 320 + 1180;
	//		std::cout << random << ":  �Ʒ� " << std::endl;
	//	}
	//	ObjMgr->AddObject(new GasterBlaster(Vec2(randomx, randomy)), "GasterBlaster");
	//	rtime = 0;
	//}
	//m_Player->SetVertex();
	m_TSBgm->Update(deltaTime, time);
}

void TestScene::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + "  " + std::to_string(INPUT->GetMousePos().y) + "\n" + std::to_string(dt) + "  " + std::to_string(gt), 500, 0);
	Renderer::GetInst()->GetSprite()->End();

	//m_Line->DrawLine(m_Vertex, 5);

}
