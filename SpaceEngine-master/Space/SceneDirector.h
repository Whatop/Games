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

	void Update(float deltaTime, float time);
	void Render();

};

