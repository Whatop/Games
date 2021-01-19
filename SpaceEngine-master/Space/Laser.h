#pragma once
class Laser : public Object
{
	Animation* m_Laser;
	Sprite* m_ColBox;

	float Add;
public:
	Laser(Vec2 Pos, float Rotation);
	~Laser();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object obj);
};

