#pragma once
class GroundMgr : public Singleton<GroundMgr>
{

	int arr;
	int width;//Æø
public:
	Vec2 m_LinePos[256] = {};
	Vec2 m_InPos;
	GroundMgr();
	~GroundMgr();

	void PlayerPos(Vec2 PlayerPos);
	void LinePos(Vec2 LinePos);
	void Fill();
	void ResetArr();
	void SetLine();

	void Update(float deltaTime, float time);
	void Render();
};

