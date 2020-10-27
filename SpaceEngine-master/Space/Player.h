#pragma once
class Player : public Object
{
public:
	Sprite* m_ColBox;
	Sprite* m_red;
	Sprite* m_blue;
	scene m_scene;

	Sprite* m_Left;
	Sprite* m_Right;
	Sprite* m_Up;
	Sprite* m_Down;
public:
	Player();
	~Player();

	Vec2 Pos;

	float m_Speed;

	void Move();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};