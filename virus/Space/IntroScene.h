#pragma once
class IntroScene : public Scene
{
public:
	Sprite* m_IntroCut1;
	Sprite* m_IntroCut2;
	Sprite* m_IntroCut3;
	Sprite* m_IntroCut4;

	Sprite* m_Skip;

	IntroScene();
	~IntroScene();

	float m_Count;
	int m_Cut;

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};
