#include"stdafx.h"
#include"IntroScene.h"

#pragma warning(disable:26495)

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "wt", stdout);
#endif
	App::GetInst()->Init(1920, 1080, 1);
	SceneDirector::GetInst()->ChangeScene(new IntroScene());
	App::GetInst()->Run();
	return 0;
}