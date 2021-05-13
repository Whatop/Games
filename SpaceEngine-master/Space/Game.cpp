#include "stdafx.h"
#include "Game.h"
#include"Texture.h"
#include"UI.h"

Game::Game()
{
	ZeroMemory(&m_CollisionMapRect, sizeof(m_CollisionMapRect));
}

Game::~Game()
{
}

void Game::Init()
{
	shape = 7;
	m_isCreateUI = false;
	m_DebugMode = false;
	m_Puase = true; 
	Game::GetInst()->m_MouseShape = MouseShape::none;
}

void Game::Release()
{
}

void Game::CollisionMapInit(Sprite* cMap)
{
	cMap->GetSpriteTexture()->GetTexture()->LockRect(0, &m_CollisionMapRect, 0, 0);
	m_MapColor = (DWORD*)m_CollisionMapRect.pBits;
	cMap->GetSpriteTexture()->GetTexture()->UnlockRect(0);
}

void Game::CreateUI()
{
	UI::GetInst()->Init();
	m_isCreateUI = true;
}

void Game::ReleaseUI()
{
	UI::GetInst()->Release();
	UI::GetInst()->ReleaseInst();
	m_isCreateUI = false;
}

void Game::Shape(bool dir)
{
	if (dir) {
		if (shape >= 7) {
			shape = 1;
		}
		else {
			shape++;
		}
	}
	else if (!dir) {
		if (shape <= 1) {
			shape = 7;
		}
		else {
			shape--;
		}
	}
	if (shape == 1) {
		m_MouseShape = MouseShape::BONESMALL;
	}
	else if (shape == 2) {
		m_MouseShape = MouseShape::BONE;
	}
	else if (shape == 3) {
		m_MouseShape = MouseShape::BONEBIG;
	}
	else if (shape == 4) {
		m_MouseShape = MouseShape::BONELONG;
	}
	else if (shape == 5) {
		m_MouseShape = MouseShape::BONELIE;
	}
	else if (shape == 6) {
		m_MouseShape = MouseShape::PLATFORM;
	}
	else if (shape == 7) {
		m_MouseShape = MouseShape::GASTERBALSTER;
	}
}
void Game::Rota(bool dir)
{
	if (dir) {
		if (Rotae >= 4) {
			Rotae = 1;
		}
		else {
			Rotae++;
		}
	}
	else if (!dir) {
		if (Rotae <= 1) {
			Rotae = 4;
		}
		else {
			Rotae--;
		}
	}
	if (Rotae == 1) {
		Dir = _left;
	}
	else if (Rotae == 2) {
		Dir = _right;
	}
	else if (Rotae == 3) {
		Dir = _up;
	}
	else if (Rotae == 4) {
		Dir = _down;
	}
}
void Game::Update()
{
	if (INPUT->GetKey('V') == KeyState::DOWN)
	{
		if (m_DebugMode)
			m_DebugMode = false;
		else
			m_DebugMode = true;
	}

	if (m_isCreateUI)
		UI::GetInst()->Update();
}

void Game::Render()
{
	if (m_isCreateUI)
		UI::GetInst()->Render();
}
