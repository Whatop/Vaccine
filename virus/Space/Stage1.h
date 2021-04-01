#pragma once
class Stage1 : public Scene
{
	Sprite* m_BG;
	Sprite* m_Virus;

	bool m_HideGrid;
	TextMgr* m_Text;
public:
	Stage1();
	~Stage1();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};

