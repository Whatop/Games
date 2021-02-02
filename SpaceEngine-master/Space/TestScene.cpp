#include "stdafx.h"
#include "TestScene.h"
#include "GasterBlaster.h"
#include "Laser.h"
#include "Bones.h"
#include "Platform.h"


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
	if (rtime >= 2) {// direction < Count  조건 추가 

		if (direction % 2 != 0) {
			randomx = 300;
		}
		else {
			randomx = 1600;
		}

		ObjMgr->AddObject(new GasterBlaster(Vec2(randomx, -400), direction), "GasterBlaster");
		direction++;
		rtime = 0;
	}
	if (btime >= 1) {// direction < Count  조건 추가 
		//(Vec2 Pos,std::string color, std::string size, int
		ObjMgr->AddObject(new Bones(Vec2(-100,100),"blue","small", _right), "BlueBone");
		ObjMgr->AddObject(new Bones(Vec2(-100,300),"blue","middle",_right), "BlueBone");
		ObjMgr->AddObject(new Bones(Vec2(-100,500),"blue","big",_right), "BlueBone");
		ObjMgr->AddObject(new Bones(Vec2(-100,700),"blue","long", _right), "BlueBone");
		ObjMgr->AddObject(new Bones(Vec2(1920/2,-100),"blue","lie", _down), "BlueBone");

		ObjMgr->AddObject(new Bones(Vec2(2020, 100), "blue", "small", _left), "BlueBone");
		ObjMgr->AddObject(new Bones(Vec2(2020, 300), "blue", "middle", _left), "BlueBone");
		ObjMgr->AddObject(new Bones(Vec2(2020, 500), "blue", "big", _left), "BlueBone");
		ObjMgr->AddObject(new Bones(Vec2(2020, 700), "blue", "long", _left), "BlueBone");
		ObjMgr->AddObject(new Bones(Vec2(1920 / 2, 1180), "blue", "lie", _up), "BlueBone");

		ObjMgr->AddObject(new Platform(Vec2(2020 / 2, 1180), _up), "Platform");
		direction++;
		btime = 0;
	}
		//m_Player->SetVertex();
		m_TSBgm->Update(deltaTime, time);
}

void TestScene::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + "  " + std::to_string(INPUT->GetMousePos().y)
		+ "\n" + std::to_string(dt) + "  " + std::to_string(gt), 500, 0);
	Renderer::GetInst()->GetSprite()->End();

	//m_Line->DrawLine(m_Vertex, 5);

}
