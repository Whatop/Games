#pragma once
class Trail : public Object
{
	Sprite* m_Obj;
public:
	Trail(std::wstring fileName, std::string Enemy, Vec2 pos, bool LastDireIsRight);
	~Trail();

	std::string m_Name;
	float timer;

	void Update(float deltaTime, float Time);
	void Render();
};

