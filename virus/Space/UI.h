#pragma once
class UI : public Singleton<UI>
{
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

