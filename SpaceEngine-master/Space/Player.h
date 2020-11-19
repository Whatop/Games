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

	Sprite* m_red;
	Sprite* m_blue;
	scene m_scene;

	Sprite* m_Soul_ColBox;
	Sprite* m_Soul_Left;
	Sprite* m_Soul_Right;
	Sprite* m_Soul_Up;
	Sprite* m_Soul_Down;

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

	void SetDirection();

	void Move(float deltaTime, float Time);

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};