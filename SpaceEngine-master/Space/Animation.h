#pragma once
constexpr int BigImage = 0;
constexpr int MultipleImage = 1;

class Texture;
class Animation : public Object
{
private:
	Sprite* m_Anim;
	std::vector<Sprite*>m_Anims;

	float m_Delay;
	bool m_AutoPlay;
	float m_FrameCount;

	int m_FirstFrame;
	int m_LastFrame;

	int m_AnimationMode;

public:
	int m_CurrentFrame;
	int A, R, G, B;

public:
	Animation();
	~Animation();

	void AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame, D3DXCOLOR ColorKey = COLORKEY_PINK);

	void Init(float delay, bool play, int Mode);
	void Update(float deltaTime, float time);
	void Render();
};

