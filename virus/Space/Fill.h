#pragma once
class Fill : public Object
{
	Sprite* m_Fill;
	int m_Type;
	float type;
public:
	Fill(Vec2 MyPos, Vec2 Scale,int type);
	~Fill();
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

 