#include "stdafx.h"
#include "GameMgr.h"
#include "Player.h"
#include "UI.h"
#include "BlockMgr.h"
#include "Fill.h"

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

	SetPlayerStatus(0, 0);
	arr = 0;
	
	memset(m_LinePos, 90, sizeof(m_LinePos));
}

void GameMgr::RankInit()
{
	RankingPlayer* player = new RankingPlayer();
	player->name = "player";
	player->score = 1;

	RankingPlayer* sans = new RankingPlayer();
	sans->name = "cht";
	sans->score = 9999;

	RankingPlayer* dummy = new RankingPlayer();
	dummy->name = "dummy";
	dummy->score = -10;

	Ranks.push_back(player);
	Ranks.push_back(dummy);
	Ranks.push_back(sans);
	m_Score = 0;
}

void GameMgr::Release()
{
}

void GameMgr::CreatePlayer()
{
	// 벽쪽 랜덤 생성 해야됨 1스테이지 2스테이지 다름
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
		ObjMgr->AddObject(new Player(Vec2(90, 90)), "Player");//백신 왼쪽위
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
		ObjMgr->AddObject(new Player(Vec2(60, 60)), "Player");//백신 왼쪽위

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
//	0-------1
//	|		|
//	3-------2	
//
//
void GameMgr::GameEnd()
{
	//ReleaseUI();
	//ObjMgr->Release();
	//Init();
	//SceneDirector::GetInst()->ChangeScene(new InputScoreScene());
	//죽었을때 이어하기가 나와야됨
}

void GameMgr::PlayerPos(Vec2 playerpos)
{
	m_LinePos[0] = playerpos;
	m_LinePos[4] = m_LinePos[0];
}

void GameMgr::LinePos(Vec2 linepos)
{
	arr++;
	m_LinePos[arr] = linepos;
	std::cout << arr << "몇번째턴" << std::endl;
}


//bool Sort(const RankingPlayer* pSour, const RankingPlayer* pDest)
//{
//	return (pSour->score > pDest->score);
//} 이걸로 해도 가능함

void GameMgr::SortRanking()
{
	std::sort(Ranks.begin(), Ranks.end(), GameMgr::stVECTORsort());
}

void GameMgr::SetPlayerStatus(int hp, float speed)
{
	m_PlayerStatus = { hp,speed };
}

void GameMgr::SetLimit()
{
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) {
		for (int a = 30; a < 1920; a += 60) {
			ObjMgr->AddObject(new BlockMgr(Vec2(a, 30), "ground"), "Ground");//
			ObjMgr->AddObject(new BlockMgr(Vec2(a, 1050), "ground"), "Ground");//벽
		}
		for (int a = 90; a < 1050; a += 60) {
			ObjMgr->AddObject(new BlockMgr(Vec2(30, a), "ground"), "Ground");//벽
			ObjMgr->AddObject(new BlockMgr(Vec2(1890, a), "ground"), "Ground");//벽
		}
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
	{
		ObjMgr->AddObject(new Player(Vec2(60, 60)), "Player");//백신 왼쪽위
		for (int a = 20; a < 1920; a += 40) {
			ObjMgr->AddObject(new BlockMgr(Vec2(a, 20), "ground"), "Ground");//
			ObjMgr->AddObject(new BlockMgr(Vec2(a, 1060), "ground"), "Ground");//벽
		}
		for (int a = 60; a < 1060; a += 40) {
			ObjMgr->AddObject(new BlockMgr(Vec2(20, a), "ground"), "Ground");//벽
			ObjMgr->AddObject(new BlockMgr(Vec2(1900, a), "ground"), "Ground");//벽
		}

	}
}

void GameMgr::SpawnItem(Vec2 Pos) //Item에 백신이랑 닿았을때 visible 
{
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
	{
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 240 + 30), "speed"), "Speed");//아이템 스피드 3회
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 300 + 30), "ammor"), "Ammor");//아이템 방어 3회
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 360 + 30), "invincible"), "Invincible");//아이템 무적 1회
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 420 + 30), "heal"), "Heal");//아이템 체력회복 +1 풀리면 점수 오름 2회
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 480) + 30, "random"), "Random");//아이템 랜덤 5회
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
	{
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 240 + 20), "speed"), "Speed");//아이템 스피드 3회
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 280 + 20), "ammor"), "Ammor");//아이템 방어 3회
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 320 + 20), "invincible"), "Invincible");//아이템 무적 1회
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 360 + 20), "heal"), "Heal");//아이템 체력회복 +1 풀리면 점수 오름 2회
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 400 + 20), "random"), "Random");//아이템 랜덤 5회
	}
}

void GameMgr::SpawnFast(Vec2 Pos)
{
	ObjMgr->AddObject(new BlockMgr(Vec2(1170, 300 + 30), "fast"), "Monster");//스피드 적 1칸
}

void GameMgr::SpawnFlash(Vec2 Pos)
{
	ObjMgr->AddObject(new BlockMgr(Vec2(1170, 420 + 60), "flash"), "Monster");//점멸 적 1~ 2칸? 사이즈가 랜덤이라 위치조정이 따로 필요함 BlockMgr에서 조정해야됨
}

void GameMgr::SpawnGiant(Vec2 Pos)
{
	ObjMgr->AddObject(new BlockMgr(Vec2(1170 + 30, 660 + 60), "giant"), "Monster");// 큰 적 2칸으로?
}

void GameMgr::SpawnToxino(Vec2 Pos)
{
	ObjMgr->AddObject(new BlockMgr(Vec2(1170 + 30, 780 + 60), "toxino"), "Monster");// 톡시노 4칸?
}

void GameMgr::Draw()
{
	dtime += dt;
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
	{
		float posx = (m_LinePos[0].x + m_LinePos[2].x) / 2;
		float posy = (m_LinePos[0].y + m_LinePos[2].y) / 2;
		float scalex = (m_LinePos[2].x - m_LinePos[0].x + 60) / 60;
		float scaley = (m_LinePos[2].y - m_LinePos[0].y + 60) / 60;
		ObjMgr->AddObject(new Fill(Vec2(posx , posy ), Vec2(scalex, scaley),1), "Fill");
		ObjMgr->AddObject(new Fill(Vec2(posx , posy ), Vec2(scalex, scaley),0), "FCOLBOX");
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
	{
		float posx = (m_LinePos[0].x + m_LinePos[2].x) / 2;
		float posy = (m_LinePos[0].y + m_LinePos[2].y) / 2;
		float scalex = (m_LinePos[2].x - m_LinePos[0].x + 30) / 60;
		float scaley = (m_LinePos[2].y - m_LinePos[0].y + 30) / 60;
		ObjMgr->AddObject(new Fill(Vec2(posx - 20, posy - 20), Vec2(scalex, scaley), 0), "Fill");
			ObjMgr->AddObject(new Fill(Vec2(posx - 20, posy - 20), Vec2(scalex, scaley), 1), "FCOLBOX");
	}


}
