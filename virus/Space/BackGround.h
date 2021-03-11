#pragma once
class BackGround : public Object
{
	Animation* m_BackGround;
public:
	BackGround(std::wstring filename, int start, int end, int speed, Vec2 Pos);
	~BackGround();

	int Start;
	int End;
	float ime;
	float m_Count;
	int m_Cut;

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

