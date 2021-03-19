#pragma once
struct Vertex {
	float x, y, z, w;
	D3DCOLOR color;
};
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
#define COLORKEY_GREEN D3DCOLOR_ARGB(255,0,133,0)
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


	std::vector<RankingPlayer*> Ranks;

	bool m_CreatePlayer;
	bool m_CreateUI;

	PlayerStatus m_PlayerStatus;

	Vec2 m_PlayerPos;
	Vec2 m_LinePos[256] = {};

	int arr;
	int m_Score;

	void Init();
	void RankInit();
	void Release();

	void CreatePlayer();
	void CreateUI();

	void ReleasePlayer();
	void ReleaseUI();
	void GameEnd();

	void PlayerPos(Vec2 playerpos);
	void LinePos(Vec2 linepos);
	void Fill();

	void SortRanking();

	void SetPlayerStatus(int hp, float speed);
	void SetLimit();

	void SpawnItem(Vec2 Pos);

	void SpawnFast(Vec2 Pos);
	void SpawnFlash(Vec2 Pos);
	void SpawnGiant(Vec2 Pos);
	void SpawnToxino(Vec2 Pos);
	void Draw();
};

