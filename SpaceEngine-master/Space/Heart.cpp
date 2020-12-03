#include "stdafx.h"
#include "Heart.h"

Heart::Heart(Vec2 Pos)
{
	//red R 255 G - B -
	//blue R 8 G 3 B 198

	m_red = Sprite::Create(L"Painting/Soul/red.png", COLORKEY_BALCK);
	m_red->SetParent(this);
	SetPosition(Pos);
	stime = 0;
	a = false;
}

Heart::~Heart()
{
}

void Heart::Update(float deltaTime, float Time)
{

	if (a == false) {
		stime += dt;
		if (stime >= 0.15f && stime <= 0.2f)
			m_red->A = 0;

		if (stime >= 0.25f && stime <= 0.3f)
			m_red->A = 255;

		if (stime >= 0.35f && stime <= 0.4f)
			m_red->A = 0;

		if (stime >= 0.45f && stime <= 0.5f)
			m_red->A = 255;

		if (stime >= 0.55f && stime <= 0.6f)
			a = true;
		
	}

	if (a == true) {
		mtime += dt;
		if (SceneDirector::GetInst()->m_scene == scene::battlescene)//����
			m_red->A = 255;
		else
			m_red->A = 0;

		Vec2 A, B;
		A = m_Position;
		B = Vec2(2800, 680);
		A -= B;
		D3DXVec2Normalize(&Dir, &A);

		if (mtime >= 0.f && mtime <= 0.45f)
		{
			Translate(-Dir.x * 800 * dt, -Dir.y * 800 * dt);
		}
		else {
			atime += dt;
			if (atime >= 0.4f && atime <= 1.3f)
				SceneDirector::GetInst()->SetScene(scene::start);
		}
	}

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