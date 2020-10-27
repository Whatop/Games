#pragma once
class Bullet : public Object
{
	Animation * m_Attack;
	Sprite* m_Bullet;
	
public:
	//					�����̸�
	//				L"Painting/Player/~~",   Name,   m_Position,   ����,������
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

