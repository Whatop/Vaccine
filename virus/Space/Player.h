#pragma once
class Player : public Object
{
	Sprite* m_Player;

	int m_Hp;
	int m_direction;
	float m_Speed;
	float dtime;
	float jtime;
	bool Movement;
	
	Vec2 m_TileSize;
	Vec2 m_GridSize;
public:
	Player(Vec2 Pos);
	~Player();

	void CheatKey();
	
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};
