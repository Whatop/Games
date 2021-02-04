#include "stdafx.h"
#include "Bones.h"

Bones::Bones(Vec2 Pos, std::string color, std::string size, int direction)
{
	if (size == "small") {
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone_small.png",COLORKEY_BALCK);
		m_ColBox = Sprite::Create(L"Painting/sans/Attack/ColBox/small.png");
	}
	if (size == "middle") {
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone.png", COLORKEY_BALCK);
		m_ColBox = Sprite::Create(L"Painting/sans/Attack/ColBox/middle.png");
	}
	if (size == "big") {
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone_big.png", COLORKEY_BALCK);
		m_ColBox = Sprite::Create(L"Painting/sans/Attack/ColBox/big.png");
	}
	if (size == "long") {
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone_long.png", COLORKEY_BALCK);
		m_ColBox = Sprite::Create(L"Painting/sans/Attack/ColBox/long.png");
	}
	if (size == "lie") {
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone_lie.png", COLORKEY_BALCK);
		m_ColBox = Sprite::Create(L"Painting/sans/Attack/ColBox/lie.png");
	}
	if(color == "while") {
		m_Bones->R = 255;
		m_Bones->G = 255;
		m_Bones->B = 255;
	}
	else if (color == "blue") {
		m_Bones->R = 0;
		m_Bones->G = 168;
		m_Bones->B = 255;
	}
	m_ColBox->SetParent(this);
	SetPosition(Pos);
	m_Bones->SetPosition(Pos);
	m_direction = direction;
	m_Speed = 500.f;//속도설정 빠름 보통 해놀까?
	dtime = 0.f;

}

Bones::~Bones()
{
}

void Bones::Update(float deltaTime, float Time)
{
	dtime += dt;
	if (m_direction == _left) {
		m_Position.x -= m_Speed * dt;
	}
	else if(m_direction == _right) {
		m_Position.x += m_Speed * dt;
	}
	else if (m_direction == _up) {
		m_Position.y -= m_Speed * dt;
	}
	else if (m_direction ==_down) {
		m_Position.y += m_Speed * dt;
	}
	if (dtime >= 5)
		ObjMgr->RemoveObject(this);
	m_Bones->SetPosition(m_Position.x, m_Position.y );
	
}

void Bones::Render()
{
	m_Bones->Render();
	m_ColBox->Render();
}

void Bones::OnCollision(Object* obj)
{
}
