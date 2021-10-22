#pragma once
enum class MouseShape {
	BONESMALL,
	BONE,
	BONEBIG,
	BONELONG,
	BONELIE,
	PLATFORM,
	GASTERBALSTER,
	none
};
class Texture;
class Game : public Singleton<Game>
{
private:
	D3DLOCKED_RECT m_CollisionMapRect;
	DWORD* m_MapColor;

public:
	Game();
	~Game();

	bool m_Puase;
	int shape;
	int Rotae;
	int Dir;

	bool m_isCreateUI;
	bool m_DebugMode;

	void Init();
	void Release();

	bool Color;
	
	int Count;

	bool isCount;
	float DelayCount;

	void CollisionMapInit(Sprite* cMap);

	void CreateUI();
	void ReleaseUI();
	void Shape(bool dir); // 마우스 모양 바꾸는 기능
	void Rota(bool dir); // 마우스 모양 바꾸는 기능

	void Update();
	void Render();

	MouseShape m_MouseShape;

	DWORD GetMapColor(int pos) { return m_MapColor[pos]; }
	D3DLOCKED_RECT GetCollisionMapRect() { return m_CollisionMapRect; }

};

