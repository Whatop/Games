#pragma once
class TestScene : public Scene
{
	LineMgr* m_Line;
	TextMgr* m_Text;
	SoundMgr* m_TSBgm;
	float rtime;
	float btime;
	float randomx;
	float randomy;
	int Count;
	int direction;
	int test;
	bool one;
	int random;
	bool brandom;
public:
	TestScene();
	~TestScene();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};
