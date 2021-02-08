#include "stdafx.h"
#include "Laser.h"
#include "GasterBlaster.h"

Laser::Laser(Vec2 Pos, float Rotation, int direction) //������ ���ؼ� �� �������� ��� 
//��ü�� 5������ �϶� 1������
//��ü�� 6������ �϶� 2������
//��ü�� 7������ �϶� 3������
//��ü�� 8������ �϶� 4������ ���� �̵�
//��ü�� 9������ �϶� 5������ 
//��ü�� 10������ �϶� 6������ 
//��ü�� 11������ �϶� 7������ ���� ������
//��ü�� 12������ �϶� 8������ ������ 
//��ü�� 13������ �϶� 9������ �� ������ 
//��ü�� 14������ �϶� 10������ ���� ������ 
//��ü�� 15������ �϶� 11������ ���� ������ 
//��ü�� 16������ �϶� 12������ �� 
//��ü�� 17������ �϶� 13������  ��
//��ü�� 18������ �϶� 14������   ��
//��ü�� 19������ �϶� 15������    ��
//��ü�� 20������ �϶� 16������ �� 

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
