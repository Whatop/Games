#include "stdafx.h"
#include "Laser.h"
#include "GasterBlaster.h"

Laser::Laser(Vec2 Pos,float Rotation) //������ ���ؼ� �� �������� ��� 
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
	m_Laser->SetParent(this);
	m_Laser->Init(0.15f, true);
	m_Laser->AddContinueFrame(L"Painting/sans/Attack/Laser/Gasterblaster", 0, 7, COLORKEY_WHITE);
	
	//m_ColBox = Sprite::Create(L"Painting/sans/Attack/gasterblaster1.png"); �߰��ؾߵɰ�
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
