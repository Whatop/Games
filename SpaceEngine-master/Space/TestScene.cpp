#include "stdafx.h"
#include "TestScene.h"
#include "GasterBlaster.h"
#include "Laser.h"
#include "Bones.h"
#include "Platform.h"
#include "UI.h"
#include "BonePlate.h"


TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::Init()
{
	SceneDirector::GetInst()->SetScene(scene::testscene);
	ObjMgr->DeleteObject("UI");

	Game::GetInst()->ReleaseUI();
	Game::GetInst()->CreateUI();

	StopButton = Sprite::Create(L"Painting/Button/Start_1.png");
	StopButton->SetPosition(2100, 100);

	ResumeButton = Sprite::Create(L"Painting/Button/Stop_1.png");
	ResumeButton->SetPosition(2200, 100);

	TempButton = Sprite::Create(L"Painting/Button/Option_1.png");
	TempButton->SetPosition(2400, 100);
	TempButton->m_Visible = false;

	DirButton[0] = Sprite::Create(L"Painting/Button/Left.png");
	DirButton[0]->SetPosition(3300, 100);

	DirButton[1] = Sprite::Create(L"Painting/Button/Right.png");
	DirButton[1]->SetPosition(3700, 100);

	DirButton[2] = Sprite::Create(L"Painting/Button/Left.png");
	DirButton[2]->SetPosition(3300, 300);

	DirButton[3] = Sprite::Create(L"Painting/Button/Right.png");
	DirButton[3]->SetPosition(3700, 300);


	DirButton[0]->m_Visible = false;
	DirButton[1]->m_Visible = false;

	DirButton[2]->m_Visible = false;
	DirButton[3]->m_Visible = false;

	Mouse = Sprite::Create(L"Painting/Button/Right.png");
	Mouse->SetPosition(3400, 100);
	Mouse->m_Visible = false;

	rtime = 0;
	m_Text = new TextMgr();
	m_Text->Init(32, true, false, L"Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);

	m_TSBgm = new SoundMgr("Sound/MEGALOVANIA.mp3", true);
	m_TSBgm->play();
	m_TSBgm->volumeDown();
	m_TSBgm->volumeDown();
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

void TestScene::Button()
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(StopButton)) {
		StopButton = Sprite::Create(L"Painting/Button/Stop_2.png");
		StopButton->SetPosition(2000, 100);
		if (INPUT->GetButtonDown()) {
			Game::GetInst()->m_Puase = true;
			m_TSBgm->pause();
			INPUT->ButtonDown(false);
		}
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(ResumeButton)) {
		ResumeButton = Sprite::Create(L"Painting/Button/Start_2.png");
		ResumeButton->SetPosition(2200, 100);
		if (INPUT->GetButtonDown()) {
			Game::GetInst()->m_Puase = false;
			m_TSBgm->resume();
			INPUT->ButtonDown(false);
		}
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(TempButton)&& TempButton->m_Visible) {
		TempButton = Sprite::Create(L"Painting/Button/Option_2.png");
		TempButton->SetPosition(2400, 100);
		if (INPUT->GetButtonDown()) {
				if (!m_Puase) {
					m_Puase = true;
				}
				else {
					m_Puase = false;
				}
			INPUT->ButtonDown(false);
		}
	}
	else {
		StopButton = Sprite::Create(L"Painting/Button/Stop_1.png");
		StopButton->SetPosition(2000, 100);

		ResumeButton = Sprite::Create(L"Painting/Button/Start_1.png");
		ResumeButton->SetPosition(2200, 100);

		TempButton = Sprite::Create(L"Painting/Button/Option_1.png");
		TempButton->SetPosition(2400, 100);
		if (Game::GetInst()->m_Puase == false) {
			TempButton->m_Visible = false;
		}
		else {
			TempButton->m_Visible = true;
		}
	}
	if (TempButton->m_Visible) {
		if (CollisionMgr::GetInst()->MouseWithBoxSize(DirButton[0])) {
			DirButton[0]->R = 255;
			DirButton[0]->G = 255;
			DirButton[0]->B = 255;
			if (INPUT->GetButtonDown()) {
				Game::GetInst()->Shape(true);
				INPUT->ButtonDown(false);
			}
			Mode = false;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(DirButton[1])) {
			DirButton[1]->R = 255;
			DirButton[1]->G = 255;
			DirButton[1]->B = 255;
			if (INPUT->GetButtonDown()) {
				Game::GetInst()->Shape(false);
				INPUT->ButtonDown(false);
			}
			Mode = false;
		}
		else {
			DirButton[0]->R = 120;
			DirButton[0]->G = 120;
			DirButton[0]->B = 120;
			DirButton[1]->R = 120;
			DirButton[1]->G = 120;
			DirButton[1]->B = 120;
		}
		if (CollisionMgr::GetInst()->MouseWithBoxSize(DirButton[2])) {
			DirButton[2]->R = 255;
			DirButton[2]->G = 255;
			DirButton[2]->B = 255;
			if (INPUT->GetButtonDown()) {
				Game::GetInst()->Rota(true);
				INPUT->ButtonDown(false);
			}
			Mode = false;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(DirButton[3])) {
			DirButton[3]->R = 255;
			DirButton[3]->G = 255;
			DirButton[3]->B = 255;
			if (INPUT->GetButtonDown()) {
				Game::GetInst()->Rota(false);
				INPUT->ButtonDown(false);
			}
			Mode = false;
		}
		else {
			DirButton[2]->R = 120;
			DirButton[2]->G = 120;
			DirButton[2]->B = 120;
			DirButton[3]->R = 120;
			DirButton[3]->G = 120;
			DirButton[3]->B = 120;
		}
	}
	if (Game::GetInst()->m_Puase == true) {
		if (m_Puase == true) {
			DirButton[0]->m_Visible = true;
			DirButton[1]->m_Visible = true;
			DirButton[2]->m_Visible = true;
			DirButton[3]->m_Visible = true;
			Mouse->m_Visible = true;
			Mouse = UI::GetInst()->m_Mouse;
			Mouse->SetScale(0.5f, 0.5f);
			Mouse->SetPosition(3500, 100);
		}
		else {
			DirButton[0]->m_Visible = false;
			DirButton[1]->m_Visible = false;
			DirButton[2]->m_Visible = false;
			DirButton[3]->m_Visible = false;
			Mouse->m_Visible = false;
		}
	}
	if (Game::GetInst()->m_Puase == false || !m_Puase) {
		m_Name = "";
		m_Puase = false;
		DirButton[0]->m_Visible = false;
		DirButton[1]->m_Visible = false;
		DirButton[2]->m_Visible = false;
		DirButton[3]->m_Visible = false;
		Mouse->m_Visible = false;
	}
	if (INPUT->GetKey('M') == KeyState::DOWN) {
		if (!Mode) {
			Mode = true;
		}
		else {
			Mode = false;
		}
	}
	if (INPUT->GetKey('C') == KeyState::DOWN) {
		if (!Color) {
			Color = true;

		}
		else {
			Color = false;
		}
	}

	if (Mode) {
		if (Game::GetInst()->shape == 1) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), m_Color, "small", Game::GetInst()->Dir, 1000), m_TempTag);
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 2) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), m_Color, "middle", Game::GetInst()->Dir, 1000), m_TempTag);
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 3) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), m_Color, "big", Game::GetInst()->Dir, 1000), m_TempTag);
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 4) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), m_Color, "long", Game::GetInst()->Dir, 1000), m_TempTag);
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 5) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), m_Color, "lie", Game::GetInst()->Dir, 1000), m_TempTag);
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 6) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Platform(INPUT->GetMousePos(), Game::GetInst()->Dir), "Platform");
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 7) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new GasterBlaster(INPUT->GetMousePos(), Game::GetInst()->Dir), "GasterBlaster");
				INPUT->ButtonDown(false);
			}
		}
	}
}

void TestScene::Update(float deltaTime, float time) // 화면 밖에서 내려오기
{
	Button();
	if (Game::GetInst()->Dir == _left) {
		m_Name = "왼쪽";
	}
	else if (Game::GetInst()->Dir == _right) {
		m_Name = "오른쪽";
	}
	else if (Game::GetInst()->Dir == _up) {
		m_Name = "위";
	}
	else if (Game::GetInst()->Dir == _down) {
		m_Name = "아래";
	}

	if (Mode) {
		m_Mode = "그리기 모드 ON";
	}
	else{
		m_Mode = "그리기 모드 OFF";
	}

	if (Color) {
		m_Color = "blue";
		m_TempTag = "BlueBone";
		Mouse->R = 0;
		Mouse->G = 168;
		Mouse->B = 255;
	}
	else {
		 m_Color = "while";
		m_TempTag = "Bone";
		Mouse->R = 255;
		Mouse->G = 255;
		Mouse->B = 255;
	}
	Game::GetInst()->Color = Color;
	m_TSBgm->Update(deltaTime, time);
}

void TestScene::Render()
{
	ResumeButton->Render();
	StopButton->Render();
	TempButton->Render();
	DirButton[0]->Render();
	DirButton[1]->Render();
	DirButton[2]->Render();
	DirButton[3]->Render();
	Mouse->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	if (m_Puase == true) {
		m_Text->print(m_Name, 1675, 280);
	}

	m_Text->print(m_Mode, 1675, 480);

	m_Text->print("뼈 색깔 : "+m_Color, 1675, 680);

	m_Text->print(std::to_string(UI::GetInst()->m_Hp), 1650, 900);

	Renderer::GetInst()->GetSprite()->End();
	//m_Line->DrawLine(m_Vertex, 5);

}
