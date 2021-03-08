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
	int player_Hp;// �÷��̾��� ü���� ���ų� ������ �޶����°� �������� ����

	void BlockType(std::string tag,Vec2);

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

