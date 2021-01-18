#pragma once
class Laser : public Object
{
	Animation* m_Laser;
	Sprite* m_ColBox;

public:
	Laser();
	~Laser();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object obj);
};

