#pragma once
class Camera : public Singleton<Camera>
{
private:
	Matrix mRot;
	Matrix mTrans;
	Matrix mScale;
	Matrix mWorld;

	float ptime;
	float m_Pos;
public:
	Camera();
	~Camera();


	float m_Rotation;
	Vec2 m_Position;
	Vec2 m_Scale;

	Vec2 m_MinMapSize;
	Vec2 m_MaxMapSize;

	Matrix GetWorld()
	{
		return mWorld;
	}

	void Init();
	void Translate();
	void SetPos(float x);
	void Follow(Object* obj);
	void Update(float deltaTime, float time);
	void Render();
};
