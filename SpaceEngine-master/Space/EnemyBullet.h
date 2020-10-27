#pragma once

class EnemyBullet : public Object
{
	Sprite* m_Bullet;
public:
	EnemyBullet(Vec2 pos,float R);
	~EnemyBullet();
	float t;
	Vec2 m_Dir;
	float m_Speed;
	Vec2 m_Arrive;
	float m_Angle;
	
	float R;
	float U;
	float V;
	float W;
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

