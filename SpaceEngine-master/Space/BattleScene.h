#pragma once
class BattleScene : public Scene
{
	Sprite* m_BG;
	Sprite* m_Frame;

	TextMgr* m_Text;
	Vec2 PlayerPos;
	LineMgr* m_StartLine;
public:
	BattleScene();
	~BattleScene();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};

