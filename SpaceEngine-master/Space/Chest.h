#pragma once
class Chest : public Object
{
	Sprite* m_Chest;
public:
	Chest(Vec2 Pos);
	~Chest();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

