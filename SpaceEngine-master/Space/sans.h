#pragma once
class sans : public Object
{
public:
	Sprite* m_ColBox;
public:
	sans(Vec2 Pos);
	~sans();

	Vec2 Pos;

	float m_Speed;
	bool one;
	void Move();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};