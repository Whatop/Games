#pragma once

class Interaction1 : public Object
{
	Animation* m_Save;
	Animation* m_State;
	Animation* m_Chest;
	Animation* m_Interaction;
public:
	float delayTime;
	Interaction1(Vec2 Pos,std::string string);
	~Interaction1();

	void Update(float deltaTime, float Time);
	void Render();
	
};

