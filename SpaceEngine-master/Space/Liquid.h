#pragma once
class Liquid : public Object
{
	Sprite* m_Liquid;
public:
	Liquid();
	~Liquid();

	Vec2 m_Arrive;
	float m_Angle;

	Vec2 m_Directon;
	int m_LandAngle;
	int m_BaseAngle;

	bool m_isFall;
	bool m_isGround;
	bool m_LastDireIsRight;

	void Move();

	void Gravity();
	void SetDirection();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

	