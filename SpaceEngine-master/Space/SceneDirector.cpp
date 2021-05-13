#include "stdafx.h"
#include "SceneDirector.h"
#include "UI.h"


SceneDirector::SceneDirector()
{
}


SceneDirector::~SceneDirector()
{
}

void SceneDirector::ChangeScene(Scene* newScene)
{
	if (m_CurrentScene)
	{
		m_CurrentScene->Release();
		SafeDelete(m_CurrentScene);
	}

	m_CurrentScene = newScene;
	m_CurrentScene->Init();
}

void SceneDirector::SetScene(scene scene)
{
	m_scene = scene;
}

void SceneDirector::Update(float deltaTime, float time)
{
	Camera::GetInst()->Update(deltaTime, time);
	Input::GetInst()->Update();

	if (m_CurrentScene)
		m_CurrentScene->Update(deltaTime, time);

	ObjMgr->Update(deltaTime, time);

	if(Game::GetInst()->m_isCreateUI)
		UI::GetInst()->Update();
}

void SceneDirector::Render()
{
	if (m_CurrentScene)
		m_CurrentScene->Render();
	ObjMgr->Render();

	if (Game::GetInst()->m_isCreateUI)
		UI::GetInst()->Render();
}
