#include "stdafx.h"
#include "GasterBlaster.h"

GasterBlaster::GasterBlaster(Vec2 Pos)// 크기 : 홀쭉한, 중간, 큰
									  // 종류 : 랜덤위치소환, 왼쪽오른쪽 가로
{
	m_GBlaster = new Animation();
	m_GBlaster->SetParent(this);
	m_GBlaster->Init(0.1f, true);
	m_GBlaster->AddContinueFrame(L"Painting/sans/Attack/gasterblaster", 1, 6, COLORKEY_GASTER);

	m_ColBox = Sprite::Create(L"Painting/sans/Attack/gasterblaster1.png");
	m_ColBox->SetParent(this);
	SetPosition(Pos);

	m_Speed = 500.f;
	m_ColBox->A = 0;

	A = m_Position;
	for (auto iter = ObjMgr->m_Objects.begin(); iter != ObjMgr->m_Objects.end(); ++iter)
	{
		if ((*iter)->m_Tag == "Heart")
		{
			B = (*iter)->m_Position;
		}
	}
	A -= B;
	D3DXVec2Normalize(&C, &A);
	m_Rotation = atan2(C.x, -C.y);
	lifeTime = 0;
	//랜덤한 위치 조정
	//m_Position.x = x - App::GetInst()->m_Width / 2;

	int randomx = rand() % 1920;
	int randomy = rand() % 1080;
}

GasterBlaster::~GasterBlaster()
{
}

void GasterBlaster::Update(float deltaTime, float Time)
{
	//if()

	if (m_GBlaster->m_CurrentFrame != 5 || ntRange)
		m_GBlaster->Update(deltaTime, Time);
	else
	{
		lifeTime += dt;
		m_Speed += 110;
		Translate(-C.x * -m_Speed * dt, -C.y * -m_Speed * dt);
		if (lifeTime > 5)
			ObjMgr->RemoveObject(this);
	}	
}

void GasterBlaster::Render()
{
	m_GBlaster->Render();
	m_ColBox->Render();
}

void GasterBlaster::OnCollision(Object* obj)
{
}
