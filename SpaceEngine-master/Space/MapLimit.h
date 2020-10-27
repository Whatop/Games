#pragma once
constexpr int HORIZONTAL = 0;
constexpr int VERTICAL = 1;
class MapLimit : public Singleton<MapLimit>
{
public:
	MapLimit();
	~MapLimit();

	Vec2 m_Pos;

	void CreateMap(int Dire, int Count, Vec2 Pos);
};

