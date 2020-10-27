#include "stdafx.h"
#include "Player_Attack.h"
#include "Bullet.h"

Player_Attack::Player_Attack(std::wstring fileName,Vec2 pos,int speed,int end ,bool LastDireIsRight)
{
	m_Attack = new Animation();
	m_Attack->SetParent(this);
	m_Attack->Init(speed, true);
	m_Attack->AddContinueFrame(fileName, 1, end);
	timer = 0.f;
	m_Position = pos;

	if (LastDireIsRight)
	{
		m_Scale.x = 1; //  -> 

	}
	else if (!LastDireIsRight)
	{
		m_Scale.x = -1;
	}
	m_Attack->A = 150;
	
	//m_Attack_A = new Animation();// 무장 상태
	//m_Attack_A->SetParent(this);
	//m_Attack_A->Init(1, true);
	//m_Attack_A->AddContinueFrame(L"Painting/Player/Attacks/attack-A", 1, 8);
	//m_AttackLastFrame = 8;

	//m_Attack_B = new Animation();// 무장 상태
	//m_Attack_B->SetParent(this);
	//m_Attack_B->Init(1, true);
	//m_Attack_B->AddContinueFrame(L"Painting/Player/Attacks/attack-B", 1, 7);

	//m_Attack_C = new Animation();// 무장 상태
	//m_Attack_C->SetParent(this);
	//m_Attack_C->Init(1, true);
	//m_Attack_C->AddContinueFrame(L"Painting/Player/Attacks/attack-C", 1, 10);

	//m_Attack_D = new Animation();// 무장 상태
	//m_Attack_D->SetParent(this);
	//m_Attack_D->Init(1, true);
	//m_Attack_D->AddContinueFrame(L"Painting/Player/Attacks/attack-D", 1, 12);
	m_End = end;
	m_LastDireIsRight = LastDireIsRight;
}

Player_Attack::~Player_Attack()
{
}

void Player_Attack::Update(float deltaTime, float Time)
{
	m_Attack->Update(deltaTime, Time);

	if (m_End == 8)
	{
		if (m_Attack->m_CurrentFrame == 6)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-A7.png", "Enemy",
				Vec2(m_Position.x , m_Position.y), m_LastDireIsRight), "Player_Sword");
		}
	}

	if (m_End == 7)
	{
		if (m_Attack->m_CurrentFrame == 4)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-B5.png", "Enemy",
				Vec2(m_Position.x, m_Position.y), m_LastDireIsRight), "Player_Sword");
		}
	}

	if (m_End == 10)
	{
		if (m_Attack->m_CurrentFrame == 6)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-C7.png", "Enemy",
				Vec2(m_Position.x, m_Position.y), m_LastDireIsRight), "Player_Sword");
		}
	}
	if (m_End == 12)
	{
		if (m_Attack->m_CurrentFrame == 3)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-D4.png", "Enemy",
				Vec2(m_Position.x , m_Position.y), m_LastDireIsRight), "Player_Sword");
		}
		if (m_Attack->m_CurrentFrame == 8)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-D9.png", "Enemy",
				Vec2(m_Position.x , m_Position.y), m_LastDireIsRight), "Player_Sword");
		}
	}
}

void Player_Attack::Render()
{
	m_Attack->Render();
}

void Player_Attack::OnCollision(Object* other)
{
}
