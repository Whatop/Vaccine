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
	int m_Cure;
	float dtime;

	bool hit;
	float hitime;//클론이 맞음

	bool _Hit; //클론이 맞음
	bool _Speed;
	bool _Invincible;
	bool _Heal;
	bool _Ammor;
	bool _Random;

	void Init();
	void RankInit();

	void CreatePlayer();
	void GameEnd();
	void CreateUI();
	void ReleaseUI();

	void PlayerPos(Vec2 playerpos);
	void LinePos(Vec2 linepos);

	void SortRanking();

	void SetLimit();

	void SpawnItem();

	void SpawnEnemy();
	void AddScore(int score);
	void AddCure(int cure);

	void Draw();
	void HitCheak();
};

