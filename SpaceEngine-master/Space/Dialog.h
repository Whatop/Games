#pragma once
class Dialog : public Object
{
public:
	Sprite* m_Dialog;
public:
	Dialog(Vec2 Pos);
	~Dialog();

	Vec2 Pos;

	float m_Speed;

	void Move();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};