#pragma once
enum class scene
{
	mainscene,
	dialogscene,
	battlescene,
	none
};

class SceneDirector : public Singleton<SceneDirector>
{
	Scene* m_CurrentScene;
public:
	scene m_scene;
	SceneDirector();
	~SceneDirector();

	void ChangeScene(Scene* newScene);
	void SetScene(scene scene);

	void Update(float deltaTime, float time);
	void Render();

};

