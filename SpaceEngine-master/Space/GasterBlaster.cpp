#include "stdafx.h"
#include "GasterBlaster.h"
#include "Laser.h"

GasterBlaster::GasterBlaster(Vec2 SpawnPos, int direction)// ũ�� : Ȧ����, �߰�, ū
									  // ���� : ������ġ��ȯ, ���ʿ����� ����
									  // �´� ������ ���� �ְ� Ŀ���ٰ� �پ����
									  // 0������ ���� 90����
									  // 0������ ���� -90���� 
{
	m_GBlaster = new Animation();
	m_GBlaster->SetParent(this);
	m_GBlaster->Init(0.14f, true);
	m_GBlaster->AddContinueFrame(L"Painting/sans/Attack/GasterBlaster/gasterblaster", 1, 20, COLORKEY_GASTER);

	SetPosition(SpawnPos);
	//A = SpawnPos;
	m_direction = direction;

	m_Speed = 500.f;

	lifeTime = 0;
	rTime = 0;

	m_gasterblaster = new SoundMgr("Sound/gasterblaster.mp3", false);
	m_gasterblaster->play();
	m_gasterblaster->volumeUp();
	m_gasterblaster->volumeUp();
	m_Rotation = D3DXToRadian(0);
	random = rand() % 900 + 200;
	//if(random%200==0)
	Pos.y = random;
}
	

GasterBlaster::~GasterBlaster()
{
}

void GasterBlaster::Update(float deltaTime, float Time)
{
	if (m_direction % 2 != 0) {

		if (m_Rotation > D3DXToRadian(-90))
			m_Rotation += D3DXToRadian(-3);
		else
			m_Rotation = D3DXToRadian(-90);

	}
	else {

		if (m_Rotation < D3DXToRadian(90))
			m_Rotation += D3DXToRadian(3);
		else
			m_Rotation = D3DXToRadian(90);

	}
	if (m_Position.y <= Pos.y) { //�� ��ġ ������ ��ġ���� Ŀ���� ����
		//B = Vec2(Pos.x, Pos.y); //�̵��ؾ� �� ��ġ
		//A -= B;
		//D3DXVec2Normalize(&C, &A);
		//m_Rotation = atan2(C.x, -C.y);
		//Translate(-C.x * m_Speed * dt, -C.y * m_Speed * dt);
		m_Position.y += 1600 * dt;

	}
	else {
		if (m_GBlaster->m_CurrentFrame == 4) {
			if (m_direction % 2 != 0 && one == false) {
				ObjMgr->AddObject(new Laser(Vec2(m_Position.x+1600, m_Position.y), m_Rotation, m_direction), "Laser");
				one = true;
			}
			else if (m_direction % 2 == 0 && one == false) {
				ObjMgr->AddObject(new Laser(Vec2(m_Position.x-1600, m_Position.y), m_Rotation, m_direction), "Laser");
				one = true;
			}
		}
		if (m_GBlaster->m_CurrentFrame >= 8) {

			if (m_direction % 2 != 0)
				m_Position.x -= m_Speed * dt;

			else
				m_Position.x += m_Speed * dt;

			m_Speed += 50;

			lifeTime += dt;
			if (lifeTime > 8)
				ObjMgr->RemoveObject(this);
		}
		if (m_GBlaster->m_CurrentFrame < 20) {
			m_GBlaster->Update(deltaTime, Time);
		}

	}
	m_gasterblaster->Update(deltaTime, Time);
}

void GasterBlaster::Render()
{
	m_GBlaster->Render();
}

void GasterBlaster::OnCollision(Object* obj)
{
}
