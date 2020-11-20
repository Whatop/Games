#pragma once
class Pillar : public Object
{
	Sprite* m_Pillar;
	TextMgr* m_Text;
public:
	Pillar(Vec2 Pos);
	~Pillar();

	Vec2 Pos;
	float m_Speed;
	float m_Pos;
	float ptime;
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};