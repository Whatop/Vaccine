#include "stdafx.h"
#include "GameMgr.h"
#include "Player.h"
#include "UI.h"

GameMgr::GameMgr()
{
}

GameMgr::~GameMgr()
{
}

void GameMgr::Init()
{
	m_CreatePlayer = false;
	m_CreateUI = false;

	SetPlayerStatus(0, 0, 0, 0, 0, 0);
}

void GameMgr::RankInit()
{
	RankingPlayer* dummy = new RankingPlayer();
	dummy->name = "UNKNOWN";
	dummy->score = 0;
	Ranks.push_back(dummy);
	Ranks.push_back(dummy);
	Ranks.push_back(dummy);
	m_Score = 0;
}

void GameMgr::Release()
{
}

void GameMgr::CreatePlayer()
{
	ObjMgr->AddObject(new Player, "Player");
	m_CreatePlayer = true;
}

void GameMgr::CreateUI()
{
	UI::GetInst()->Init();
	m_CreateUI = true;
}

void GameMgr::ReleasePlayer()
{
	ObjMgr->DeleteObject("Player");
	m_CreatePlayer = false;
}

void GameMgr::ReleaseUI()
{
	UI::GetInst()->Release();
	UI::GetInst()->ReleaseInst();
	m_CreateUI = false;
}

void GameMgr::GameEnd()
{
	ReleaseUI();
	ObjMgr->Release();
	Init();

	SceneDirector::GetInst()->ChangeScene(new InputScoreScene());
}

void GameMgr::SortRanking()
{
	std::sort(Ranks.begin(), Ranks.end());
}

void GameMgr::ChangeFireMode()
{
	UI::GetInst()->ChangeFireMode();
}

void GameMgr::SetPlayerStatus(int level, int exp, int hp, float speed, int atk, float rpm)
{
	m_PlayerStatus = { level,exp,hp,speed,atk,rpm };
}

void GameMgr::SetLimit(float xmax, float xmin, float ymax, float ymin)
{
	XMAX = xmax;
	XMIN = xmin;
	YMAX = ymax;
	YMIN = ymin;
}

void GameMgr::SpawnItem(Vec2 Pos)
{
	ObjMgr->AddObject(new Item(Pos), "ITEM");
}

void GameMgr::SpawnMiddleBoss()
{
	ObjMgr->AddObject(new MiddleBoss(), "MiddleBoss");
}

void GameMgr::SpawnFinalBoss()
{
	ObjMgr->AddObject(new FinalBoss(), "FianlBoss");
}

void GameMgr::SpawnEnemy1(Vec2 Pos = Vec2(1920 / 2, -100))
{
	ObjMgr->AddObject(new Enemy1(Pos), "Enemy");
}

void GameMgr::SpawnEnemy2(Vec2 Pos = Vec2(1920 / 2, -100))
{
	ObjMgr->AddObject(new Enemy2(Pos), "Enemy");
}

void GameMgr::SpawnEliteEnemy1(Vec2 Pos = Vec2(1920 / 2, -100))
{
	ObjMgr->AddObject(new EliteEnemy1(Pos), "Enemy");
}

void GameMgr::SpawnEliteEnemy2(Vec2 Pos = Vec2(1920 / 2, -100))
{
	ObjMgr->AddObject(new EliteEnemy2(Pos), "Enemy");
}

void GameMgr::UnlockSkill()
{
	if (m_FirstSkill)
		UI::GetInst()->UnlockedFirstSkill();
	if (m_SecendSkill)
		UI::GetInst()->UnlockedSecendSkill();
}
