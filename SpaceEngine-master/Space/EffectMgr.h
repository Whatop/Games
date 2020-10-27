#pragma once
class EffectMgr : public Object
{
	Animation* Effect;
public:
	EffectMgr(std::wstring filename, int start, int end, float speed, int type, Vec2 Pos);
	~EffectMgr();

	int Start;
	int End;

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

