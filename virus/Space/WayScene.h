#pragma once
class WayScene : public Scene
{
	Sprite* m_BG;
	Sprite* m_Back;

public:
	WayScene();
	~WayScene();

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
};