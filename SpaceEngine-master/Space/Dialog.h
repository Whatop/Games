#pragma once
class Dialog : public Object
{
private:
	Sprite* m_Dialog;
	TextMgr* m_Text;
public:
	Dialog(Vec2 Pos);
	~Dialog();

	Vec2 Pos;

	float m_Speed;

	void Move();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};