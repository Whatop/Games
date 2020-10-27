#include "stdafx.h"
#include "Player.h"
#include "MainScene.h"
#include "BattleScene.h"

Player::Player()
{
	m_ColBox = Sprite::Create(L"Painting/Player/ColBox.png");
	m_ColBox->SetParent(this);

	m_red = Sprite::Create(L"Painting/Player/red.png",COLORKEY_PINK);
	m_red->SetParent(this);
	m_red->SetScale(1.5f,1.5f);

	m_blue = Sprite::Create(L"Painting/Player/blue.png", COLORKEY_PINK);
	m_blue->SetParent(this);	
	m_blue->SetScale(1.5f,1.5f);

	m_red->A = 0;
	m_blue->A = 0;

	m_Speed = 500.f;

	SetPosition(175,350);	
}
//-10 3590 333 560
Player::~Player()
{
}
//1500 이벤트 작동
void Player::Move()
{
	if (SceneDirector::GetInst()->m_scene == scene::mainscene)
	{
		if (INPUT->GetKey('W') == KeyState::PRESS && m_Position.y >= 333)
		{
			m_Position.y -= m_Speed * dt;
		}
		if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x >= -10)
		{
			m_Position.x -= m_Speed * dt;
		}
		if (INPUT->GetKey('S') == KeyState::PRESS && m_Position.y <= 560)
		{
			m_Position.y += m_Speed * dt;
		}
		if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x <= 3575)
		{
			m_Position.x += m_Speed * dt;
		}
	}
	else if (SceneDirector::GetInst()->m_scene == scene::battlescene)
	{
		m_Speed = 300.f;
		m_red->A = 255;
		m_ColBox->A = 0;
		if (INPUT->GetKey('W') == KeyState::PRESS)
		{
			m_Position.y -= m_Speed * dt;
		}
		if (INPUT->GetKey('A') == KeyState::PRESS)
		{
			m_Position.x -= m_Speed * dt;
		}
		if (INPUT->GetKey('S') == KeyState::PRESS)
		{
			m_Position.y += m_Speed * dt;
		}
		if (INPUT->GetKey('D') == KeyState::PRESS)
		{
			m_Position.x += m_Speed * dt;
		}
	}
}

void Player::Update(float deltaTime, float Time)
{
	Move();
	if(m_scene!=scene::battlescene)
	Camera::GetInst()->Follow(this);

	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
	{
		SceneDirector::GetInst()->ChangeScene(new MainScene());
	}
	if (INPUT->GetKey(VK_F2) == KeyState::DOWN)
	{
		SceneDirector::GetInst()->ChangeScene(new BattleScene());
	}
}

void Player::Render()
{
	m_ColBox->Render();
	m_red->Render();
	m_blue->Render();
}

void Player::OnCollision(Object* other)
{

if (other->m_Tag == "Frame")
{
	RECT rc;
	if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
	{
		
	}
}
	//ObjMgr->AddObject(new sans(Vec2(m_Position.x, m_Position.y)), "sans"); 대화창에 닿았을때 
}