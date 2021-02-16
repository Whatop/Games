#pragma once
class Ground : public Object
{
	Sprite* m_Ground;
public:
	Ground(int);
	~Ground();

	
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);

};

