#include"stdafx.h"
#include"Sprite.h"
#include"Texture.h"
#include"ResourceMgr.h"

Sprite::Sprite()
	: m_pSp(Renderer::GetInst()->GetSprite())
{
	m_pSp->AddRef();
	SetRect(&m_Rect, 0, 0, 0, 0);
	A = 255;
	R = 255;
	G = 255;
	B = 255;
}

Sprite::~Sprite()
{
}

bool Sprite::Init(std::wstring fileName, D3DCOLOR ColorKey)
{
	m_Texture = ResourceMgr::GetInst()->CreateTextureFromFile(fileName, ColorKey);
	if (m_Texture)
	{
		m_Size = m_Texture->GetSize();
		SetRect(&m_Rect, 0, 0, static_cast<int>(m_Size.x), static_cast<int>(m_Size.y));
		return true;
	}
	else
		return false;
}

Sprite* Sprite::Create(std::wstring fileName, D3DCOLOR ColorKey)
{
	auto sprite = new (std::nothrow) Sprite();
	if (sprite && sprite->Init(fileName, ColorKey))
	{
		return sprite;
	}
	else
	{
		SafeDelete(sprite);
		return nullptr;
	}
}



void Sprite::Render()
{
	
	if (m_Parent)
	{
		if (m_Parent->m_Tag == "Soul" ||m_Parent->m_Tag == "Bone" || m_Parent->m_Tag == "BlueBone" || m_Parent->m_Tag == "GasterBlaster" || m_Parent->m_Tag == "Platform")
		{
			SetRect(&m_Parent->m_Collision, m_Parent->m_Position.x - m_Size.x/2, m_Parent->m_Position.y - m_Size.y/2,
											m_Parent->m_Position.x + m_Size.x/2 , m_Parent->m_Position.y + m_Size.y/2);
		}
		else{
			SetRect(&m_Parent->m_Collision, m_Parent->m_Position.x - m_Size.x / 2, m_Parent->m_Position.y - m_Size.y,
				m_Parent->m_Position.x + m_Size.x, m_Parent->m_Position.y + m_Size.y);
		}
		m_Parent->m_Size = m_Size;
	}
	else
	{
		SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.y / 2,
			m_Position.x + m_Size.x / 2, m_Position.y + m_Size.y / 2);
	}
	Camera::GetInst()->Render();
	m_pSp->Begin(D3DXSPRITE_ALPHABLEND);

	Matrix transForm = Camera::GetInst()->GetWorld() * GetMatrix();
	if (m_Tag == "UI")
		transForm = GetMatrix();
	else
		transForm = Camera::GetInst()->GetWorld() * GetMatrix();

	m_pSp->SetTransform(&transForm);

	D3DXVECTOR3 center = D3DXVECTOR3(m_Size.x / 2, m_Size.y / 2, 0);

	if (m_Visible == false)
		m_pSp->Draw(m_Texture->GetTexture(), &m_Rect, &center, 0, D3DCOLOR_ARGB(0, R, G, B));
	else
		m_pSp->Draw(m_Texture->GetTexture(), &m_Rect, &center, 0, D3DCOLOR_ARGB(A, R, G, B));

	m_pSp->End();
}