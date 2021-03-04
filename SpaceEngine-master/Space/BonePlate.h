#pragma once
class BonePlate : public Object
{
	Sprite* m_BonePlate;
public:
	BonePlate(Vec2 Pos);
	~BonePlate();

	void Update(float deltaTime, float Time);
	void Render();

};

