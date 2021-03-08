#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_UI;
	Sprite* m_Curtain;
	Sprite* m_Pillar;
	Sprite* m_HpBar;
	Sprite* m_SpHp;
	Sprite* m_Poison;

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

