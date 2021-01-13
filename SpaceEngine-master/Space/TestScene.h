#pragma once
class TestScene : public Scene
{
	LineMgr* m_Line;
	TextMgr* m_Text;
	SoundMgr* m_TSBgm;
	float rtime;
	float randomx;
	float randomy;
public:
	TestScene();
	~TestScene();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};
