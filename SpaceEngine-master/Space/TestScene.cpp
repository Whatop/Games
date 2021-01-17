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

	m_TSBgm = new SoundMgr("Sound/MEGALOVANIA.mp3", true);
	m_TSBgm->play();
	m_TSBgm->volumeDown();
	//Count = 10 보통 마지막은 안쏨
	//Count = 12 빠름 마지막은 안씀
	Count = 10;
	direction = 1;
	one = false;
}
	
void TestScene::Release()
{
	m_TSBgm->Release();
}

void TestScene::Update(float deltaTime, float time) // 화면 밖에서 내려오기
{
	rtime += dt;
	//빠르게 11번 보통 9번 
	if (rtime >= 1 ) {// direction < Count  조건 추가 

			if (direction % 2 != 0) {
				randomx = 300;
				std::cout << ":  왼쪽 " << std::endl;
				direction++;
			}
			else {
				randomx = 1600;
				std::cout << ":  오른쪽 " << std::endl;
				direction++;
			}
				
			ObjMgr->AddObject(new GasterBlaster(Vec2(randomx, -400), direction), "GasterBlaster");
		rtime = 0;
	}
	
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
