#pragma once
class GroundMgr : public Singleton<GroundMgr>
{
	Vec2 m_LinePos[256] = {};
	Vec2 m_InPos;

	int arr;
	int width;//Æø
public:
	GroundMgr();
	~GroundMgr();

	void PlayerPos(Vec2 PlayerPos);
	void LinePos(Vec2 LinePos);
	void Fill();
	void ResetArr();
	Vec2 GetLinePos() { return m_LinePos; }


	void Update(float deltaTime, float time);
	void Render();
};

