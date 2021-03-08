#pragma once
class UI : public Singleton<UI>, public Object
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

