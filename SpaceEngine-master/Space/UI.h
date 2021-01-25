#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_Curtain;
	Sprite* m_Pillar;
	TextMgr* m_Text;
	Vec2 PlayerPos;
	std::string UpdateText;
public:
	UI();
	~UI();

	float textTime;
	float ztime;
	float ptime;
	bool a;
	bool b;
	bool c;
	bool d;
	float m_Pos;
	void Init();
	void Release();

	void Update();
	void Render();
};

