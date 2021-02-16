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
	JUMP,
	NONE																							
};
class Heart : public Object
{
	Sprite* m_red;
	Sprite* m_ColBox;
	Soul_Color m_Color;
	Soul_Movement m_Move;
	bool a;
	bool f;
	Vec2 Dir;
	SoundMgr* m_Bgm;
	SoundMgr* m_Start																																										;
	Vec2 Pos;
	float m_Speed;
	int m_Hp;
	int m_limit;

	float m_JumpTime;
	float JTime; //점프 강도 정해주는 시간

	bool m_isFall;
	bool m_isGround;
	int m_Gravity;

	
	TextMgr* m_Text;
public:
	Heart(Vec2 Pos);
	~Heart();

	float stime;
	float mtime;
	float atime;
	void Update(float deltaTime, float Time);
	void Render();	
	void OnCollision(Object* other);

	void Gravity();
	void Move();
};

