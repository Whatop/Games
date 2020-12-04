#pragma once
class GameOver : public Scene
{
	Sprite* m_BG;
public:
	GameOver();
	~GameOver();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};

