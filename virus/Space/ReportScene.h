#pragma once
class ReportScene : public Scene
{
	Sprite* m_BG;
	Sprite* m_Back;

public:
	ReportScene();
	~ReportScene();

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
};