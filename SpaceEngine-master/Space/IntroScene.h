#pragma once
class IntroScene : public Scene
{
public:
	Sprite* m_IntroCut1;
	Sprite* m_IntroCut2;
	Sprite* m_IntroCut3;
	Sprite* m_IntroCut4;
	Sprite* m_IntroCut5;
	Sprite* m_IntroCut6;
	Sprite* m_IntroCut7;
	Sprite* m_IntroCut8;
	Sprite* m_IntroCut9;
	Sprite* m_IntroCut10;
	Sprite* m_IntroCut11;
	Sprite* m_IntroCut12;
	Sprite* m_IntroCut13;
	Sprite* m_IntroFrame;

	Sprite* m_Skip;

	SoundMgr* IntroSound;
	SoundMgr* BGIntroSound;


	IntroScene();
	~IntroScene();

	float m_Count;
	float m_Start;
	int m_Cut;
	bool start;
	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};
