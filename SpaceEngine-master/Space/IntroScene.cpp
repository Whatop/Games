#include"stdafx.h"
#include "IntroScene.h"
#include"MainScene.h"

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{

}


void IntroScene::Init()
{
	SoundMgr::GetInst()->Init();
	m_IntroCut1 = Sprite::Create(L"Painting/Intro/1.png");
	m_IntroCut1->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut2 = Sprite::Create(L"Painting/Intro/2.png");
	m_IntroCut2->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut3 = Sprite::Create(L"Painting/Intro/3.png");
	m_IntroCut3->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut4 = Sprite::Create(L"Painting/Intro/4.png");
	m_IntroCut4->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut5 = Sprite::Create(L"Painting/Intro/5.png");
	m_IntroCut5->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut6 = Sprite::Create(L"Painting/Intro/6.png");
	m_IntroCut6->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut7 = Sprite::Create(L"Painting/Intro/7.png");
	m_IntroCut7->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut8 = Sprite::Create(L"Painting/Intro/8.png");
	m_IntroCut8->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut9 = Sprite::Create(L"Painting/Intro/9.png");
	m_IntroCut9->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut10 = Sprite::Create(L"Painting/Intro/10.png");
	m_IntroCut10->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut11 = Sprite::Create(L"Painting/Intro/11.png");
	m_IntroCut11->SetPosition(1920 / 2, 1080 / 2);
	m_IntroCut11->m_Position.y = -540/2+100;

	m_IntroCut12 = Sprite::Create(L"Painting/Intro/12.png");
	m_IntroCut12->SetPosition(1920 / 2, 1080 / 2);

	m_IntroFrame = Sprite::Create(L"Painting/Intro/0.png");
	m_IntroFrame->SetPosition(1920 / 2, 1080 / 2);


	m_IntroCut12->A = 0;
	m_IntroCut11->A = 0;
	m_IntroCut10->A = 0;
	m_IntroCut9->A = 0;
	m_IntroCut8->A = 0;
	m_IntroCut7->A = 0;
	m_IntroCut6->A = 0;
	m_IntroCut5->A = 0;
	m_IntroCut4->A = 0;
	m_IntroCut3->A = 0;
	m_IntroCut2->A = 0;

	m_Count = 0;
	m_Cut = 1;
	start = false;
	IntroSound = new SoundMgr("Sound/Intro.mp3", false);
	//IntroSound->volumeUp();
	//IntroSound->volumeUp();

	BGIntroSound = new SoundMgr("Sound/BGIntro.mp3", false);

	TextSound = new SoundMgr("Sound/Chet.mp3", false);
	TextSound->volumeDown();
	TextSound->volumeDown();

	//BGIntroSound->volumeUp();
	BGIntroSound->volumeDown();
	BGIntroSound->volumeDown();
	BGIntroSound->play(); 

	IntroText = new TextMgr();
	IntroText->Init(82, false, false, "DungGeunMo");
	IntroText->SetColor(255, 255, 255, 255);

	BGIntroSound->play();
	TextSound->play();
	textdelay = 0.f;
	istextsound = false;
	textCount = 0;
}

void IntroScene::Release()
{
}

void IntroScene::Update(float deltaTime, float time) //백그라운드클래스 써서 간략화하기
{
	IntroChange();

	if (m_Cut < 8) {
		if (!istextsound) {
			fin.open("Text/Intro/" + std::to_string(m_Cut) + ".txt");
			if (fin.is_open()) {
				fin.seekg(0, std::ios::end);
				int size = fin.tellg();
				text.resize(size);
				fin.seekg(0, std::ios::beg);
				fin.read(&text[0], size);
				std::cout << text << std::endl;
				fin.close();
					istextsound = true;
			}
			else {
				std::cout << "파일을 찾을 수 없습니다!" << std::endl;
			}
		}
		else {
			if (!text.empty()) {
				textdelay += 2 * dt;
				if (textdelay > 0.15f && text.length() != Wtext.length()) {
					Wtext += text[textCount];
					textCount++;
					textdelay = 0;
				}
				if(text.length() == Wtext.length()){
					TextSound->stop();
				}
			}
			TextSound->Update(deltaTime, time);
		}
	}
	if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN)
	{
		m_IntroCut12->A = 255;
		m_IntroCut11->A = 0;
		m_IntroCut10->A = 0;
		m_IntroCut9->A = 0;
		m_IntroCut8->A = 0;
		m_IntroCut7->A = 0;
		m_IntroCut6->A = 0;
		m_IntroCut5->A = 0;
		m_IntroCut4->A = 0;
		m_IntroCut3->A = 0;
		m_IntroCut2->A = 0;
		m_IntroCut1->A = 0;
		m_Cut = 0;
		start = true;
	}
	if (start == true) {
		m_Start += dt;
		if (m_Start > 2.f) {
			BGIntroSound->Release();
			IntroSound->Release();
			SceneDirector::GetInst()->ChangeScene(new MainScene());
		}
		else {
			IntroSound->Update(deltaTime, time);
		}
	}
	else {
		BGIntroSound->Update(deltaTime, time);
	}

	if (m_Cut == 0) {
		IntroSound->play();
		BGIntroSound->stop();
		m_Cut = 100;
	}
}
void IntroScene::Render()
{
	m_IntroCut1->Render();
	m_IntroCut2->Render();
	m_IntroCut3->Render();
	m_IntroCut4->Render();
	m_IntroCut5->Render();
	m_IntroCut6->Render();
	m_IntroCut7->Render();
	m_IntroCut8->Render();
	m_IntroCut9->Render();
	m_IntroCut10->Render();
	m_IntroCut11->Render();
	m_IntroFrame->Render();
	m_IntroCut12->Render();

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	IntroText->print(Wtext,100,700);
	Renderer::GetInst()->GetSprite()->End();
}

void IntroScene::IntroChange()
{
	m_Count += dt;

	if (m_Count >= 5.5f)
	{
		switch (m_Cut)
		{
		case 1:
			if (!one)
				istextsound = false;

			m_IntroCut2->A += 5;
			if (m_IntroCut2->A == 255)
			{
				TextSound->stop();
				TextSound->play();
				text = "";
				Wtext = "";
				m_Cut = 2;
				m_Count = 0.f;
				textCount = 0;

				one = false;
			}
			break;
		case 2:
			if (!one)
				istextsound = false;
			m_IntroCut3->A += 5;
			if (m_IntroCut3->A == 255)
			{
				TextSound->stop();
				TextSound->play();
				text = "";
				Wtext = "";
				m_Cut = 3;
				m_Count = 0.f;
				textCount = 0;
				one = false;
			}
			break;
		case 3:
			if (!one)
				istextsound = false;
			m_IntroCut4->A += 5;
			if (m_IntroCut4->A == 255)
			{
				TextSound->stop();
				TextSound->play();
				text = "";
				Wtext = "";
				m_Cut = 4;
				m_Count = 0.f;
				textCount = 0;
				one = false;
			}
			break;
		case 4:
			if (!one)
				istextsound = false;
			m_IntroCut5->A += 5;
			if (m_IntroCut5->A == 255)
			{
				TextSound->stop();
				TextSound->play();
				text = "";
				Wtext = "";
				m_Cut = 5;
				m_Count = 0.f;
				textCount = 0;
				one = false;
			}
			break;
		case 5:
			if (!one)
				istextsound = false;
			m_IntroCut6->A += 5;
			if (m_IntroCut6->A == 255)
			{
				TextSound->stop();
				TextSound->play();
				text = "";
				Wtext = "";
				m_Cut = 6;
				m_Count = 0.f;
				textCount = 0;
				one = false;
			}
			break;
		case 6:
			if (!one)
				istextsound = false;
			m_IntroCut7->A += 5;
			if (m_IntroCut7->A == 255)
			{
				TextSound->stop();
				TextSound->play();
				text = "";
				Wtext = "";
				m_Cut = 7;
				m_Count = 0.f;
				textCount = 0;
				one = false;
			}
			break;
		case 7:
			if (!one)
				istextsound = false;
			m_IntroCut8->A += 5;
			if (m_IntroCut8->A == 255)
			{
				TextSound->stop();
				text = "";
				Wtext = "";
				m_Cut = 8;
				m_Count = 0.f;
				textCount = 0;
				one = false;
			}
			break;
		case 8:
			m_IntroCut9->A += 5;
			if (m_IntroCut9->A == 255)
			{
				TextSound->stop();
				m_Cut = 9;
				m_Count = 0.f;

			}
			break;
		case 9:
			m_IntroCut10->A += 5;
			if (m_IntroCut10->A == 255)
			{
				m_Cut = 10;
				m_Count = 0.f;

			}
			break;
		case 10:
			m_IntroCut11->A += 5;
			if (m_IntroCut11->A == 255)
			{
				m_Cut = 11;
				m_Count = 3.f;
			}
			break;
		case 11:
			m_IntroCut11->m_Position.y += 100 * dt;
			if (m_IntroCut11->m_Position.y > 1080/2+350)
			{
				m_Cut = 12;
				m_Count = -10.f;
			}
			break;
		
		case 12:
			m_IntroCut12->A += 5;
			if (m_IntroCut12->A == 255)
			{
				m_Cut = 13;
				m_Count = 0.f;
			}
			break;
		}
	}
}