#include "stdafx.h"
#include "GroundMgr.h"
#include "BlockMgr.h"

GroundMgr::GroundMgr(Vec2, std::string tag)
{
	arr = 0;
}

GroundMgr::~GroundMgr()
{
}

void GroundMgr::PlayerPos(Vec2 Pos)
{
	m_PlayerPos = Pos;
}

void GroundMgr::LinePos(Vec2 LinePos)
{
	m_LinePos[arr] = LinePos;
	arr++;
	std::cout << arr << "¹øÂ° ÅÏ" << std::endl;
}

void GroundMgr::Fill()
{
	for (int i = m_PlayerPos.x - m_LinePos[0].x; i)
	{
		for(int i = 0; i < m_LinePos[0].x; i += 40)
		ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos[0].x,), "clone"),"Clone");
	}
}

void GroundMgr::Update(float deltaTime, float time)
{
}

void GroundMgr::Render()
{
}
