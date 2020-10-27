#pragma once
class Barrel : public Object
{
	Animation* Rolling_m_Barrel;

	Sprite* m_Barrel;

	Sprite* m_ColBox;
	Sprite* m_HeadCol;
	Sprite* m_FootCol;
	Sprite* m_Left;
	Sprite* m_Right;
public:	
	Barrel();
	~Barrel();

	std::string m_Name;
	float m_Speed;
	float timer;

	Vec2 m_Arrive;
	float m_Angle;

	Vec2 m_Directon;
	int m_LandAngle;
	int m_BaseAngle;

	bool RightMove;
	bool LeftMove;


	bool m_RightCol;
	bool m_LeftCol;

	bool m_isFall;
	bool m_isGround;
	bool m_LastDireIsRight;

	void Move();

	void SetLookingDirection();
	void Gravity();
	void SetDirection();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

