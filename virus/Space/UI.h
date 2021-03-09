#pragma once
class UI : public Singleton<UI>, public Object
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
	void Init();
	void Release();

	void Update();
	void Render();
};

