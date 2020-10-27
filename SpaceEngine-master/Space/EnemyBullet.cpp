#include "stdafx.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(Vec2 pos, float R)
{
	m_Bullet = Sprite::Create(L"Painting/Player.png");
	m_Bullet->SetParent(this);

	m_Position = pos;
	m_Rotation = D3DXToRadian(90);
	R = R;
	m_Speed = 1400.f;
	//m_Arrive = INPUT->GetMousePos();
	t = M_PI;
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update(float deltaTime, float Time)
{
	
	m_Arrive = Vec2(cos(m_Rotation), sin(m_Rotation));
	U = 2*t*R/2;
	W = 2*t/2;
	V = R * W;
	m_Dir = Vec2(U,W);
	D3DXVec2Normalize(&m_Dir, &m_Dir); 
	Translate(m_Dir.x * m_Speed * dt, m_Dir.y * m_Speed * dt);

	//ObjMgr->CollisionCheak(this, "Enemy");
	//ObjMgr->CollisionCheak(this, "EnemyShield");
}

void EnemyBullet::Render()
{
	m_Bullet->Render();
}

void EnemyBullet::OnCollision(Object* other)
{
	if (other->m_Tag == "Enemy")
	{
		//other->m_HP -= GameMgr::GetInst()->m_PlayerStat->Atk;
		//ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/ex2/expl_01_00", 1, 21, m_Position, 0.01f, true), "Effect");
		//ObjMgr->RemoveObject(this);
	}
	if (other->m_Tag == "EnemyShield")
	{
		//ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/ex2/expl_01_00", 1, 21, m_Position, 0.01f, true), "Effect");
		//ObjMgr->RemoveObject(this);
	}
}
