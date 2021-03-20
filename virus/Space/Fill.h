#pragma once
class Fill : public Object
{
	Sprite* m_Fill;
public:
	Fill(Vec2 MyPos, Vec2 Scale);
	~Fill();
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

 