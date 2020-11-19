#pragma once
class Solids : public Object
{
private:
	Sprite* m_Solids;

public:
	Solids(std::wstring fileName, Vec2 Pos);
	~Solids();

	Vec2 Pos;

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};
