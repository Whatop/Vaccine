#include "stdafx.h"
#include "Stage2.h"
#include "Player.h"

Stage2::Stage2()
{
}

Stage2::~Stage2()
{
}
//인트로 만들기 -> 메뉴에선 게임소개, 게임방법, 게임랭킹. 크래디 선택
void Stage2::Init() // 스테이지 1 배경 신체로 하고, 스테이지 2의 배경을 숲으로 한다. 근대 숲이라고 초록초록하면 분위기가 안사니 
{
	ObjMgr->Release();

	m_BG = Sprite::Create(L"Painting/Stage1/Stage1.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_Virus = Sprite::Create(L"Painting/Stage1/Virus.png");
	m_Virus->SetPosition(1920 / 2, 1080 / 2);

	Menu = Sprite::Create(L"Painting/Button/ReturnTitle.png");
	Menu->SetPosition(640, 1080 / 2); 
	Menu->m_Visible = false;

	Game = Sprite::Create(L"Painting/Button/ReturnGame.png");
	Game->SetPosition(1280, 1080 / 2);
	Game->m_Visible = false;

	SceneDirector::GetInst()->SetScene(SceneState::STAGE2);
	GameMgr::GetInst()->ReleaseUI();
	GameMgr::GetInst()->CreatePlayer();
	GameMgr::GetInst()->SetLimit();
	GameMgr::GetInst()->CreateUI();
	GameMgr::GetInst()->SpawnItem();
	GameMgr::GetInst()->SpawnEnemy();

	m_Cut = 0;
	m_Move = 0;
}

void Stage2::Release()
{
}

void Stage2::Update(float deltaTime, float time)
{
	m_Move += dt;
	if (m_Move > 1) {
		switch (m_Cut) {
		case 1:
			m_Virus->Translate(1000 * dt, 0);
			m_Cut++;
			m_Move = 0;
			break;
		case 2:
			m_Virus->Translate(0, -1000 * dt);
			m_Cut++;
			m_Move = 0;
			break;
		case 3:
			m_Virus->Translate(-1000 * dt, 0);
			m_Cut++;
			m_Move = 0;
			break;
		case 4:
			m_Virus->Translate(0, 1000 * dt);
			m_Cut = 1;
			m_Move = 0;
			break;
		}
	}
	if (GameMgr::GetInst()->Visible == false) {
		m_BG->A = 200;
		m_Virus->A = 200;
		Menu->m_Visible = true;
		Game->m_Visible = true;

		if (CollisionMgr::GetInst()->MouseWithBoxSize(Menu) && INPUT->GetButtonDown())
		{
			SceneDirector::GetInst()->SetScene(SceneState::MENU);
			ObjMgr->AddObject(new Loading(0), "SceneChange");
		}

		if (CollisionMgr::GetInst()->MouseWithBoxSize(Game) && INPUT->GetButtonDown())
		{
			GameMgr::GetInst()->Keep = true;
		}
	}
	else {
		m_BG->A = 255;
		m_Virus->A = 255;
		Menu->m_Visible = false;
		Game->m_Visible = false;
	}

}

void Stage2::Render()
{
	m_BG->Render();
	m_Virus->Render();
	Menu->Render();
	Game->Render();
}
