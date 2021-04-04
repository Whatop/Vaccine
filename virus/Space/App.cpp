#include "stdafx.h"
#include "App.h"

App::App()
{
}


App::~App()
{
}
bool App::Init(int width, int height, bool windowMode)
{
	m_Width = width;
	m_Height = height;
	m_WindowMode = windowMode;


	if (!_CreateWindow())
		return false;

	if (!_CreateRenderer())
		return false;

	Time = 0.0f;
	return true;
}

void App::Run()
{
	srand(time(NULL));
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT)
	{
		static DWORD lastTime = timeGetTime();
		static float fps = 0.f;

		DWORD curTime = timeGetTime();
		float timeDelta = float(curTime - lastTime) * 0.001;
		fps = 1000.f / float(curTime - lastTime);

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Renderer::GetInst()->Begin();
		INPUT->Update();
			if (INPUT->GetKey(VK_F8) == KeyState::DOWN)
			{
				if (m_Pause)
					m_Pause = false;
				else if (!m_Pause)
					m_Pause = true;
			}
			if (!m_Pause)
			{
				SceneDirector::GetInst()->Update(timeDelta, Time);
			}
			SceneDirector::GetInst()->Render();
			Renderer::GetInst()->End();

			DeltaTime = timeDelta;
			Time += timeDelta;
			lastTime = curTime;

			if (GetAsyncKeyState(VK_ESCAPE))
			{
				App::GetInst()->Release();
				exit(0);
			}
			if (INPUT->GetKey(VK_F4) == KeyState::DOWN) // 메뉴화면 이동
			{
				SceneDirector::GetInst()->SetScene(SceneState::MENU);
				ObjMgr->AddObject(new Loading(0), "SceneChange");
				std::cout << "메뉴로이동" << std::endl;
			}
			else if (INPUT->GetKey(VK_F5) == KeyState::DOWN) // 스테이지 1 이동
			{
				SceneDirector::GetInst()->SetScene(SceneState::STAGE1);
				ObjMgr->AddObject(new Loading(0), "SceneChange");
				std::cout << "1로이동" << std::endl;
			}
			else if (INPUT->GetKey(VK_F6) == KeyState::DOWN) // 스테이지 2 이동
			{
				SceneDirector::GetInst()->SetScene(SceneState::STAGE2);
				ObjMgr->AddObject(new Loading(0), "SceneChange");
				std::cout << "2로이동" << std::endl;
			}
			else if (INPUT->GetKey(VK_F7) == KeyState::DOWN) // 스테이지 2 이동
			{
				SceneDirector::GetInst()->SetScene(SceneState::ENDING);
				ObjMgr->AddObject(new Loading(0), "SceneChange");
				std::cout << "엔딩으로" << std::endl;
			}
			

		}
	}

}

void App::Release()
{
	FreeConsole();
	Renderer::GetInst()->Release();
	ObjMgr->Release();
}

LRESULT App::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		INPUT->ButtonDown(true);
		break;
	case WM_LBUTTONUP:
		INPUT->ButtonDown(false);
		break;
	case WM_RBUTTONDOWN:
		INPUT->RightButtonDown(true);
		break;
	case WM_RBUTTONUP:
		INPUT->RightButtonDown(false);
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

bool App::_CreateWindow()
{
	WNDCLASS wc = {};
	wc.lpszClassName = L"Space";
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.lpfnWndProc = WndProc;

	RegisterClass(&wc);

	DWORD Style = 0;

	if (m_WindowMode)
		Style = WS_OVERLAPPEDWINDOW;
	else
		Style = WS_POPUP | WS_EX_TOPMOST;

	HWND hWnd = CreateWindow(wc.lpszClassName, wc.lpszClassName, Style, 0, 0, m_Width, m_Height, 0, 0, 0, 0);
	if (hWnd)
		m_Hwnd = hWnd;
	else
		return false;

	ShowWindow(m_Hwnd, SW_SHOWDEFAULT);


	return true;
}

bool App::_CreateRenderer()
{
	if (!(Renderer::GetInst()->Init(m_Width, m_Height, m_WindowMode)))
		return false;

	return true;
}