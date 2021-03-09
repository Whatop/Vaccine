#pragma once
class UI : public Singleton<UI>
{
	Animation* m_Intro;
	Animation* m_MenuScene;
	Animation* m_MainScene;
	Animation* m_EndScene;
	Sprite* m_UI;
	TextMgr* m_Text;
public:
	UI();
	~UI();

	int m_Hp;
	int m_Score;
	void Init();
	void Release();

	void Update();
	void Render();
};

