#pragma once
class TestScene : public Scene
{
	LineMgr* m_Line;
	TextMgr* m_Text;
	SoundMgr* m_TSBgm;

	Sprite* StopButton;
	Sprite* ResumeButton;
	Sprite* TempButton;

	Sprite* DirButton[5];
	Sprite* ActButton[8];
	Sprite* Mouse;
	std::string m_Name;
	std::string m_Mode;

	bool m_Puase;
	float rtime;
	float btime;
	float dtime;
	float randomx;
	float randomy;
	int Count;
	int direction;
	int test;
	bool one;
	int random;
	bool brandom;
	bool Mode;
public:
	TestScene();
	~TestScene();

	void Init();
	void Release();
	void Button();

	void Update(float deltaTime, float time);
	void Render();
};
