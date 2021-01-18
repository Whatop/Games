#include "stdafx.h"
#include "GasterBlaster.h"

GasterBlaster::GasterBlaster(Vec2 SpawnPos, int direction)// ũ�� : Ȧ����, �߰�, ū
									  // ���� : ������ġ��ȯ, ���ʿ����� ����
									  // �´� ������ ���� �ְ� Ŀ���ٰ� �پ����
									  // 0������ ���� 90����
									  // 0������ ���� -90���� 
{
	m_GBlaster = new Animation();
	m_GBlaster->SetParent(this);
	m_GBlaster->Init(0.15f, true);
	m_GBlaster->AddContinueFrame(L"Painting/sans/Attack/gasterblaster", 1, 12, COLORKEY_GASTER);

	m_ColBox = Sprite::Create(L"Painting/sans/Attack/gasterblaster1.png");
	m_ColBox->SetParent(this);
	SetPosition(SpawnPos);
	//A = SpawnPos;
	m_direction = direction;

	m_Speed = 500.f;
	m_ColBox->A = 0;

	lifeTime = 0;
	rTime = 0;

	m_gasterblaster = new SoundMgr("Sound/gasterblaster.mp3", false);
	m_gasterblaster->play();
	m_gasterblaster->volumeUp(); 
	m_Rotation = D3DXToRadian(0);
	if (m_direction % 2 != 0) {
		Pos.x = 300;
		std::cout << ":  ���� " << std::endl;
	}
	else {
		Pos.x = 1600;
		std::cout << ":  ������ " << std::endl;
	}
}

GasterBlaster::~GasterBlaster()
{
}

void GasterBlaster::Update(float deltaTime, float Time)
{
	rTime += dt;
	if (m_Position.y <= Pos.y) { //�� ��ġ ������ ��ġ���� Ŀ���� ����
		int random = rand() % 3+1;

		if (random == 1) {
			Pos.y = 1080 / 2;
			std::cout << random << ":  �� " << std::endl;
		}
		else if (random == 2) {
			Pos.y = 1080 / 2 + 150;
			std::cout << random << ":  �߰� " << std::endl;
		}
		else if (random == 3) {
			Pos.y = 1080 / 2 + 300;
			std::cout << random << ":  �Ʒ� " << std::endl;
		}
		
		//B = Vec2(Pos.x, Pos.y); //�̵��ؾ� �� ��ġ
		//A -= B;
		//D3DXVec2Normalize(&C, &A);
		//m_Rotation = atan2(C.x, -C.y);
		//Translate(-C.x * m_Speed * dt, -C.y * m_Speed * dt);

		if (m_direction % 2 != 0) {
			if (m_Rotation < D3DXToRadian(90))
				m_Rotation += D3DXToRadian(3);
			else
				m_Rotation = D3DXToRadian(90);
	
		}
		else {
			
			if (m_Rotation > D3DXToRadian(-90))
				m_Rotation += D3DXToRadian(-3); 
			else 
				m_Rotation = D3DXToRadian(-90);	
		}
		m_Position.y += 1600 * dt;

	}
	else {
		if (m_GBlaster->m_CurrentFrame < 6) {
			m_GBlaster->Update(deltaTime, Time);
			m_Speed = 500;
		}
		else
		{
			if (m_direction % 2 != 0) 
				m_Position.x -= m_Speed * dt;
			
			else
				m_Position.x += m_Speed * dt;
				
			m_Speed += 110;
			lifeTime += dt;
			if (lifeTime > 5)   
				ObjMgr->RemoveObject(this);
		}
	}
	m_gasterblaster->Update(deltaTime,Time);
}

void GasterBlaster::Render()
{
	m_GBlaster->Render();
	m_ColBox->Render();
}

void GasterBlaster::OnCollision(Object* obj)
{
}
