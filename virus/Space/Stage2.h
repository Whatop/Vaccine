#pragma once
class Stage2 : public Scene
{
	Sprite* m_BG;
	Sprite* m_Virus;
public:
	float m_Move;
	int m_Cut;

	Stage2();
	~Stage2();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

