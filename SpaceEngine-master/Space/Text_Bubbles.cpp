#include "stdafx.h"
#include "Text_Bubbles.h"

Text_Bubbles::Text_Bubbles(Vec2 Pos)
{
	SoundMgr::Init();
	m_Text_Bubbles = Sprite::Create(L"Painting/sans/TextBubble.png",COLORKEY_BALCK);
	m_Text_Bubbles->SetParent(this);

	SetPosition(Pos.x,Pos.y-m_Text_Bubbles->m_Size.y-10);

	m_Expression = Sprite::Create(L"Painting/sans/sans_head.png");
	m_Expression->m_Position = m_Position;
	m_RText = new SoundMgr("Sound/Word/Word1.mp3", false);
	m_RText->play();
}

Text_Bubbles::~Text_Bubbles()
{
}

void Text_Bubbles::Update(float deltaTime, float Time)
{
	m_RText->Update(deltaTime, Time);
	m_Expression->m_Position = Vec2(m_Position.x + m_Expression->m_Size.x/2,m_Position.y + m_Expression->m_Size.y/2-20);
}

void Text_Bubbles::Render()
{
	m_Text_Bubbles->Render();
	m_Expression->Render();
}
