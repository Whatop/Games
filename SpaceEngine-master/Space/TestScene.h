#pragma once
class TestScene : public Scene
{
	TextMgr* m_Text;
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
