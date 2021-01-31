#include "stdafx.h"
#include "Bones.h"

Bones::Bones(Vec2 Pos, std::string type, std::string size, bool)
{
if (type == "basic") {
	if (size == "small")
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone_small.png");

	if (size == "middle")
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone.png");

	if (size == "big")
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone_big.png");

	if (size == "long")
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone_long.png");

	if (size == "lie")
		m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone_lie.png");
}
if (type == "blue") {
	m_Bones->R = 0;
	m_Bones->G = 168;
	m_Bones->B = 255;
}
	m_Bones->SetParent(this);
	SetPosition(Pos);
}

Bones::~Bones()
{
}

void Bones::Update(float deltaTime, float Time)
{

}

void Bones::Render()
{
	m_Bones->Render();
}

void Bones::OnCollision(Object* obj)
{
}
