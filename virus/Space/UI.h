#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_UI;
	TextMgr* m_Text;
public:
	UI();
	~UI();

	int m_Hp;
	int m_Score;
	float TimeLimit;
	void Init();
	void Release();

	void Update();
	void Render();
};
