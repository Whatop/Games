#pragma once
class TestScene : public Scene
{
	float rtime;
	TextMgr* m_Text;
public:
	TestScene();
	~TestScene();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};