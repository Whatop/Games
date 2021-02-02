#pragma once
class Bones : public Object
{
	Sprite* m_Bones;
	Sprite* m_ColBox;
	int m_direction;
	float m_Speed;
	float dtime;
public:
	Bones(Vec2 Pos,std::string type, std::string size, int);
	~Bones();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

