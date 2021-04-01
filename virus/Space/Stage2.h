#pragma once
class Stage2 : public Scene
{
	bool m_HideGrid;
	bool m_Pause;

	TextMgr* m_Text;
public:
	Stage2();
	~Stage2();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

