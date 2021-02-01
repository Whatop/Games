#include "stdafx.h"
#include "Player.h"
#include "MainScene.h"
#include "BattleScene.h"
#include "sans.h"
#include "Text_Bubbles.h"
#include "UI.h"
#include "Heart.h"
#include "TestScene.h"
#include "Interaction1.h"

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

	m_Line = new LineMgr();
	m_Line->Init(1, true);
	m_Line->SetColor(D3DXCOLOR(255, 255, 255, 255));

	m_Speed = 450.f;

	SetPosition(175, 400);

	Up = false;
	Down = false;
	Right = false;
	Left = false;

	m_ColBox->m_Visible = false;
	m_Left->m_Visible = false;
	m_Right->m_Visible = false;
	m_Down->m_Visible = false;
	m_Up->m_Visible = false;
}
//-10 3590 333 560
Player::~Player()
{
}
//1500 이벤트 작동

void Player::Move(float deltaTime, float Time)
{
	if (SceneDirector::GetInst()->m_scene == scene::mainscene && SceneDirector::GetInst()->m_Move != Interaction::NONE) // 플레이어 상태일때
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

			
			if (!Left && m_Position.x > 10) {
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
	else if (SceneDirector::GetInst()->m_scene == scene::dialogscene)//대화
	{
		if (m_Status != Status::NONE && m_Player->m_CurrentFrame % 2 != 0)
		{
			m_Player->Update(deltaTime, Time);
		}
	}
	//영혼 분리완료
}

void Player::Update(float deltaTime, float Time)
{
	if (m_Position.x < 270)
		Camera::GetInst()->SetPos(270);
	else if (m_scene != scene::battlescene)
		Camera::GetInst()->Follow(this);

	Left = false;
	Up = false;
	Right = false;
	Down = false;
	Save = false;
	Chest = false;

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
	if (INPUT->GetKey('Z') == KeyState::DOWN)
	{
		if (Save && SceneDirector::GetInst()->m_Move != Interaction::NONE) {//이렇게 제한 안걸어놓으면 계속생성되서 문제임
																			       //사실 간단하게 Object뺴고 Singleton 쓰면되는대 귀찮음
			ObjMgr->AddObject(new Interaction1(Vec2(m_Position.x-300, m_Position.y - 300), "Save"),"Interaction");
			SceneDirector::GetInst()->m_Move = Interaction::NONE;
		}
		if (Chest && SceneDirector::GetInst()->m_Move != Interaction::NONE) {
			ObjMgr->AddObject(new Interaction1(Vec2(m_Position.x-600, m_Position.y-400), "Chest"), "Interaction");
			SceneDirector::GetInst()->m_Move = Interaction::NONE;
		}


		if (UI::GetInst()->b == true) {
			ObjMgr->DeleteObject("Chet");
			ObjMgr->DeleteObject("Chest");
			ObjMgr->DeleteObject("Save");
			ObjMgr->DeleteObject("sans");
			ObjMgr->DeleteObject("Solids");
			ObjMgr->DeleteObject("Pillar");
			UI::GetInst()->b = false;
			UI::GetInst()->d = false;
			ObjMgr->AddObject(new Heart(Vec2(m_Position.x + m_Player->m_Size.x / 2-11,m_Position.y+m_Player->m_Size.y/2)), "Heart");
			//SceneDirector::GetInst()->ChangeScene(new BattleScene());
			SceneDirector::GetInst()->ChangeScene(new TestScene());
		}
	}
	else if (INPUT->GetKey('X') == KeyState::DOWN)
	{
	
	}
	else if (INPUT->GetKey('C') == KeyState::DOWN)
	{

	}

	Move(deltaTime, Time);

	m_ColBox->m_Position = Vec2(m_Position.x, m_Position.y + m_ColBox->m_Size.y+10);
	m_Left->m_Position = Vec2(m_Position.x-5, m_ColBox->m_Position.y + 20);
	m_Right->m_Position = Vec2(m_Position.x+ m_ColBox->m_Size.x, m_ColBox->m_Position.y+20);
	m_Up->m_Position = Vec2(m_Position.x+30, m_Position.y + m_ColBox->m_Size.y+4);
	m_Down->m_Position = Vec2(m_Position.x+30, m_ColBox-> m_Position.y + m_ColBox->m_Size.y);

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
				Chest = true;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				Right = true;
				Chest = true;
			}
			if (IntersectRect(&rc, &m_Down->m_Collision, &other->m_Collision))
			{
				Down = true;
				Left = false;
				Chest = true;
			}
			else if (IntersectRect(&rc, &m_Up->m_Collision, &other->m_Collision))
			{
				Up = true;
				Chest = true;
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
				Save = true;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				Right = true;
				Save = true;
			}
			if (IntersectRect(&rc, &m_Down->m_Collision, &other->m_Collision))
			{
				Down = true;
				Left = false;
				Save = true;
			}
			else if (IntersectRect(&rc, &m_Up->m_Collision, &other->m_Collision))
			{
				Up = true;
				Save = true;
			}
		}
	
	}
}