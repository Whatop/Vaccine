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
	std::cout << arr << "번째 턴" << std::endl;
}

void GroundMgr::Fill()// 플레이어 위치랑 라인 위치 사이에 블럭을 채워야함
{
	// 벽에 닿지않고 안을 채울때
	//m_InPos.x = m_PlayerPos.x - m_LinePos[1].x;
	//m_InPos.y = m_PlayerPos.y - m_LinePos[1].y;
	if (m_PlayerPos.x > m_LinePos[1].x) { // 플레이어가 라인보다 클때
		for (int i = 40; m_PlayerPos.x - i < m_LinePos[1].x; i += 40) {
			if (m_PlayerPos.y > m_LinePos[1].y) { // 플레이어가 라인보다 클때
				for (int j = 40; m_PlayerPos.y + j < m_LinePos[1].y; j += 40) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y + j), "clone"), "Clone");//이거랑 플레이어가 소환하는 그거랑 닿으면 사라지도록
				}
			}
			else {// 플레이어가 라인보다 작을때
				for (int j = 40; m_PlayerPos.y - j < m_LinePos[1].y; j += 40) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y - j), "clone"), "Clone");//이거랑 플레이어가 소환하는 그거랑 닿으면 사라지도록
				}
			}
		}
	}
	else { //라인이 플레이어보다 클떼
		for (int i = 40; m_PlayerPos.x + i > m_LinePos[1].x; i += 40) {
			if (m_PlayerPos.y > m_LinePos[1].y) { // 플레이어가 라인보다 클때
				for (int j = 40; m_PlayerPos.y + j < m_LinePos[1].y; j += 40) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y + j), "clone"), "Clone");//이거랑 플레이어가 소환하는 그거랑 닿으면 사라지도록
				}
			}
			else {// 플레이어가 라인보다 작을때
				for (int j = 40; m_PlayerPos.y - j < m_LinePos[1].y; j += 40) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y - j), "clone"), "Clone");//이거랑 플레이어가 소환하는 그거랑 닿으면 사라지도록
				}
			}
		}
	}
}

void GroundMgr::Update(float deltaTime, float time)
{
}

void GroundMgr::Render()
{
}
