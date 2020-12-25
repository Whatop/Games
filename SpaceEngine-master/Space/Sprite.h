#pragma once
#define COLORKEY_PURPLE D3DCOLOR_XRGB(88, 64, 172)
#define COLORKEY_GASTER D3DCOLOR_XRGB(195, 134, 255)
#define COLORKEY_PINK D3DCOLOR_XRGB(255, 102, 255)
//#define COLORKEY_SKY D3DCOLOR_XRGB(75, 169, 218)
#define COLORKEY_WHITE D3DCOLOR_XRGB(255,255,255)
#define COLORKEY_BALCK D3DCOLOR_XRGB(0,0,0)
//#define COLORKEY_GREEN D3DCOLOR_XRGB(182,255,0)

class Texture;
class Sprite : public Object
{
	LPD3DXSPRITE m_pSp;
	Texture* m_Texture;


public:
	Sprite();
	~Sprite();
	RECT m_Rect;
public:
	bool Init(std::wstring fileName, D3DCOLOR ColorKey);

public:
	Texture* GetSpriteTexture() { return m_Texture; }
	static Sprite* Create(std::wstring fileName, D3DCOLOR ColorKey = COLORKEY_PINK);
	void Render() override;

public:
	int A, R, G, B;
};