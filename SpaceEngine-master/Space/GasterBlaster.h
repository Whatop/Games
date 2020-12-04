#pragma once
class GasterBlaster : public Object
{

public:
	GasterBlaster();
	~GasterBlaster();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};