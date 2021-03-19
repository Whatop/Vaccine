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
	// ���� ���� ���� �ؾߵ� 1�������� 2�������� �ٸ�
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
		ObjMgr->AddObject(new Player(Vec2(90, 90)), "Player");//��� ������
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
		ObjMgr->AddObject(new Player(Vec2(60, 60)), "Player");//��� ������

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
	//�׾����� �̾��ϱⰡ ���;ߵ�
}

void GameMgr::PlayerPos(Vec2 playerpos)
{
	m_LinePos[0] = playerpos;
}

void GameMgr::LinePos(Vec2 linepos)
{
	m_LinePos[arr] = linepos;
	std::cout << arr << "���°��" << std::endl;
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
			ObjMgr->AddObject(new BlockMgr(Vec2(a, 1050), "ground"), "Ground");//��
		}
		for (int a = 90; a < 1050; a += 60) {
			ObjMgr->AddObject(new BlockMgr(Vec2(30, a), "ground"), "Ground");//��
			ObjMgr->AddObject(new BlockMgr(Vec2(1890, a), "ground"), "Ground");//��
		}
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
	{
		ObjMgr->AddObject(new Player(Vec2(60, 60)), "Player");//��� ������
		for (int a = 20; a < 1920; a += 40) {
			ObjMgr->AddObject(new BlockMgr(Vec2(a, 20), "ground"), "Ground");//
			ObjMgr->AddObject(new BlockMgr(Vec2(a, 1060), "ground"), "Ground");//��
		}
		for (int a = 60; a < 1060; a += 40) {
			ObjMgr->AddObject(new BlockMgr(Vec2(20, a), "ground"), "Ground");//��
			ObjMgr->AddObject(new BlockMgr(Vec2(1900, a), "ground"), "Ground");//��
		}

	}
}

void GameMgr::SpawnItem(Vec2 Pos) //Item�� ����̶� ������� visible 
{
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 240 + 30), "speed"), "Speed");//������ ���ǵ� 3ȸ
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 300 + 30), "ammor"), "Ammor");//������ ��� 3ȸ
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 360 + 30), "invincible"), "Invincible");//������ ���� 1ȸ
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 420 + 30), "heal"), "Heal");//������ ü��ȸ�� +1 Ǯ���� ���� ���� 2ȸ
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 480) + 30, "random"), "Random");//������ ���� 5ȸ
}

void GameMgr::SpawnFast(Vec2 Pos)
{
	ObjMgr->AddObject(new BlockMgr(Vec2(1170, 300 + 30), "fast"), "Monster");//���ǵ� �� 1ĭ
}

void GameMgr::SpawnFlash(Vec2 Pos)
{
	ObjMgr->AddObject(new BlockMgr(Vec2(1170, 420 + 60), "flash"), "Monster");//���� �� 1~ 2ĭ? ����� �����̶� ��ġ������ ���� �ʿ��� BlockMgr���� �����ؾߵ�
}

void GameMgr::SpawnGiant(Vec2 Pos)
{
	ObjMgr->AddObject(new BlockMgr(Vec2(1170 + 30, 660 + 60), "giant"), "Monster");// ū �� 2ĭ����?
}

void GameMgr::SpawnToxino(Vec2 Pos)
{
	ObjMgr->AddObject(new BlockMgr(Vec2(1170 + 30, 780 + 60), "toxino"), "Monster");// ��ó� 4ĭ?
}

void GameMgr::Draw()
{
	Renderer::GetInst()->GetDevice()->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	Renderer::GetInst()->GetSprite()->End();
	Vertex  v[4] = {
 {m_LinePos[0].x, m_LinePos[0].y, 1.f, 1.f, COLORKEY_GREEN}, //z���� �ƹ����� ���� �������.
 {m_LinePos[1].x, m_LinePos[1].y, 1.f, 1.f, COLORKEY_GREEN}, //w���� �ƹ����� ���� ���������, 4���� w���� �� ���ƾ� �Ѵ�.
 {m_LinePos[2].x, m_LinePos[2].y, 1.f, 1.f, COLORKEY_GREEN},
 {m_LinePos[3].x, m_LinePos[3].y, 1.f, 1.f, COLORKEY_GREEN} };

	Renderer::GetInst()->GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(Vertex));
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
}
