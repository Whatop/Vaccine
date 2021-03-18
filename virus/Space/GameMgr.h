#pragma once
struct PlayerStatus
{
public:
	int m_HP;
	float m_Speed;
};
struct RankingPlayer
{
	int score;
	std::string name;
};
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr();
	~GameMgr();

	struct stVECTORsort
	{
		bool operator() (const RankingPlayer* pObject1, const RankingPlayer* pObject2) const
		{
			if (pObject1->score < pObject2->score)
				return TRUE;

			return FALSE;
		}
	};

	float XMAX, XMIN, YMAX, YMIN;

	std::vector<RankingPlayer*> Ranks;

	bool m_CreatePlayer;
	bool m_CreateUI;

	PlayerStatus m_PlayerStatus;

	Vec2 m_PlayerPos;
	Vec2 m_LinePos[256] = {};

	int m_Score;

	void Init();
	void RankInit();
	void Release();

	void CreatePlayer();
	void CreateUI();

	void ReleasePlayer();
	void ReleaseUI();
	void GameEnd();

	void SortRanking();

	void ChangeFireMode();

	void SetPlayerStatus(int level, int exp, int hp, float speed, int atk, float rpm);
	void SetLimit(float xmax, float xmin, float ymax, float ymin);
	void SpawnItem(Vec2 Pos);

	void SpawnMiddleBoss();
	void SpawnFinalBoss();

	void SpawnEnemy1(Vec2 Pos);
	void SpawnEnemy2(Vec2 Pos);
	void SpawnEliteEnemy1(Vec2 Pos);
	void SpawnEliteEnemy2(Vec2 Pos);
};

