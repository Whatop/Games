#include "stdafx.h"
#include "Trail.h"
Trail::Trail(std::wstring fileName, std::string Name, Vec2 pos, bool LastDireIsRight)
{
	m_Obj = Sprite::Create(fileName);
	m_Obj->SetParent(this);
	m_Position = pos;
	m_Obj->A = 100;
	timer = 0.f;
	if (LastDireIsRight)
	{
		m_Scale.x = 1; //  -> 
	}
	else if (!LastDireIsRight)
	{
		m_Scale.x = -1;
	}
	m_Name = Name;
}

Trail::~Trail()
{
}

void Trail::Update(float deltaTime, float Time)
{
	ObjMgr->CollisionCheak(this, m_Name);
	timer += dt;
	if (timer >= 0.08f)
		SetDestroy(true);
}

void Trail::Render()
{
	m_Obj->Render();
}
