#pragma once
class Platform : public Object
{
private:
	Sprite* m_platfrom;
	Sprite* m_pColBox;
	float m_Speed;
	float ptime;
	int m_direction;
public:
	Platform(Vec2,int);
	~Platform();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

