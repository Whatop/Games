#pragma once
enum class Player_Color {
	RED,
	BULE,
	NONE
};

class Heart : public Object
{
	Sprite* m_red;
	Player_Color m_Color;
public:
	Heart(Vec2 Pos);
	~Heart();

	void Update(float deltaTime, float Time);
	void Render();	
	void OnCollision(Object* other);

};

