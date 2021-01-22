#pragma once
class Player : public Object
{
public:
	Animation* m_Player;
	Animation* m_Player_Left;
	Animation* m_Player_Right;
	Animation* m_Player_Down;
	Animation* m_Player_Up;

	Sprite* m_ColBox;
	Sprite* m_Left;
	Sprite* m_Right;
	Sprite* m_Up;
	Sprite* m_Down;

	Status m_Status;

	scene m_scene;

	LineMgr* m_Line;
public:
	Player();
	~Player();

	Vec2 Pos;

	float m_Speed;

	bool Right;
	bool Left;
	bool Up;
	bool Down;

	bool Chest;
	bool Save;
	bool State;

	void Move(float deltaTime, float Time);

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};