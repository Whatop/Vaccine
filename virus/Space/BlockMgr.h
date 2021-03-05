#pragma once
class BlockMgr : public Object
{
public:
	BlockMgr();
	~BlockMgr();

	int Start;
	int End;

	void BlockType();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

