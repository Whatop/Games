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
	m_Laser->Init(0.2f, true);
	m_Laser->AddContinueFrame(L"Painting/sans/Attack/Laser/Gasterblaster", 1, 17, COLORKEY_WHITE);
	
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
	/*if (m_Laser->m_CurrentFrame == 7)
		m_Laser->A = 240;
	if (m_Laser->m_CurrentFrame == 8)
		m_Laser->A = 200;
	if (m_Laser->m_CurrentFrame == 9)
		m_Laser->A = 160;
	if (m_Laser->m_CurrentFrame == 10)
		m_Laser->A = 140;
	if (m_Laser->m_CurrentFrame == 11)
		m_Laser->A = 130;
	if (m_Laser->m_CurrentFrame == 12)
		m_Laser->A = 100;
	if (m_Laser->m_CurrentFrame == 13)
		m_Laser->A = 70;
	if (m_Laser->m_CurrentFrame == 14)
		m_Laser->A = 60;
	if (m_Laser->m_CurrentFrame == 15)
		m_Laser->A = 30;
	if (m_Laser->m_CurrentFrame == 16)
		m_Laser->A = 0;


	if (m_Laser->A = 0)
		ObjMgr->RemoveObject(this);*/
}

void Laser::Render()
{
	m_Laser->Render();
}

void Laser::OnCollision(Object obj)
{
}
