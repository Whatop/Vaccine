#pragma once
class Stage1 : public Scene
{
	Sprite* m_BG;
	Sprite* m_Virus;

	Sprite* Menu;
	Sprite* Game;

	TextMgr* m_Text;
public:
	float m_Move;
	int m_Cut;
	Stage1();
	~Stage1();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};

