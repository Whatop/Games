#pragma once
class MainScene : public Scene
{
	Sprite* m_BG;

	TextMgr* m_Text;
	Vec2 PlayerPos;
	SoundMgr* m_test1;
	SoundMgr* m_test2;
public:	
	MainScene();
	~MainScene();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

