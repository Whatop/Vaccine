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
	// ���� ���� ���� �ؾߵ� 1�������� 2�������� �ٸ�

	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) {

		int randomposx = rand() % 1830;
		int randomposy = rand() % 990;
		int randomxy = rand() % 2 + 1;
		if (randomxy == 1) {
			for (; randomposx % 60 != 0; randomposx--) {
				int LeftRight = rand() % 2 + 1;
				if(LeftRight ==1)
					randomposy = 90;
				else
					randomposy = 1080-90;

			}
			randomposx += 90;
		}
		else if(randomxy == 2) {
			for (; randomposy % 60 != 0; randomposy--) {
				int LeftRight = rand() % 2 + 1;
				if (LeftRight==1)
					randomposx = 90;
				else
					randomposx = 1920 - 90;

			}
			randomposy += 90;
		}
		if (randomposy > 990)
			randomposy = 990;
		if (randomposx > 1830)
			randomposx = 1830;

		ObjMgr->AddObject(new Player(Vec2(randomposx, randomposy)), "Player");
		//ObjMgr->AddObject(new Player(Vec2(90, 90)), "Player");//��� ������
	}
	else if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2) {
			int randomposx = rand() % 1860;
			int randomposy = rand() % 1020;
			int randomxy = rand() % 2 + 1;
			if (randomxy == 1) {
				for (; randomposx % 40 != 0; randomposx--) {
					int LeftRight = rand() % 2 + 1;
					if (LeftRight==1)
						randomposy = 60;
					else
						randomposy = 1080 - 60;

				}
				randomposx += 60;
			}
			else  {
				for (; randomposy % 40 != 0; randomposy--) {
					int LeftRight = rand() % 2 + 1;
					if (LeftRight==1)
						randomposx = 60;
					else
						randomposx = 1920 - 60;

				}
				randomposy += 60;
			}
			ObjMgr->AddObject(new Player(Vec2(randomposx, randomposy)), "Player");
			//ObjMgr->AddObject(new Player(Vec2(60, 60)), "Player");//��� ������
		}

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
	//�׾����� �̾��ϱⰡ ���;ߵ�
}

void GameMgr::PlayerPos(Vec2 playerpos)
{
	m_LinePos[0] = playerpos;
}

void GameMgr::LinePos(Vec2 linepos)
{
	arr++;
	m_LinePos[arr] = linepos;
	std::cout << arr << "���°��" << std::endl;
}


//bool Sort(const RankingPlayer* pSour, const RankingPlayer* pDest)
//{
//	return (pSour->score > pDest->score);
//} �̰ɷ� �ص� ������

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
			ObjMgr->AddObject(new BlockMgr(Vec2(a, 1050), "ground"), "Ground");//��
		}
		for (int a = 90; a < 1050; a += 60) {
			ObjMgr->AddObject(new BlockMgr(Vec2(30, a), "ground"), "Ground");//��
			ObjMgr->AddObject(new BlockMgr(Vec2(1890, a), "ground"), "Ground");//��
		}
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
	{
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
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
	{
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 240 + 30), "speed"), "Speed");//������ ���ǵ� 3ȸ
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 300 + 30), "ammor"), "Ammor");//������ ��� 3ȸ
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 360 + 30), "invincible"), "Invincible");//������ ���� 1ȸ
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 420 + 30), "heal"), "Heal");//������ ü��ȸ�� +1 Ǯ���� ���� ���� 2ȸ
		ObjMgr->AddObject(new BlockMgr(Vec2(270, 480) + 30, "random"), "Random");//������ ���� 5ȸ
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
	{
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 240 + 20), "speed"), "Speed");//������ ���ǵ� 3ȸ
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 280 + 20), "ammor"), "Ammor");//������ ��� 3ȸ
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 320 + 20), "invincible"), "Invincible");//������ ���� 1ȸ
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 360 + 20), "heal"), "Heal");//������ ü��ȸ�� +1 Ǯ���� ���� ���� 2ȸ
		ObjMgr->AddObject(new BlockMgr(Vec2(300, 400 + 20), "random"), "Random");//������ ���� 5ȸ
	}
}

void GameMgr::SpawnFast(Vec2 Pos)
{
	ObjMgr->AddObject(new BlockMgr(Vec2(1170, 300 + 30), "fast"), "Monster");//���ǵ� �� 1ĭ
}

void GameMgr::SpawnFlash(Vec2 Pos)
{
	int random = rand() % 2 + 1;

	if (random == 1)
		ObjMgr->AddObject(new BlockMgr(Vec2(1170 + 30, 660 + 60), "flash"), "Monster");// ū �� 2ĭ����?
	else if (random == 2)
	ObjMgr->AddObject(new BlockMgr(Vec2(1170, 420 + 60), "flashgiant"), "Monster");//���� �� 1~ 4ĭ? ����� �����̶� ��ġ������ ���� �ʿ��� BlockMgr���� �����ؾߵ�
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
	dtime += dt;
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
	{
			float posx = (m_LinePos[0].x + m_LinePos[2].x) / 2;
			float posy = (m_LinePos[0].y + m_LinePos[2].y) / 2;

			if (m_LinePos[2].x > m_LinePos[0].x) {
				if (m_LinePos[2].y < m_LinePos[0].y) {

					m_PlayerPos.y = m_LinePos[2].y;
					m_LinePos[2].y = m_LinePos[0].y;
					m_LinePos[0].y = m_PlayerPos.y;
				}

			//	else if (m_LinePos[2].y > m_LinePos[0].y) {
//				������
			//	}
			}
			else if (m_LinePos[2].x < m_LinePos[0].x) {

				if (m_LinePos[2].y < m_LinePos[0].y) {

					m_PlayerPos = m_LinePos[2];
					m_LinePos[2] = m_LinePos[0];
					m_LinePos[0] = m_PlayerPos;
				}
				else if (m_LinePos[2].y > m_LinePos[0].y) {
					m_PlayerPos.x = m_LinePos[2].x;
					m_LinePos[2].x = m_LinePos[0].x;
					m_LinePos[0].x = m_PlayerPos.x;
				}
			}

			float scalex = (m_LinePos[2].x - m_LinePos[0].x + 60) / 60;
			float scaley = (m_LinePos[2].y - m_LinePos[0].y + 60) / 60;
			//�׳� ���� �ݴ�� �־��ָ� �Ǵ°� �ƴѰ�?
			//m_LinePos[2]���� 0���� ������ְ�
			//m_LinePos[0]���� 2�� ������ָ� ������ �Ϻ�������.

			ObjMgr->AddObject(new Fill(Vec2(posx, posy), Vec2(scalex, scaley), 1), "Fill");
			ObjMgr->AddObject(new Fill(Vec2(posx, posy), Vec2(scalex, scaley), 0), "ColBox");
	}

	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
	{
		float posx = (m_LinePos[0].x + m_LinePos[2].x) / 2;
		float posy = (m_LinePos[0].y + m_LinePos[2].y) / 2;

		if (m_LinePos[2].x > m_LinePos[0].x) {
			if (m_LinePos[2].y < m_LinePos[0].y) {

				m_PlayerPos.y = m_LinePos[2].y;
				m_LinePos[2].y = m_LinePos[0].y;
				m_LinePos[0].y = m_PlayerPos.y;
			}

			//	else if (m_LinePos[2].y > m_LinePos[0].y) {
//				������
			//	}
		}
		else if (m_LinePos[2].x < m_LinePos[0].x) {

			if (m_LinePos[2].y < m_LinePos[0].y) {

				m_PlayerPos = m_LinePos[2];
				m_LinePos[2] = m_LinePos[0];
				m_LinePos[0] = m_PlayerPos;
			}
			else if (m_LinePos[2].y > m_LinePos[0].y) {
				m_PlayerPos.x = m_LinePos[2].x;
				m_LinePos[2].x = m_LinePos[0].x;
				m_LinePos[0].x = m_PlayerPos.x;
			}
		}

		float scalex = (m_LinePos[2].x - m_LinePos[0].x + 40) / 40;
		float scaley = (m_LinePos[2].y - m_LinePos[0].y + 40) / 40;
		//�׳� ���� �ݴ�� �־��ָ� �Ǵ°� �ƴѰ�?
		//m_LinePos[2]���� 0���� ������ְ�
		//m_LinePos[0]���� 2�� ������ָ� ������ �Ϻ�������.

		ObjMgr->AddObject(new Fill(Vec2(posx, posy), Vec2(scalex, scaley), 1), "Fill");
		ObjMgr->AddObject(new Fill(Vec2(posx, posy), Vec2(scalex, scaley), 0), "ColBox");
	}
	arr = 0;
	m_LinePos[3].x = -100;
	m_LinePos[3].y = -100;
}
