#include "stdafx.h"
#include "GameMgr.h"
#include "Player.h"
#include "UI.h"
#include "BlockMgr.h"

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
	arr = 1;
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
}

void GameMgr::LinePos(Vec2 linepos)
{
	m_LinePos[arr] = linepos;
	std::cout << arr << "몇번째턴" << std::endl;
	arr++;
}

void GameMgr::Fill()
{
	arr = 1;
}

void GameMgr::SortRanking()
{
	std::sort(Ranks.begin(), Ranks.end());
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
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 240 + 30), "speed"), "Speed");//아이템 스피드 3회
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 300 + 30), "ammor"), "Ammor");//아이템 방어 3회
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 360 + 30), "invincible"), "Invincible");//아이템 무적 1회
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 420 + 30), "heal"), "Heal");//아이템 체력회복 +1 풀리면 점수 오름 2회
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 480) + 30, "random"), "Random");//아이템 랜덤 5회
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
	Renderer::GetInst()->GetDevice()->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	Renderer::GetInst()->GetSprite()->End();
	Vertex  v[4] = {
 {m_LinePos[0].x, m_LinePos[0].y, 1.f, 1.f, COLORKEY_GREEN}, //z에는 아무값이 들어가도 상관없다.
 {m_LinePos[1].x, m_LinePos[1].y, 1.f, 1.f, COLORKEY_GREEN}, //w에도 아무값이 들어가도 상관없지만, 4개의 w값이 다 같아야 한다.
 {m_LinePos[2].x, m_LinePos[2].y, 1.f, 1.f, COLORKEY_GREEN},
 {m_LinePos[3].x, m_LinePos[3].y, 1.f, 1.f, COLORKEY_GREEN} };

	Renderer::GetInst()->GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(Vertex));
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
}
