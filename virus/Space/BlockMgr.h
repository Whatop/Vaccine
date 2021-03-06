#pragma once
class BlockMgr : public Object
{
	Sprite* m_Blocks;
public:
	BlockMgr(Vec2, std::string tag);
	~BlockMgr();

	int Start;
	int End;

	void BlockType(std::string tag,Vec2);

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

