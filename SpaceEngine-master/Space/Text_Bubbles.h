#pragma once
class Text_Bubbles : public Object
{
	Sprite* m_Text_Bubbles;
	Sprite* m_Expression;
	TextMgr* m_Text;
public:
	Text_Bubbles(Vec2 Pos);
	~Text_Bubbles();

	void Update(float deltaTime, float Time);
	void Render();
};

