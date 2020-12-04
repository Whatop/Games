#pragma once
enum class Soul_Color {
	RED,
	BULE,
	NONE
};

enum class Soul_Movement {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	NONE
};
class Heart : public Object
{
	Sprite* m_red;
	Soul_Color m_Color;
	Soul_Movement m_Move;
	bool a;
	Vec2 Dir;

	float m_Speed;
	int m_Hp;
public:
	Heart(Vec2 Pos);
	~Heart();

	float stime;
	float mtime;
	float atime;
	void Update(float deltaTime, float Time);
	void Render();	
	void OnCollision(Object* other);

	void Move();
};

