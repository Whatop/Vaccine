#pragma once
//���ӼҰ�, ���ӹ��, ���ӷ�ŷ(score), ũ����(credit)
class MenuScene : public Scene
{
	Sprite* m_MainScene;
	Sprite* m_Start;
	Sprite* m_Report;
	Sprite* m_Way;
	Sprite* m_Rank;
	Sprite* m_Credit;

public:
	MenuScene();
	~MenuScene();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};

