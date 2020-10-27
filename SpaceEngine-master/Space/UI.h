#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_Time;
	Sprite* m_PlayerFrame;
	Sprite* m_HpBar;
	Sprite* m_1Up;

public:
	UI();
	~UI();

	void Init();
	void Release();

	void Update();
	void Render();
};

