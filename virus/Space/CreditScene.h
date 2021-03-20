#pragma once
class CreditScene : public Scene
{
	Sprite* m_BG;
	Sprite* m_Back;

	float stoptime;
public:
	CreditScene();
	~CreditScene();

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
};