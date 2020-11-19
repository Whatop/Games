#pragma once
class Save : public Object
{
	Animation* m_Save;
	Sprite* m_ColBox;
public:
	Save(Vec2 Pos);
	~Save();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

