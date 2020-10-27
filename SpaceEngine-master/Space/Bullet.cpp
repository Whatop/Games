#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(std::wstring fileName, std::string Enemy,Vec2 pos, bool LastDireIsRight)
{
	m_Bullet = Sprite::Create(fileName);
	m_Bullet->SetParent(this);
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
	m_Bullet->A = 50;
	m_Name = Enemy;
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime, float Time)
{
	ObjMgr->CollisionCheak(this, m_Name);
	timer += dt;

	if (timer >= 0.08f)
		SetDestroy(true);
}

void Bullet::Render()
{
	m_Bullet->Render();
}

void Bullet::OnCollision(Object* other)
{
	if (other->m_Tag == "Enemy")
	{
		ObjMgr->RemoveObject(this);
	}
	if (other->m_Tag == "Player")
	{
		ObjMgr->RemoveObject(this);
	}
	if (other->m_Tag == "Shield")
	{
		ObjMgr->RemoveObject(this);
	}
}
