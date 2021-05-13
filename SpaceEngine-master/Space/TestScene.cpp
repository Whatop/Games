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
	SoundMgr::Init();
	SceneDirector::GetInst()->SetScene(scene::testscene);
	ObjMgr->DeleteObject("UI");

	Game::GetInst()->ReleaseUI();
	Game::GetInst()->CreateUI();

	StopButton = Sprite::Create(L"Painting/Button/Start_1.png");
	StopButton->SetPosition(2100, 100);

	ResumeButton = Sprite::Create(L"Painting/Button/Stop_1.png");
	ResumeButton->SetPosition(2200, 100);

	TempButton = Sprite::Create(L"Painting/Button/Back_1.png");
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
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(TempButton)) {
		TempButton = Sprite::Create(L"Painting/Button/Back_2.png");
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

		TempButton = Sprite::Create(L"Painting/Button/Back_1.png");
		TempButton->SetPosition(2400, 100);
		if (Game::GetInst()->m_Puase == false) {
			TempButton->m_Visible = false;
		}
		else {
			TempButton->m_Visible = true;
		}
	}
	
	if (CollisionMgr::GetInst()->MouseWithBoxSize(DirButton[0])) {
		DirButton[0]->R = 120;
		DirButton[0]->G = 120;
		DirButton[0]->B = 120;
		if (INPUT->GetButtonDown()) {
			Game::GetInst()->Shape(true);
			INPUT->ButtonDown(false);
		}
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(DirButton[1])) {
		DirButton[1]->R = 120;
		DirButton[1]->G = 120;
		DirButton[1]->B = 120;
		if (INPUT->GetButtonDown()) {
			Game::GetInst()->Shape(false);
			INPUT->ButtonDown(false);
		}
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
		DirButton[2]->R = 120;
		DirButton[2]->G = 120;
		DirButton[2]->B = 120;
		if (INPUT->GetButtonDown()) {
			Game::GetInst()->Rota(true);
			INPUT->ButtonDown(false);
		}
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(DirButton[3])) {
		DirButton[3]->R = 120;
		DirButton[3]->G = 120;
		DirButton[3]->B = 120;
		if (INPUT->GetButtonDown()) {
			Game::GetInst()->Rota(false);
			INPUT->ButtonDown(false);
		}
	}
	else {
		DirButton[2]->R = 120;
		DirButton[2]->G = 120;
		DirButton[2]->B = 120;
		DirButton[3]->R = 120;
		DirButton[3]->G = 120;
		DirButton[3]->B = 120;
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
	else {
		DirButton[0]->m_Visible = false;
		DirButton[1]->m_Visible = false;
		DirButton[2]->m_Visible = false;
		DirButton[3]->m_Visible = false;
		Mouse->m_Visible = false;
	}
	if (INPUT->GetKey('0')==KeyState::DOWN) {
		if (!Mode) {
			Mode = true;
		}
		else {
			Mode = false;
		}
	}
	if (Mode) {
		if (Game::GetInst()->shape == 1) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), "while", "small", Game::GetInst()->Dir, 1000), "Bone");
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 2) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), "while", "middle", Game::GetInst()->Dir, 1000), "Bone");
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 3) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), "while", "big", Game::GetInst()->Dir, 1000), "Bone");
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 4) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), "while", "long", Game::GetInst()->Dir, 1000), "Bone");
				INPUT->ButtonDown(false);
			}
		}
		else if (Game::GetInst()->shape == 5) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Bones(INPUT->GetMousePos(), "while", "lie", Game::GetInst()->Dir, 1000), "Bone");
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
	m_TSBgm->Update(deltaTime, time);
}

void TestScene::Render()
{
	ResumeButton->Render();
	StopButton->Render();
	TempButton->Render();
	DirButton[0]->Render();
	DirButton[1]->Render();
	Mouse->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + "  " + std::to_string(INPUT->GetMousePos().y)
		+ "\n" + std::to_string(dt) + "  " + std::to_string(gt), 250, 900);
	m_Text->print(std::to_string(UI::GetInst()->m_Hp), 1600, 800);
	Renderer::GetInst()->GetSprite()->End();
	//m_Line->DrawLine(m_Vertex, 5);

}
