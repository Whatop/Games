#pragma once
class Player_Attack : public Object
{
	Animation* m_Attack;

public:
	Player_Attack(std::wstring fileName, Vec2 pos, int speed, int end, bool LastDireIsRight);
	~Player_Attack();

	Vec2 m_Dir;
	float m_Speed;
	float timer;
	Vec2 m_Arrive;
	float m_Angle;
	bool m_LastDireIsRight;
	int m_End;
	int num;
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};


