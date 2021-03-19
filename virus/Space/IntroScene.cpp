#include"stdafx.h"
#include "IntroScene.h"
#include"MenuScene.h"

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{

}

void IntroScene::Init()
{
	SoundMgr::GetInst()->Play(L"Intro.wav", false);
	m_IntroCut1 = Sprite::Create(L"Painting/Intro/1.png");
	m_IntroCut1->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut2 = Sprite::Create(L"Painting/Intro/2.png");
	m_IntroCut2->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut3 = Sprite::Create(L"Painting/Intro/3.png");
	m_IntroCut3->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut4 = Sprite::Create(L"Painting/Intro/4.png");
	m_IntroCut4->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut5 = Sprite::Create(L"Painting/Intro/5.png");
	m_IntroCut5->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut6 = Sprite::Create(L"Painting/Intro/6.png");
	m_IntroCut6->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut7 = Sprite::Create(L"Painting/Intro/7.png");
	m_IntroCut7->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut8 = Sprite::Create(L"Painting/Intro/8.png");
	m_IntroCut8->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut9 = Sprite::Create(L"Painting/Intro/9.png");
	m_IntroCut9->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut10 = Sprite::Create(L"Painting/Intro/10.png");
	m_IntroCut10->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut11 = Sprite::Create(L"Painting/Intro/11.png");
	m_IntroCut11->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut12 = Sprite::Create(L"Painting/Intro/12.png");
	m_IntroCut12->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut13 = Sprite::Create(L"Painting/Intro/13.png");
	m_IntroCut13->SetPosition(1920 / 2, 1080 / 2);

	m_IntroCut13->A = 0;
	m_IntroCut12->A = 0;
	m_IntroCut11->A = 0;
	m_IntroCut10->A = 0;
	m_IntroCut9->A = 0;
	m_IntroCut8->A = 0;
	m_IntroCut7->A = 0;
	m_IntroCut6->A = 0;
	m_IntroCut5->A = 0;
	m_IntroCut4->A = 0;
	m_IntroCut3->A = 0;
	m_IntroCut2->A = 0;

	m_Count = 0;
	m_Cut = 1;
}

void IntroScene::Release()
{
}

void IntroScene::Update(float deltaTime, float time) //백그라운드클래스 써서 간략화하기
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
			m_IntroCut3->A = 0;
			if (m_IntroCut3->A == 255)
			{
				m_Cut = 3;
				m_Count = 0.f;
			}
		case 3:
			m_IntroCut4->A += 5;
			if (m_IntroCut4->A == 255)
			{
				m_Cut = 4;
				m_Count = 0.f;

			}
			break;
		case 4:
			m_IntroCut5->A += 5;
			if (m_IntroCut5->A == 255)
			{
				m_Cut = 5;
				m_Count = 0.f;

			}
			break;
		case 5:
			m_IntroCut6->A += 5;
			if (m_IntroCut6->A == 255)
			{
				m_Cut = 6;
				m_Count = 0.f;

			}
			break;
		case 6:
			m_IntroCut7->A += 5;
			if (m_IntroCut7->A == 255)
			{
				m_Cut = 7;
				m_Count = 0.f;

			}
			break;
		case 7:
			m_IntroCut8->A += 5;
			if (m_IntroCut8->A == 255)
			{
				m_Cut = 8;
				m_Count = 0.f;

			}
			break;
		case 8:
			m_IntroCut9->A += 5;
			if (m_IntroCut9->A == 255)
			{
				m_Cut = 9;
				m_Count = 0.f;

			}
			break;
		case 9:
			m_IntroCut10->A += 5;
			if (m_IntroCut10->A == 255)
			{
				m_Cut = 10;
				m_Count = 0.f;

			}
			break;
		case 10:
			m_IntroCut11->A += 5;
			if (m_IntroCut11->A == 255)
			{
				m_Cut = 11;
				m_Count = 0.f;

			}
			break;
		case 11:
			m_IntroCut12->A += 5;
			if (m_IntroCut12->A == 255)
			{
				m_Cut = 12;
				m_Count = 0.f;

			}
			break;
		case 12:
			m_IntroCut13->A += 5;
			if (m_IntroCut13->A == 255)
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
		m_IntroCut13->A = 0;
		m_IntroCut12->A = 0;
		m_IntroCut11->A = 0;
		m_IntroCut10->A = 0;
		m_IntroCut9->A = 0;
		m_IntroCut8->A = 0;
		m_IntroCut7->A = 0;
		m_IntroCut6->A = 0;
		m_IntroCut5->A = 0;
		m_IntroCut4->A = 0;
		m_IntroCut3->A = 0;
		m_IntroCut2->A = 0;
		m_IntroCut1->A = 0;

		start = true;
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
	m_IntroCut5->Render();
	m_IntroCut6->Render();
	m_IntroCut7->Render();
	m_IntroCut8->Render();
	m_IntroCut9->Render();
	m_IntroCut10->Render();
	m_IntroCut11->Render();
	m_IntroCut12->Render();
	m_IntroCut13->Render();
}