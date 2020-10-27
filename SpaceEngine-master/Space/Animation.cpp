#include "stdafx.h"
#include"Texture.h"
#include "Animation.h"

Animation::Animation()
	: m_AutoPlay(0)
	, m_CurrentFrame(1)
	, m_Delay(0.f)
	, m_FrameCount(0.f)
	, m_FirstFrame(1)
	, m_LastFrame(1)
	, A(255)
	, R(255)
	, G(255)
	, B(255)
{
}

Animation::~Animation()
{
}

void Animation::AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame, D3DXCOLOR ColorKey)
{
	if (m_AnimationMode == BigImage)
	{
		m_Anim = Sprite::Create(fileName.c_str(), ColorKey);
		m_Anim->SetParent(this);
	}
	else if (m_AnimationMode == MultipleImage)
	{
		for (int i = firstFrame; i <= lastFrame; i++)
		{
			Sprite* sprite = Sprite::Create(fileName.c_str() + std::to_wstring(i) + L".png", ColorKey);
			sprite->SetParent(this);
			if (sprite)
				m_Anims.push_back(sprite);
		}
	}
	m_FirstFrame = firstFrame;
	m_LastFrame = lastFrame;
}

void Animation::Init(float delay, bool play, int Mode)
{
	m_Delay = delay;
	m_AutoPlay = play;
	m_AnimationMode = Mode;
}

void Animation::Update(float deltaTime, float time)
{
	m_FrameCount += dt;

	if (m_Destroy)
	{
		if (m_AnimationMode == BigImage)
			SetDestroy(true);
		if (m_AnimationMode == MultipleImage)
			m_Anims.at(m_CurrentFrame)->SetDestroy(true);
	}

	if (m_AutoPlay == true)
	{
		if (m_FrameCount > m_Delay)
		{
			m_CurrentFrame++;
			m_FrameCount = 0.f;
		}
	}
	if (m_CurrentFrame > m_LastFrame)
	{
		m_CurrentFrame = 1;
	}

	if (m_AnimationMode == MultipleImage)
	{
		m_Anims.at(m_CurrentFrame)->A = A;
		m_Anims.at(m_CurrentFrame)->R = R;
		m_Anims.at(m_CurrentFrame)->G = G;
		m_Anims.at(m_CurrentFrame)->B = B;
	}

	if (m_AnimationMode == BigImage)
		m_Anim->Update(deltaTime, time);
	if (m_AnimationMode == MultipleImage)
		m_Anims.at(m_CurrentFrame)->Update(deltaTime, time);
}

void Animation::Render()
{
	if (m_AnimationMode == BigImage)
		m_Anim->Render();
	if (m_AnimationMode == MultipleImage)
		m_Anims.at(m_CurrentFrame)->Render();

	if (m_Parent)
	{
		SetRect(&m_Parent->m_Collision, m_Parent->m_Position.x - m_Size.x / 2, m_Parent->m_Position.y - m_Size.y / 2,
			m_Parent->m_Position.x + m_Size.x / 2, m_Parent->m_Position.y + m_Size.y / 2);

		m_Parent->m_Size = m_Size;
	}
	else
	{
		SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.y / 2,
			m_Position.x + m_Size.x / 2, m_Position.y + m_Size.y / 2);
	}

	if (m_AnimationMode == BigImage)
	{
		SetRect(&m_Anim->m_Rect, static_cast<int>(m_Size.x / m_LastFrame)* (m_CurrentFrame - 1), 0,
			static_cast<int>(m_Size.x / m_LastFrame)* m_CurrentFrame, static_cast<int>(m_Size.y));

		m_Size.x /= m_LastFrame;

		if (m_Visible == false)
			m_Anim->A = 0;
		else if (m_Visible == true)
			m_Anim->A = 255;
	}
}