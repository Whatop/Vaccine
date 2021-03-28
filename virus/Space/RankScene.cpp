#include "stdafx.h"
#include "RankScene.h"
#include "MenuScene.h"

RankScene::RankScene()
{
}

RankScene::~RankScene()
{
}

void RankScene::Init()
{

	m_BG = Sprite::Create(L"Painting/Scene/Black.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_Rank = Sprite::Create(L"Painting/Scene/Rank.png");
	m_Rank->SetPosition(1920 / 2, 100);

	m_Back = Sprite::Create(L"Painting/Button/ReturnTitle.png");
	m_Back->SetPosition(1700, 900);

	m_First = new TextMgr();
	m_Secend = new TextMgr();
	m_Third = new TextMgr();

	m_First->Init(72, true, false, "Arial");
	m_Secend->Init(72, true, false, "Arial");
	m_Third->Init(72, true, false, "Arial");
}

void RankScene::Release()
{
}

void RankScene::Update(float deltaTime, float Time)
{

	GameMgr::GetInst()->SortRanking();
	if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Back) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new MenuScene());
	}
}

void RankScene::Render()
{
	m_BG->Render();
	m_Back->Render();
	m_Rank->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	std::vector<RankingPlayer*> s = GameMgr::GetInst()->Ranks;
	m_First->print("NAME : " + GameMgr::GetInst()->Ranks.at(0)->name + " / SCORE : " + std::to_string(GameMgr::GetInst()->Ranks.at(0)->score), 600, 300);
	m_Secend->print("NAME : " + GameMgr::GetInst()->Ranks.at(1)->name + " / SCORE : " + std::to_string(GameMgr::GetInst()->Ranks.at(1)->score), 600, 500);
	m_Third->print("NAME : " + GameMgr::GetInst()->Ranks.at(2)->name + " / SCORE : " + std::to_string(GameMgr::GetInst()->Ranks.at(2)->score), 600, 700);
	Renderer::GetInst()->GetSprite()->End();
}
