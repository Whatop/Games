#pragma once
#define LEFT 0
#define RIGHT 1
class GasterBlaster : public Object
{
	Sprite* m_ColBox;
	Animation* m_GBlaster;
	SoundMgr* m_gasterblaster;
	Vec2 A, B, C, location;
	Vec2 Pos;
	float m_Speed;

	bool ntRange;
	int m_direction;
	float lifeTime;
	float rTime;
public:
	GasterBlaster(Vec2 Pos, int direction);
	~GasterBlaster();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};