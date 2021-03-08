#pragma once
class Player : public Object
{
	Sprite* m_Player;

	int m_Hp;
	float m_Speed;

	int m_direction;
	float dtime;
	float jtime; // ������ �ð�
	float limit; // ������ ���ѽð�
	float itime; // ������ ���ӽð�

	bool Movement;
	
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

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};
