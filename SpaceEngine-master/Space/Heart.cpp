#include "stdafx.h"
#include "Heart.h"
#include "UI.h"

Heart::Heart(Vec2 Pos)
{
	//red R 255 G - B -
	//blue R 8 G 3 B 198

	m_red = Sprite::Create(L"Painting/Soul/red.png",COLORKEY_BALCK);
	m_red->SetParent(this);
	SetPosition(Pos);
	m_ColBox = Sprite::Create(L"Painting/Soul/ColBox.png",COLORKEY_BALCK);
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
	m_Start->volumeUp();
	m_Start->volumeUp();

	m_JumpPower = 45.f; 
	m_JumpTime = 0;
	m_JumpAccel = 0.f;
	m_PrevAccel = 0.f;
	m_JumpLate = 0.f;
	JTime = 0.f;
	m_isFall = false;
	m_isGround = false;

}

Heart::~Heart()
{
	m_Start->Release();
}

void Heart::Update(float deltaTime, float Time)
{
	m_isGround = false;

	ObjMgr->CollisionCheak(this, "Bone");
	ObjMgr->CollisionCheak(this, "BlueBone");
	ObjMgr->CollisionCheak(this, "GasterBlaster");
	
	ObjMgr->CollisionCheak(this, "Platform");
	ObjMgr->CollisionCheak(this, "Ground");
	//가블 레이저는 레이저에서 처리함
	if (m_JumpLate > 0)
	m_JumpLate -= dt;

	if (a == false) {
		stime += dt;
		if (stime > 0.15f)
			m_red->A = 0;

		if (stime > 0.25f)
			m_red->A = 255;

		if (stime > 0.35f)
			m_red->A = 0;

		if (stime > 0.45f)
			m_red->A = 255;

		if (stime > 0.55f)
			m_red->A = 0;

		if (stime > 0.65f)
		{
			m_red->A = 255;
			a = true;
		}
	}

	else if (a == true) {
		mtime += dt;

		Vec2 A, B;
		A = m_Position;
		B = Vec2(m_Position.x + App::GetInst()->m_Width / 2, 1080/2);
		A -= B;
		D3DXVec2Normalize(&Dir, &A);

		if (mtime >= 0.f && mtime <= 0.45f)
		{
			Translate(-Dir.x * 800 * dt, -Dir.y * 800 * dt);
		}
		else {
			atime += dt;
			if (atime >= 0.4f && atime <= 1.3f) {
				SceneDirector::GetInst()->SetScene(scene::testscene);
			}
			Move();
		}
	}
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
	{
		m_Color = Soul_Color::RED;
	}
	if (INPUT->GetKey(VK_F2) == KeyState::DOWN)
	{
		m_Color = Soul_Color::BULE;
	}
	if (m_Move != Soul_Movement::JUMP && m_Color==Soul_Color::BULE&&m_Position.y < 1040)
		Gravity();

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
	if (m_limit > 20) {
		m_Hp += 1;
		m_limit = 0;
	}
	m_Start->Update(deltaTime, Time);
	UI::GetInst()->m_Hp = m_Hp;
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
		if (INPUT->GetKey('W') == KeyState::DOWN && m_Move != Soul_Movement::JUMP && m_JumpLate <= 0.f)
		{
			m_JumpTime = 0;
			Pos = m_Position;
			m_Move = Soul_Movement::JUMP;

		}
	
		if (m_Move == Soul_Movement::JUMP)
		{
			if (INPUT->GetKey('W') == KeyState::UP)
			{
				Gravity();
			}
			static float minus;
			

			m_PrevAccel = m_JumpAccel;

			m_JumpAccel = ((-2.8f) / 2 * m_JumpTime * m_JumpTime) + (m_JumpPower * m_JumpTime);
			m_JumpTime += dt * 20.f;
			m_Position.y = Pos.y - m_JumpAccel;

			if (m_PrevAccel > m_JumpAccel)
			{
				m_isFall = true;
			}

			if (m_JumpAccel < 0.f)
			{
				minus = m_JumpAccel;
			}
			if (m_JumpAccel >= 0.f)
			{
				if (INPUT->GetKey('A') == KeyState::PRESS)
				{
					m_Position.x -= m_Speed * dt;
				}
				else if (INPUT->GetKey('D') == KeyState::PRESS)
				{
					m_Position.x += m_Speed * dt;
				}
			}
			if (m_JumpAccel < 0.f || (m_isFall && m_isGround))
			{
				m_PrevAccel = 0.f;
				m_JumpLate = 0.1f;
				m_Position.y += minus;
				m_Move = Soul_Movement::NONE;

			}
		}
		if (m_Move != Soul_Movement::JUMP) {
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
	}
}

void Heart::Gravity()
{
	static float vy = 0;
	vy += 9.8f * dt;

	if (!m_isGround)
	{
		m_Position.y += vy;
	}
	else
		vy = 0.f;
}

void Heart::Render()
{

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
	if (other->m_Tag == "GasterBlaster") {
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision)) {
			m_Hp -= 1;
		}
	}
	if (other->m_Tag == "Laser") {
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision)) {
			m_Hp -= 1; 
			m_limit += 1;
		}
	}
	if (other->m_Tag == "Platform") {
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			m_isFall = false;
		}
	}
	if (other->m_Tag == "Ground") {
		RECT rc;
		if (IntersectRect(&rc, &m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			m_isFall = false;
		}
	}
}
