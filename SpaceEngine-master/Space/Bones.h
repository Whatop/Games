#pragma once
class Bones : public Object
{

public:
	Bones();
	~Bones();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

