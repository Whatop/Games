#include "stdafx.h"
#include "GameOver.h"

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::Init()
{
	m_BG = Sprite::Create(L"Painting/GameOver.png");
	m_BG->SetPosition(0, 0);

}

void GameOver::Release()
{
}

void GameOver::Update(float deltaTime, float time)
{
}

void GameOver::Render()
{
	m_BG->Render();
}
