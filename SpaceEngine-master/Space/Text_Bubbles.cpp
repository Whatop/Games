#include "stdafx.h"
#include "Text_Bubbles.h"

Text_Bubbles::Text_Bubbles(Vec2 Pos)
{
	m_Text_Bubbles = Sprite::Create(L"Painting/sans/TextBubble.png");
	m_Text_Bubbles->SetParent(this);

	SetPosition(Pos.x,Pos.y-m_Text_Bubbles->m_Size.y);

	m_Expression = Sprite::Create(L"Painting/sans/sans_head.png");
	m_Expression->m_Position = m_Position;

	m_Text = new TextMgr();
	m_Text->Init(60, true, false, L"Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);

}

Text_Bubbles::~Text_Bubbles()
{
}

void Text_Bubbles::Update(float deltaTime, float Time)
{
	m_Expression->m_Position = Vec2(m_Position.x + m_Expression->m_Size.x/2,m_Position.y + m_Expression->m_Size.y/2);
}

void Text_Bubbles::Render()
{
	m_Text_Bubbles->Render();
	m_Expression->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("* 그냥 본론으로 \n 들어가자구.", m_Position.x + m_Expression->m_Size.x, m_Expression->m_Size.y);
	Renderer::GetInst()->GetSprite()->End();
}
