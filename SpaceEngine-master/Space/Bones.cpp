#include "stdafx.h"
#include "Bones.h"

Bones::Bones(Vec2 Pos, std::string type, std::string size, bool)
{
	m_Bones = Sprite::Create(L"Painting/sans/Attack/Bone.png");
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
