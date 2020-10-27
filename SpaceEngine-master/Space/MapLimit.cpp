#include "stdafx.h"
#include "MapLimit.h"

MapLimit::MapLimit()
{
}

MapLimit::~MapLimit()
{
}

void MapLimit::CreateMap(int Dire, int Count, Vec2 Pos)
{
	m_Pos = Pos;
	if (Dire == HORIZONTAL)
	{
		for (int i = 0; i < Count; i++)
		{
			Sprite* floor = Sprite::Create(L"Painting/Map/Floor.png");
			floor->SetPosition(m_Pos.x, m_Pos.y + floor->m_Size.y / 2);
			ObjMgr->AddObject(floor, "Ground");
			m_Pos.x += floor->m_Size.x;
		}
	}

	if (Dire == VERTICAL)
	{
		for (int i = 0; i < Count; i++)
		{
			Sprite* floor = Sprite::Create(L"Painting/Map/Wall.png");
			floor->SetPosition(m_Pos.x, m_Pos.y);
			ObjMgr->AddObject(floor, "Wall");
			m_Pos.y -= floor->m_Size.y;
		}
	}
}