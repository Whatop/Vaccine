#include"stdafx.h"
#include "IntroScene.h"
#include"MainScene.h"
#include"MenuScene.h"

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{

}

void IntroScene::Init()
{
	UI::GetInst()->Init();
	SoundMgr::GetInst()->Play(L"Intro.wav",true);
	m_IntroCut1 = Sprite::Create(L"Painting/Intro/1.png");
	m_IntroCut1->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut2 = Sprite::Create(L"Painting/Intro/2.png");
	m_IntroCut2->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut3 = Sprite::Create(L"Painting/Intro/3.png");
	m_IntroCut3->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut4 = Sprite::Create(L"Painting/Intro/4.png");
	m_IntroCut4->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut4->A = 0;
	m_IntroCut3->A = 0;
	m_IntroCut2->A = 0;

	m_Count = 0;
	m_Cut = 1;
}

void IntroScene::Release()
{
}

void IntroScene::Update(float deltaTime, float time)
{
	m_Count += dt;

	if (m_Count >= 5.f)
	{
		switch (m_Cut)
		{
		case 1:
			m_IntroCut2->A += 5;
			if (m_IntroCut2->A == 255)
			{
				m_Cut = 2;
				m_Count = 0.f;
			}
			break;
		case 2:
			m_IntroCut3->A += 5;
			m_IntroCut4->A = 0;
			if (m_IntroCut3->A == 255)
			{
				m_Cut = 3;
				m_Count = 0.f;
			}
		case 3:
			m_IntroCut4->A += 5;
			if (m_IntroCut4->A == 255)
			{
				m_Cut = 0;
				m_Count = 0.f;

			}
			break;
		}
	}
	if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN)
	{
		SoundMgr::GetInst()->Stop();
		start = true;
		m_IntroCut4->A = 0;
		m_IntroCut3->A = 0;
		m_IntroCut2->A = 0;
		m_IntroCut1->A = 0;
	}
	if (start == true) {
		m_Start += dt;
		SoundMgr::GetInst()->Play(L"Start.wav", false);
		if (m_Start > 1.f) {
			SceneDirector::GetInst()->ChangeScene(new MenuScene());
		}
	}
}

void IntroScene::Render()
{
	m_IntroCut1->Render();
	m_IntroCut2->Render();
	m_IntroCut3->Render();
	m_IntroCut4->Render();
}