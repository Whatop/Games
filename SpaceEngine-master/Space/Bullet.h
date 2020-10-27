#pragma once
class Bullet : public Object
{
	Animation * m_Attack;
	Sprite* m_Bullet;
	
public:
	//					파일이름
	//				L"Painting/Player/~~",   Name,   m_Position,   왼쪽,오른쪽
	Bullet(std::wstring fileName,std::string Enemy,Vec2 pos,bool LastDireIsRight);
	~Bullet();

	std::string m_Name;
	Vec2 m_Dir;
	float m_Speed; 
	float timer;
	Vec2 m_Arrive;
	float m_Angle;

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

