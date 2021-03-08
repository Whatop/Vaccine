#pragma once
class MainScene : public Scene
{
	Vec2 m_PrevSize;
	Vec2 m_TileSize;
	Vec2 m_GridSize;

	bool m_HideGrid;
	bool m_Pause;

	std::vector<Sprite*>m_Vertical;
	std::vector<Sprite*>m_Horizontal;
	
	//TextMgr* m_Text;
public:
	MainScene();
	~MainScene();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

