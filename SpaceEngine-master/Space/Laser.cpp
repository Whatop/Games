#include "stdafx.h"
#include "Laser.h"

Laser::Laser() //������ ���ؼ� �� �������� ���
{
	m_Laser = new Animation();
	m_Laser->SetParent(this);
	m_Laser->Init(0.15f, true);
	m_Laser->AddContinueFrame(L"Painting/sans/Attack/GasterBlaster/Laser/Gasterblaster", 1, 12, COLORKEY_GASTER);
	
	//m_ColBox = Sprite::Create(L"Painting/sans/Attack/gasterblaster1.png"); �߰��ؾߵɰ�
	//m_ColBox->SetParent(this);

	//SetPosition(SpawnPos);
}

Laser::~Laser()
{
}

void Laser::Update(float deltaTime, float Time)
{
}

void Laser::Render()
{
}

void Laser::OnCollision(Object obj)
{
}
