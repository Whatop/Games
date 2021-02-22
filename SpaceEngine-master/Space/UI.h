#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_UI;
	Sprite* m_Curtain;
	Sprite* m_Pillar;
	Sprite* m_HpBar;
	Sprite* m_SpHp;
	Sprite* m_Poison;

	TextMgr* m_Text;
	Vec2 PlayerPos;
	std::string UpdateText;
public:
	UI();
	~UI();

	float textTime;
	float ztime;
	float ptime;
	float m_HpGage;
	bool a;
	bool b;
	bool c;
	bool d;
	float m_Pos;
	int m_Hp;
	void Init();
	void Release();

	void Update();
	void Render();
};

