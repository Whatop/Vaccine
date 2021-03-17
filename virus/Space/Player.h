#pragma once

enum class MoveState {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NONE
};

#define _left 0
#define _right 1
#define _up 2
#define _down 3

class Player : public Object
{
	Sprite* m_Player;
	MoveState m_State;
	int m_Hp;
	float m_Speed;

	int m_direction;
	float dtime;
	float jtime; // 움직임 시간
	float limit; // 움직임 제한시간
	float itime; // 아이템 지속시간

	float xlimit;
	float ylimit;

	//bool 
	bool create;

	int Movement;
	
	//size
	Vec2 m_TileSize;
	Vec2 m_GridSize;

	//buff
	bool _Speed;
	bool _Invincible;
	bool _Heal;
	bool _Ammor;
public:
	Player(Vec2 Pos);
	~Player();

	void CheatKey();
	void Buff();
	void Move();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};
