#pragma once
class BlockMgr : public Object
{
	Sprite* m_Blocks;
	std::string _tag;
	bool type_item;
	bool type_enemy;


public:
	BlockMgr(Vec2, std::string tag);
	~BlockMgr();

	int Start;
	int End;
	int m_Hp;
	int player_Hp;// 플레이어의 체력이 적거나 많을때 달라지는것 여유있음 넣자
	
	bool player;

	float m_Speed;
	float MoveTime;
	float Moveif;

	//flash
	bool bigger;
	int flashstack;//스택
	int flashtime;//
	bool efttect;


	bool left;
	bool right;
	bool down;
	bool up;

	void BlockType(std::string tag,Vec2);

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

