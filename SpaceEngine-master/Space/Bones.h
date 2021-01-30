#pragma once
class Bones : public Object
{
	Sprite* m_Bones;

public:
	Bones(Vec2 Pos,std::string type, std::string size, bool );
	~Bones();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

