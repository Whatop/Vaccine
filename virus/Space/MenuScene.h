#pragma once
//게임소개, 게임방법, 게임랭킹(score), 크래딧(credit)
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

