#include "stdafx.h"
#include "Player.h"
#include "MainScene.h"
#include "BattleScene.h"
#include "sans.h"

Player::Player()
{
	m_Player_Up = new Animation();
	m_Player_Up->SetParent(this);
	m_Player_Up->Init(0.16f, true);
	m_Player_Up->AddContinueFrame(L"Painting/Player/Up", 1, 4, COLORKEY_WHITE);

	m_Player_Down = new Animation();
	m_Player_Down->SetParent(this);
	m_Player_Down->Init(0.16f, true);
	m_Player_Down->AddContinueFrame(L"Painting/Player/Down", 1, 4, COLORKEY_WHITE);

	m_Player_Right = new Animation();
	m_Player_Right->SetParent(this);
	m_Player_Right->Init(0.16f, true);
	m_Player_Right->AddContinueFrame(L"Painting/Player/Right", 1, 2, COLORKEY_WHITE);

	m_Player_Left = new Animation();
	m_Player_Left->SetParent(this);
	m_Player_Left->Init(0.16f, true);
	m_Player_Left->AddContinueFrame(L"Painting/Player/Left", 1, 2, COLORKEY_WHITE);

	m_Player = m_Player_Right;
	m_Player->SetParent(this);
	m_Status = Status::DOWN;

	m_ColBox = Sprite::Create(L"Painting/Player/Player_ColBox.png");
	m_ColBox->m_Position = m_Position;

	m_Left = Sprite::Create(L"Painting/Player/Down.png");
	m_Left->m_Position = m_Position;

	m_Right = Sprite::Create(L"Painting/Player/Down.png");
	m_Right->m_Position = m_Position;

	m_Up = Sprite::Create(L"Painting/Player/Down.png");
	m_Up->m_Position = m_Position;

	m_Down = Sprite::Create(L"Painting/Player/Down.png");
	m_Down->m_Position = m_Position;

	m_Left->G = 0;
	m_Right->R = 0;
	m_Down->B = 0;
	m_Up->R = 0;
	m_Up->G = 0;


	m_red = Sprite::Create(L"Painting/Soul/red.png", COLORKEY_BALCK);
	m_red->m_Position = m_Position;

	m_blue = Sprite::Create(L"Painting/Soul/blue.png", COLORKEY_BALCK);
	m_blue->m_Position = m_Position;

	m_Soul_ColBox = Sprite::Create(L"Painting/Soul/ColBox.png", COLORKEY_BALCK); //다른 이름으로 설정하고 새로운 판정 만들기
	m_Soul_ColBox->m_Position = m_Position;

	m_Soul_Left = Sprite::Create(L"Painting/Soul/Left.png", COLORKEY_BALCK);
	m_Soul_Left->m_Position = m_Position;

	m_Soul_Right = Sprite::Create(L"Painting/Soul/Right.png", COLORKEY_BALCK);
	m_Soul_Right->m_Position = m_Position;

	m_Soul_Up = Sprite::Create(L"Painting/Soul/Up.png", COLORKEY_BALCK);
	m_Soul_Up->m_Position = m_Position;

	m_Soul_Down = Sprite::Create(L"Painting/Soul/Down.png", COLORKEY_BALCK);
	m_Soul_Down->m_Position = m_Position;

	m_Line = new LineMgr();
	m_Line->Init(1, true);
	m_Line->SetColor(D3DXCOLOR(255, 255, 255, 255));

	m_Speed = 450.f;

	SetPosition(175, 400);

	Up = false;
	Down = false;
	Right = false;
	Left = false;

	//m_red->m_Visible = false;
	m_blue->m_Visible = false;
	m_Soul_ColBox->m_Visible = false;
	m_Soul_Left->m_Visible = false;
	m_Soul_Right->m_Visible = false;
	m_Soul_Down->m_Visible = false;
	m_Soul_Up->m_Visible = false;
	Camera::GetInst()->Follow(this);
}
//-10 3590 333 560
Player::~Player()
{
}
//1500 이벤트 작동

void Player::Move(float deltaTime, float Time)
{
	if (SceneDirector::GetInst()->m_scene == scene::mainscene)
	{
		if (INPUT->GetKey('W') == KeyState::PRESS)
		{
			m_Player = m_Player_Up;
			m_Status = Status::UP;

			
			if (!Up) {
				m_Position.y -= m_Speed * dt;
				if (m_Player->m_CurrentFrame % 2 == 0)
					m_Player->Update(deltaTime, Time);
			}
			}
		if (INPUT->GetKey('S') == KeyState::PRESS)
		{
			m_Player = m_Player_Down;
			m_Status = Status::DOWN;

		
			if (!Down) {
				m_Position.y += m_Speed * dt;
				if (m_Player->m_CurrentFrame % 2 == 0)
					m_Player->Update(deltaTime, Time);
			}
		}
		if (INPUT->GetKey('A') == KeyState::PRESS)
		{
			m_Player = m_Player_Left;
			m_Status = Status::LEFT;

			
			if (!Left&& m_Position.x >10) {
				m_Position.x -= m_Speed * dt;
				if (m_Player->m_CurrentFrame % 2 == 0)
					m_Player->Update(deltaTime, Time);

			}
		}
		if (INPUT->GetKey('D') == KeyState::PRESS)
		{
			m_Player = m_Player_Right;
			m_Status = Status::RIGHT;


			if (!Right) {
				m_Position.x += m_Speed * dt;

				if (m_Player->m_CurrentFrame % 2 == 0)
					m_Player->Update(deltaTime, Time);
			}
		}

		if (m_Status != Status::NONE && m_Player->m_CurrentFrame % 2 != 0)
		{
			m_Player->Update(deltaTime, Time);
		}
	}
	if (SceneDirector::GetInst()->m_scene == scene::dialogscene)
	{
		if (m_Status != Status::NONE && m_Player->m_CurrentFrame % 2 != 0)
		{
			m_Player->Update(deltaTime, Time);
		}
	}
}

void Player::Update(float deltaTime, float Time)
{
	if (m_scene != scene::battlescene&&m_Position.x>270)
		Camera::GetInst()->Follow(this);

	Left = false;
	Up = false;
	Right = false;
	Down = false;

	ObjMgr->CollisionCheak(this, "Chest");
	ObjMgr->CollisionCheak(this, "Solids");
	ObjMgr->CollisionCheak(this, "Dialog");
	ObjMgr->CollisionCheak(this, "Save");
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
	{
		SceneDirector::GetInst()->ChangeScene(new MainScene());
	}
	if (INPUT->GetKey(VK_F2) == KeyState::DOWN)
	{
		SceneDirector::GetInst()->ChangeScene(new BattleScene());
	}

	Move(deltaTime, Time);

	m_ColBox->m_Position = Vec2(m_Position.x, m_Position.y + m_ColBox->m_Size.y+10);
	m_Left->m_Position = Vec2(m_Position.x-5, m_ColBox->m_Position.y + 20);
	m_Right->m_Position = Vec2(m_Position.x+ m_ColBox->m_Size.x, m_ColBox->m_Position.y+20);
	m_Up->m_Position = Vec2(m_Position.x+30, m_Position.y + m_ColBox->m_Size.y+4);
	m_Down->m_Position = Vec2(m_Position.x+30, m_ColBox-> m_Position.y + m_ColBox->m_Size.y);

	m_red->m_Position = Vec2(m_Position.x + 17, m_Position.y + 10);
	m_blue->m_Position = Vec2(m_Position.x, m_Position.y);

	m_Soul_ColBox->m_Position = Vec2(m_Position.x, m_Position.y);
	m_Soul_Up->m_Position = Vec2(m_Position.x, m_Position.y);
	m_Soul_Down->m_Position = Vec2(m_Position.x, m_Position.y);
	m_Soul_Left->m_Position = Vec2(m_Position.x, m_Position.y);
	m_Soul_Right->m_Position = Vec2(m_Position.x, m_Position.y);
	m_Player->SetVertex();

}

void Player::Render()
{
	m_Line->DrawLine(m_Vertex, 5);
	m_Player->Render();

	m_ColBox->Render();
	m_Left->Render();
	m_Right->Render();
	m_Up->Render();
	m_Down->Render();

	m_red->Render();
	m_blue->Render();

	m_Soul_ColBox->Render();
	m_Soul_Up->Render();
	m_Soul_Left->Render();
	m_Soul_Right->Render();
	m_Soul_Down->Render();
}

void Player::OnCollision(Object* other)
{
	if (other->m_Tag == "Dialog")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
		{
			SceneDirector::GetInst()->SetScene(scene::dialogscene);
			ObjMgr->DeleteObject("Dialog");
		}
	}

	if (other->m_Tag == "Chest")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
		{
			if (IntersectRect(&rc, &m_Left->m_Collision, &other->m_Collision))
			{
				Left = true;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				Right = true;
			}
			if (IntersectRect(&rc, &m_Down->m_Collision, &other->m_Collision))
			{
				Down = true;
			}
			else if (IntersectRect(&rc, &m_Up->m_Collision, &other->m_Collision))
			{
				Up = true;
			}
		}
	}
		
	if (other->m_Tag == "Solids")
	{
		RECT rc;
			if (IntersectRect(&rc, &m_Left->m_Collision, &other->m_Collision))
			{	
				Left = true;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				Right = true;
			}
			if (IntersectRect(&rc, &m_Down->m_Collision, &other->m_Collision))
			{
				Down = true;
				Left = false;
			}
			else if (IntersectRect(&rc, &m_Up->m_Collision, &other->m_Collision))
			{
				Up = true;
			}
		
	}
	if (other->m_Tag == "Save")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
		{
			if (IntersectRect(&rc, &m_Left->m_Collision, &other->m_Collision))
			{
				Left = true;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				Right = true;
			}
			if (IntersectRect(&rc, &m_Down->m_Collision, &other->m_Collision))
			{
				Down = true;
			}
			else if (IntersectRect(&rc, &m_Up->m_Collision, &other->m_Collision))
			{
				Up = true;
			}
		}
	}
}