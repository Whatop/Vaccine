#pragma once
class BlockMgr : public Object
{
public:
	BlockMgr();
	~BlockMgr();

	int Start;
	int End;

	void BlockType(std::string tag);

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

