#include "stdafx.h"
#include "Laser.h"
#include "GasterBlaster.h"

Laser::Laser(Vec2 Pos, float Rotation, int direction) //각도를 구해서 그 방향으로 쏘기 
//본체가 5프레임 일때 1프레임
//본체가 6프레임 일때 2프레임
//본체가 7프레임 일때 3프레임
//본체가 8프레임 일때 4프레임 부터 이동
//본체가 9프레임 일때 5프레임 
//본체가 10프레임 일때 6프레임 
//본체가 11프레임 일때 7프레임 조금 연해짐
//본체가 12프레임 일때 8프레임 연해짐 
//본체가 13프레임 일때 9프레임 더 연해짐 
//본체가 14프레임 일때 10프레임 더더 연해짐 
//본체가 15프레임 일때 11프레임 더더 연해짐 
//본체가 16프레임 일때 12프레임 더 
//본체가 17프레임 일때 13프레임  더
//본체가 18프레임 일때 14프레임   더
//본체가 19프레임 일때 15프레임    더
//본체가 20프레임 일때 16프레임 끝 

{
	m_Laser = new Animation();
	m_Laser->Init(0.2f, true);
	m_Laser->AddContinueFrame(L"Painting/sans/Attack/Laser/Gasterblaster", 0, 7);
	
	m_ColBox = Sprite::Create(L"Painting/sans/Attack/Laser/ColBox.png");
	m_ColBox->SetParent(this);

	m_Rotation = Rotation + D3DXToRadian(90);
	m_Laser->m_Rotation = Rotation + D3DXToRadian(90);
	m_direction = direction;

	m_ColBox->A = 0;

	SetPosition(Pos);
	m_Laser->SetPosition(Pos);
	m_Speed = 500;
	rTime = 0;
}

Laser::~Laser()
{
}

void Laser::Update(float deltaTime, float Time)
{
	rTime += dt;
	m_Laser->Update(deltaTime, Time);
	m_Laser->A -= 120 * dt;
	if(m_Laser->m_CurrentFrame>=3&& m_Laser->m_CurrentFrame <= 5)
	ObjMgr->CollisionCheak(this, "Soul");

	if (m_Laser->																	A <= 0) {
		ObjMgr->RemoveObject(this);
	}

	if (rTime >= 0.65f) {
		if (m_direction % 2 != 0)
		{
			if (m_Position.x > 1940)
				m_Position.x -= m_Speed * dt;
		}

		else {
			if (m_Position.x < 3600)
			m_Position.x += m_Speed * dt; 
		}
		m_Speed += 50;
	}
	m_Laser->SetPosition(m_Position);
}

void Laser::Render()
{
	m_Laser->Render();
	m_ColBox->Render();
}

void Laser::OnCollision(Object obj)
{
}
