#include "stdafx.h"
#include "Heart.h"

Heart::Heart(Vec2 Pos)
{
	//red R 255 G - B -
	//blue R 8 G 3 B 198

	m_red = Sprite::Create(L"Painting/Soul/red.png");
	m_red->SetParent(this);
	SetPosition(Pos);
	m_ColBox = Sprite::Create(L"Painting/Soul/ColBox.png");
	stime = 0;
	a = false;
	m_Hp = 92;
	m_Speed = 450;
	m_Text = new TextMgr();
	m_Text->Init(60, true, false, L"Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);
	m_Move = Soul_Movement::NONE;
	m_Start = new SoundMgr("Sound/Start.mp3", false);
	m_Start->play();
}

Heart::~Heart()
{
}

void Heart::Update(float deltaTime, float Time)
{
	m_Start->Update(deltaTime, Time);
	ObjMgr->CollisionCheak(this, "Bone");
	ObjMgr->CollisionCheak(this, "BlueBone");
	ObjMgr->CollisionCheak(this, "GasterBlaster");
	ObjMgr->CollisionCheak(this, "Platform");
	if (a == false) {
		stime += dt;
		if (stime > 0.1f)
			m_red->A = 0;

		if (stime > 0.2f)
			m_red->A = 255;

		if (stime > 0.3f)
			m_red->A = 0;

		if (stime > 0.4f)
			m_red->A = 255;

		if (stime > 0.5f)
			m_red->A = 0;

		if (stime > 0.6f)
		{
			m_red->A = 255;
			a = true;
		}
	}

	else if (a == true) {
		mtime += dt;

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
			if (atime >= 0.4f && atime <= 1.3f) {
				m_Position.x = 1920 / 2;
				SceneDirector::GetInst()->SetScene(scene::testscene);
				Camera::GetInst()->Init();
			}
			Move();
		}
	}

	if (m_Color == Soul_Color::RED) {
		m_red->R = 255;
		m_red->G = 0;
		m_red->B = 0;
	}
	else {
		m_red->R = 8;
		m_red->G = 3;
		m_red->B = 198;
	}
	m_ColBox->SetPosition(m_Position.x, m_Position.y);
}


void Heart::Move()
{
	if (m_Color == Soul_Color::RED) {
		if (INPUT->GetKey('W') == KeyState::PRESS)
		{
			m_Move = Soul_Movement::UP;
			m_Position.y -= m_Speed * dt;
		}
		if (INPUT->GetKey('W') == KeyState::UP)
		{
			m_Move = Soul_Movement::NONE;
		}
		if (INPUT->GetKey('S') == KeyState::PRESS)
		{
			m_Move == Soul_Movement::DOWN;
			m_Position.y += m_Speed * dt;
		}
		if (INPUT->GetKey('S') == KeyState::UP)
		{
			m_Move = Soul_Movement::NONE;
		}
		if (INPUT->GetKey('A') == KeyState::PRESS)
		{
			m_Move = Soul_Movement::LEFT;
			m_Position.x -= m_Speed * dt;
		}
		if (INPUT->GetKey('A') == KeyState::UP)
		{
			m_Move = Soul_Movement::NONE;
		}
		if (INPUT->GetKey('D') == KeyState::PRESS)
		{
			m_Move = Soul_Movement::RIGHT;
			m_Position.x += m_Speed * dt;
		}
		if (INPUT->GetKey('D') == KeyState::UP)
		{
			m_Move = Soul_Movement::NONE;
		}
	}
	else if (m_Color == Soul_Color::BULE) //점프 만들기
	{
		if (INPUT->GetKey('W') == KeyState::PRESS)
		{
			m_Position.y -= m_Speed * dt;
		}
		if (INPUT->GetKey('S') == KeyState::PRESS)
		{
			m_Position.y += m_Speed * dt;
		}
		if (INPUT->GetKey('A') == KeyState::PRESS)
		{
			m_Position.x -= m_Speed * dt;
		}
		if (INPUT->GetKey('D') == KeyState::PRESS)
		{
			m_Position.x += m_Speed * dt;
		}
	}
}

void Heart::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(m_Hp), 1500, 1000);
	Renderer::GetInst()->GetSprite()->End();
	m_red->Render();
	m_ColBox->Render();
}

void Heart::OnCollision(Object* other)
{
	if (other->m_Tag == "BlueBone" && m_Move != Soul_Movement::NONE) {
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision)) {
			m_Hp -= 1;
		}
	}
	if (other->m_Tag == "Bone") {
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision)) {
			m_Hp -= 1;
		}
	}
}