#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_Curtain;
	Sprite* m_Pillar;
	TextMgr* m_Text;
	Vec2 PlayerPos;
public:
	UI();
	~UI();

	float ztime;
	float ptime;
	bool a;
	bool b;
	float m_Pos;
	void Init();
	void Release();

	void Update();
	void Render();
};

