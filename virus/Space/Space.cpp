#include"stdafx.h"
#include"IntroScene.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "wt", stdout);

#endif
	GameMgr::GetInst()->Init();
	GameMgr::GetInst()->RankInit();
	App::GetInst()->Init(1920, 1080, 1);
	SceneDirector::GetInst()->ChangeScene(new IntroScene());
	App::GetInst()->Run();
	return 0;
}