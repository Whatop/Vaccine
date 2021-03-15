#pragma once
class BackGround : public Object
{
	Animation* m_BackGround;
public:
	BackGround(std::wstring filename, int start, int speed, int end, Vec2 Pos);
	~BackGround();

	int Start;
	int End;

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

