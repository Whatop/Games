#include "stdafx.h"
#include "Laser.h"
#include "GasterBlaster.h"

Laser::Laser(Vec2 Pos,float Rotation) //각도를 구해서 그 방향으로 쏘기 
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
	m_Laser->SetParent(this);
	m_Laser->Init(0.15f, true);
	m_Laser->AddContinueFrame(L"Painting/sans/Attack/Laser/Gasterblaster", 0, 7, COLORKEY_WHITE);
	
	//m_ColBox = Sprite::Create(L"Painting/sans/Attack/gasterblaster1.png"); 추가해야될것
	//m_ColBox->SetParent(this);
	m_Rotation = Rotation + D3DXToRadian(90);


	m_Laser->A = 255;
	SetPosition(Pos);
}

Laser::~Laser()
{
}

void Laser::Update(float deltaTime, float Time)
{
	m_Laser->Update(deltaTime, Time);
	m_Laser->A -= 200 * dt;

	if (m_Laser->A <= 0) {
		ObjMgr->RemoveObject(this);
	}
}

void Laser::Render()
{
	m_Laser->Render();
}

void Laser::OnCollision(Object obj)
{
}
