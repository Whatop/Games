#include "stdafx.h"
#include "Heart.h"

Heart::Heart(Vec2 Pos)
{
	//red R 255 G - B -
	//blue R 8 G 3 B 198

	m_red = Sprite::Create(L"Painting/Soul/red.png", COLORKEY_BALCK);
	m_red->SetParent(this);
	SetPosition(Pos);

}

Heart::~Heart()
{
}

void Heart::Update(float deltaTime, float Time)
{
	if (SceneDirector::GetInst()->m_scene == scene::battlescene)//ÀüÅõ
		m_red->A = 255;
	else
		m_red->A = 255;

	if (m_Color == Player_Color::RED) {
		m_red->R = 255;
		m_red->G = 0;
		m_red->B = 0;
	}
	else {
		m_red->R = 8;
		m_red->G = 3;
		m_red->B = 198;
	}

}

void Heart::Render()
{
	m_red->Render();
}

void Heart::OnCollision(Object* other)
{
}
