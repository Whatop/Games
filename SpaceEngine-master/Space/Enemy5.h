#pragma once 
class Enemy5 : public Object
{
	Animation* m_Archer;

	Animation* m_Attack_A;
	Animation* m_Attack_B;

	Animation* m_Dead;

	Animation* m_Hit;

	Animation* m_Idle;

	Animation* m_Jump;

	Animation* m_Run;

	Sprite* m_ColBox;
	Sprite* m_HeadCol;
	Sprite* m_FootCol;
	Sprite* m_Left;
	Sprite* m_Right;

public:
	Vec2 m_Directon;
	int m_LandAngle;
	int m_BaseAngle;

	EnemyStatus m_EnemyStatus5;

	float m_Speed;
	int m_Hp;
	int m_MaxHp;

	Vec2 Pos;

	Vec2 PlayerPos;

	bool m_LastDireIsRight;
	float m_AttackLate;

	bool m_RightCol;
	bool m_LeftCol;

	Vec2 m_JumpPos;
	float m_JumpTime;
	float m_JumpPower;
	float m_JumpAccel;
	float m_PrevAccel;
	float m_JumpLate;

	bool m_isFall;
	bool m_isGround;

	Enemy5();
	~Enemy5();

	void Move();
	void Attack();
	void Jump();

	void SetLookingDirection();
	void Gravity();
	void SetDirection();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

	