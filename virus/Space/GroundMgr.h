#pragma once
class GroundMgr : public Singleton<GroundMgr>
{
	Vec2 m_PlayerPos;
	Vec2 m_LinePos[10] = {};


public:
	GroundMgr(Vec2, std::string tag);
	~GroundMgr();

	void PlayerPos(Vec2 PlayerPos);
	void LinePos(Vec2 LinePos);

	void Update(float deltaTime, float time);
	void Render();
};

