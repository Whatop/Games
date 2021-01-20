#pragma once
class Laser : public Object
{
	Animation* m_Laser;
	Sprite* m_ColBox;

	float Add;
	int m_direction;
	float m_Speed;
	float rTime;
public:
	Laser(Vec2 Pos, float Rotation, int direction);
	~Laser();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object obj);
};

