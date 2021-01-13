#pragma once
class GasterBlaster : public Object
{
	Sprite* m_ColBox;
	Animation* m_GBlaster;
	SoundMgr* m_gasterblaster;
	Vec2 A, B, C, Dir;
	float m_Speed;

	bool ntRange;

	float lifeTime;
	float rTime;
public:
	GasterBlaster(Vec2 Pos);
	~GasterBlaster();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};