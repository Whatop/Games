#pragma once
enum class scene
{
	mainscene,
	dialogscene,
	battlescene,
	testscene,
	start,
	end,
	none
};
enum class Interaction {
	MOVE,
	NONE
};

#define _left 0
#define _right 1
#define _up 2
#define _down 3

class SceneDirector : public Singleton<SceneDirector>
{
	Scene* m_CurrentScene;
public:
	scene m_scene;
	Interaction m_Move;
	SceneDirector();
	~SceneDirector();

	void ChangeScene(Scene* newScene);
	void SetScene(scene scene);
	scene GetScene() {return m_scene;}

	void Update(float deltaTime, float time);
	void Render();

};

