#pragma once
class MainScene : public Scene
{
	Sprite* m_BG;
	Sprite* m_Pillar;

	TextMgr* m_Text;
	Vec2 PlayerPos;
	
public:
	MainScene();
	~MainScene();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

