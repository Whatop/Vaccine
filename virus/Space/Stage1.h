#pragma once
class Stage1 : public Scene
{
	Sprite* m_BG;
	Sprite* m_Virus;

	Vec2 m_PrevSize;
	Vec2 m_TileSize;
	Vec2 m_GridSize;

	bool m_HideGrid;

	std::vector<Sprite*>m_Vertical;
	std::vector<Sprite*>m_Horizontal;

	TextMgr* m_Text;
public:
	Stage1();
	~Stage1();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};

