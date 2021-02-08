#include "stdafx.h"
#include "TestScene.h"
#include "GasterBlaster.h"
#include "Laser.h"
#include "Bones.h"
#include "Platform.h"
#include "UI.h"


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
	m_Ground = Sprite::Create(L"Painting/Map/Ground.png");
	m_Ground->SetPosition(2800, 1080);
	m_Ground->SetTag("Ground");
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
	test = 1;
	rtime = 0;
	btime = 0;
	one = false;
	std::cout << "----------테스트룸입장----------" << std::endl;
}

void TestScene::Release()
{
	m_TSBgm->Release();
}

void TestScene::Update(float deltaTime, float time) // 화면 밖에서 내려오기
{
	rtime += dt;
	btime += dt;
	//빠르게 11번 보통 9번
	if (!brandom) {
		random = rand() % 2 + 1;
		brandom = true;
	}
	
	if (brandom == 1) {
		if (rtime >= 1.f && direction < Count) {//   조건 추가 

			if (direction % 2 != 0) {
				randomx = 2080;
			}
			else {
				randomx = 3480;
			}

			ObjMgr->AddObject(new GasterBlaster(Vec2(randomx, -400), direction), "GasterBlaster");
			ObjMgr->AddObject(new GasterBlaster(Vec2(randomx, -400), direction), "GasterBlaster");
			direction++;
			rtime = 0;
			std::cout << "방향 :"<<direction << std::endl;
			std::cout << "랜덤 :"<<random << std::endl;
		}
		else if(direction > Count)
		{
			brandom = false;
			direction = 0;
		}
	}
	else if (random == 2) {
		if (btime >= 1 && direction < Count) {// direction < Count  조건 추가 
		//	(Vec2 Pos,std::string color, std::string size, int
			ObjMgr->AddObject(new Bones(Vec2(2080,100),"while","small", _right), "Bone");
			ObjMgr->AddObject(new Bones(Vec2(2080,300),"while","middle",_right), "Bone");
			ObjMgr->AddObject(new Bones(Vec2(2080,500),"while","big",_right), "Bone");
			ObjMgr->AddObject(new Bones(Vec2(2080,700),"while","long", _right), "Bone");
			ObjMgr->AddObject(new Bones(Vec2(2920/2,-100),"while","lie", _down), "Bone");

			ObjMgr->AddObject(new Bones(Vec2(3480, 100), "while", "small", _left), "Bone");
			ObjMgr->AddObject(new Bones(Vec2(3480, 300), "while", "middle", _left), "Bone");
			ObjMgr->AddObject(new Bones(Vec2(3480, 500), "while", "big", _left), "Bone");
			ObjMgr->AddObject(new Bones(Vec2(3480, 700), "while", "long", _left), "Bone");
			ObjMgr->AddObject(new Bones(Vec2(2920 / 2, 1180), "while", "lie", _up), "Bone");

			ObjMgr->AddObject(new Platform(Vec2(1980, 1180), _right), "Platform");
			direction++;
			btime = 0;
		}
		else if (direction > Count)
		{
			brandom = false;
			direction = 0;
		}
	}
	
		//m_Player->SetVertex();
		m_TSBgm->Update(deltaTime, time);
}

void TestScene::Render()
{
	m_Ground->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + "  " + std::to_string(INPUT->GetMousePos().y)
		+ "\n" + std::to_string(dt) + "  " + std::to_string(gt), 500, 0);
	m_Text->print(std::to_string(UI::GetInst()->m_Hp), 1600, 800);
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	//m_Line->DrawLine(m_Vertex, 5);

}
