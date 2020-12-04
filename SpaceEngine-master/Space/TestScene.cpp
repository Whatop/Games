#include "stdafx.h"
#include "TestScene.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::Init()
{
	SceneDirector::GetInst()->SetScene(scene::testscene);
}

void TestScene::Release()
{
}

void TestScene::Update(float deltaTime, float time)
{
}

void TestScene::Render()
{
}
