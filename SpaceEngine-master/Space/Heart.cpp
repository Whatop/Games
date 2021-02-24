#include "stdafx.h"
#include "Heart.h"
#include "UI.h"

Heart::Heart(Vec2 Pos)
{
	//red R 255 G - B -
	//blue R 8 G 3 B 198

	m_red = Sprite::Create(L"Painting/Soul/red.png", COLORKEY_BLACK);
	m_red->SetParent(this);
	SetPosition(Pos);
	m_ColBox = Sprite::Create(L"Painting/Soul/ColBox.png", COLORKEY_BLACK);
	m_Left = Sprite::Create(L"Painting/Soul/Left.png");
	m_Right = Sprite::Create(L"Painting/Soul/Right.png");
	m_Up = Sprite::Create(L"Painting/Soul/Up.png");
	m_Down = Sprite::Create(L"Painting/Soul/Down.png");

	m_ColBox->m_Visible = false;
	m_Left->m_Visible = false;
	m_Right->m_Visible = false;
	m_Up->m_Visible = false;
	m_Down->m_Visible = false;
	stime = 0;
	a = false;
	m_Hp = 92;
	m_Speed = 450;
	m_Text = new TextMgr();
	m_Text->Init(60, true, false, L"Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);
	m_Move = Soul_Movement::NONE;
	m_Color = Soul_Color::RED;
	m_Start = new SoundMgr("Sound/Start.mp3", false);
	m_Start->play();
	m_Start->volumeUp();
	m_Start->volumeUp();

	m_JumpTime = 0.f;
	
	JTime = 0.f;
	m_isFall = false;
	m_isGround = false;
	m_Gravity = _down;
	m_Layer = 1;
}

Heart::~Heart()
{
	m_Start->Release();
}

void Heart::Update(float deltaTime, float Time)
{
	m_isGround = false;
	left = false;
	right= false;
	up= false;
	down = false;

	ObjMgr->CollisionCheak(this, "Bone");
	ObjMgr->CollisionCheak(this, "BlueBone");
	ObjMgr->CollisionCheak(this, "GasterBlaster");
	ObjMgr->CollisionCheak(this, "Platform");

	ObjMgr->CollisionCheak(this, "LGround");
	ObjMgr->CollisionCheak(this, "RGround");
	ObjMgr->CollisionCheak(this, "UGround");
	ObjMgr->CollisionCheak(this, "DGround");
	//가블 레이저는 레이저에서 처리함


	if (a == false) {
		stime += dt;
		if (stime > 0.45f)
			m_Visible = false;

		if (stime > 0.55f)
			m_Visible = true;

		if (stime > 0.65f)		
			m_Visible = false;

		if (stime > 0.75f)
			m_Visible = true;

		if (stime > 0.85f)
			m_Visible = false;

		if (stime > 1.95f)
		{
			m_Visible = true;
			a = true;
		}
	}

	else if (a == true) {
		mtime += dt;

		Vec2 A, B;
		A = m_Position; // 좌 1810 우 3730
						// 상 0 하 1080
		B = Vec2(2775, 1080/2);
		A -= B;
		D3DXVec2Normalize(&Dir, &A);

		if (mtime >= 0.f && mtime <= 0.35f)
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
	if (INPUT->GetKey(VK_F3) == KeyState::DOWN)
	{
		m_Gravity = _left;
	}
	if (INPUT->GetKey(VK_F4) == KeyState::DOWN)
	{
		m_Gravity = _right;
	}
	if (INPUT->GetKey(VK_F5) == KeyState::DOWN)
	{
		m_Gravity = _up;
	}
	if (INPUT->GetKey(VK_F6) == KeyState::DOWN)
	{
		m_Gravity = _down;
	}
	if (m_Color==Soul_Color::BULE&&m_Move!= Soul_Movement::JUMP)
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
	if (m_limit > 20) {
		m_Hp += 1;
		m_limit = 0;
	}
	m_Start->Update(deltaTime, Time);
	UI::GetInst()->m_Hp = m_Hp;

	if (m_Color == Soul_Color::RED) {
		m_Rotation = D3DXToRadian(0);
	}
		if (m_Gravity == _left) {
			m_Rotation = D3DXToRadian(90);
			m_Directon = m_Left;
		}
		else if (m_Gravity == _right) {
			m_Rotation = D3DXToRadian(270);
			m_Directon = m_Right;
		}
		else if (m_Gravity == _up) {
			m_Rotation = D3DXToRadian(180);
			m_Directon = m_Up;
		}
		else if (m_Gravity == _down) {
			m_Rotation = D3DXToRadian(0);
			m_Directon = m_Down;
		}
	m_ColBox->SetPosition(m_Position.x, m_Position.y);
	m_Left->SetPosition(m_Position.x - m_Size.x / 2 - 2, m_Position.y);
	m_Right->SetPosition(m_Position.x + m_Size.x / 2 + 2, m_Position.y);
	m_Up->SetPosition(m_Position.x, m_Position.y - m_Size.y / 2 - 2);
	m_Down->SetPosition(m_Position.x, m_Position.y + m_Size.y / 2 + 2);
}


void Heart::Move()//Ground를 없에고 판정을 좌표로 해보기 
{
	// 좌 1810 우 3730
	// 상 0 하 1080
	if (m_Color == Soul_Color::RED) {
		if (INPUT->GetKey('W') == KeyState::PRESS&& m_Position.y > 0+30+16)
		{
			m_Move = Soul_Movement::UP;
			m_Position.y -= m_Speed * dt;
		}
		if (INPUT->GetKey('W') == KeyState::UP)
		{
			m_Move = Soul_Movement::NONE;
		}
		if (INPUT->GetKey('S') == KeyState::PRESS && m_Position.y < 1080-30 - 16)
		{
			m_Move == Soul_Movement::DOWN;
			m_Position.y += m_Speed * dt;
		}
		if (INPUT->GetKey('S') == KeyState::UP)
		{
			m_Move = Soul_Movement::NONE;
		}
		if (INPUT->GetKey('A') == KeyState::PRESS&& m_Position.x > 1810+30 + 16)
		{
			m_Move = Soul_Movement::LEFT;
			m_Position.x -= m_Speed * dt;
		}
		if (INPUT->GetKey('A') == KeyState::UP)
		{
			m_Move = Soul_Movement::NONE;
		}
		if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x < 3730-30 - 16)
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
		if (INPUT->GetKey('W') == KeyState::DOWN && m_isGround)
		{
			Pos = m_Position;
			m_Move = Soul_Movement::JUMP;
		}
	
		if (m_Move == Soul_Movement::JUMP)
		{
			m_PrevAccel = m_JumpAccel;

			m_JumpAccel = ((-9.8f) / 2 * m_JumpTime * m_JumpTime) + (75.f * m_JumpTime);//올라갔다가 낮아져아되
			m_JumpTime += dt * 10.6f;
			JTime += dt;

			if (INPUT->GetKey('W') == KeyState::UP) {
				m_PrevAccel = 2000.f;
			}

			if (INPUT->GetKey('A') == KeyState::PRESS && m_Gravity == _down)
					m_Position.x -= m_Speed * dt;

			else if (INPUT->GetKey('D') == KeyState::PRESS && m_Gravity == _down)
					m_Position.x += m_Speed * dt;

			if (INPUT->GetKey('A') == KeyState::PRESS && m_Gravity == _up)
				m_Position.x += m_Speed * dt;

			else if (INPUT->GetKey('D') == KeyState::PRESS && m_Gravity == _up)
				m_Position.x -= m_Speed * dt;


				if (m_Gravity == _left) {
					m_Position.x = Pos.x + m_JumpAccel;
				}
				else if (m_Gravity == _right) {
					m_Position.x = Pos.x - m_JumpAccel;
				}
				else if (m_Gravity == _up) {
					m_Position.y = Pos.y + m_JumpAccel;
				}
				else if (m_Gravity == _down) {
					m_Position.y = Pos.y - m_JumpAccel;
				}

				if (m_PrevAccel > m_JumpAccel)
				{
					JTime = 0.f;
					m_PrevAccel = 0.f;
					m_JumpAccel = 0.f;
					m_JumpTime = 0.f;
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
	if(vy < 10.3f)
		vy += 9.8f * dt;

	if (!m_isGround)
	{
		if (m_Gravity == _left) {
			m_Position.x -= vy;
		}
		else if (m_Gravity == _right) {
			m_Position.x += vy;
		}
		else if (m_Gravity == _up) {
			m_Position.y -= vy;
		}
		else if (m_Gravity == _down) {
			m_Position.y += vy;
		}
	}
	else
		vy = 0.f;
}

void Heart::Render()
{
	m_red->Render();
	m_ColBox->Render();
	m_Left->Render();
	m_Right->Render();
	m_Up->Render();
	m_Down->Render();
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
		if (IntersectRect(&rc, &m_Directon->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
		}
	}
	if (other->m_Tag == "LGround") {
		RECT rc;
		if (IntersectRect(&rc, &m_Left->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			left = true;
		}
		if (IntersectRect(&rc, &m_Right ->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			left = true;
		}
	}
	if (other->m_Tag == "RGround") {
		RECT rc;
		if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			right = true;
		}
	}
	if (other->m_Tag == "UGround") {
		RECT rc;
		if (IntersectRect(&rc, &m_Up->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			up = true;
		}
	}
	if (other->m_Tag == "DGround") {
		RECT rc;
		if (IntersectRect(&rc, &m_Down->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			down = true;
		}
	}
	
}
