#pragma once

struct RankingPlayer
{
public:
	int score;
	std::string name;
};
#define COLORKEY_GREEN D3DCOLOR_ARGB(255,50,133,50)
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr();
	~GameMgr();

	std::vector<RankingPlayer*> Ranks;

	bool m_CreatePlayer;
	bool m_CreateUI;

	int scalex;
	int scaley;


	Vec2 PrevPos;
	Vec2 m_PlayerPos;
	Vec2 m_LinePos[256] = {};

	int arr;
	int m_Score;
	int m_Hp;
	float dtime;

	bool _Hit; //클론이 맞음
	bool hit;
	float hitime;//클론이 맞음

	void Init();
	void RankInit();

	void CreatePlayer();
	void GameEnd();

	void PlayerPos(Vec2 playerpos);
	void LinePos(Vec2 linepos);

	void SortRanking();

	void SetLimit();

	void SpawnItem();

	void SpawnFast(Vec2 Pos);
	void SpawnFlash(Vec2 Pos);
	void SpawnGiant(Vec2 Pos);
	void SpawnToxino(Vec2 Pos);
	void Draw();
	void HitCheak();
};

