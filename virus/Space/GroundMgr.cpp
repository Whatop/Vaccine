#include "stdafx.h"
#include "GroundMgr.h"
#include "BlockMgr.h"

GroundMgr::GroundMgr()
{
	arr = 0;
	m_PlayerPos = Vec2(0, 0);
	memset(m_LinePos, 0, sizeof(m_LinePos));
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
	std::cout << arr << "몇번째턴" << std::endl;
	arr++; 
}

void GroundMgr::Fill()// 안에 채워주는 친구 생산,위치 설정 코드임
{

	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
		width = 60;
	else if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
		width = 40;
	if (m_PlayerPos.x == m_LinePos[1].x || m_PlayerPos.y == m_LinePos[1].y) {
		std::cout << arr << "생성실패" << std::endl;
	}
	if (m_PlayerPos.x > m_LinePos[1].x) { // 플레이어가 라인보다 클때
		for (int i = width; m_PlayerPos.x - i > m_LinePos[1].x; i += width) {
			if (m_PlayerPos.y > m_LinePos[1].y) { // 플레이어가 라인보다 클때
				for (int j = width; m_PlayerPos.y - j > m_LinePos[1].y; j += width) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y - j), "pull"), "Pull");//
				}
				std::cout << arr << "왼쪽 위" << std::endl;
			}
			else {// 플레이어가 라인보다 작을때
				for (int j = width; m_PlayerPos.y + j < m_LinePos[1].y; j += width) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y + j), "pull"), "Pull");//
				}
				std::cout << arr << "왼쪽 밑" << std::endl;
			}
		}
	}
	else { // 플레이어가 라인보다작음
		for (int i = width; m_PlayerPos.x + i < m_LinePos[1].x; i += width) {
			if (m_PlayerPos.y > m_LinePos[1].y) { // 플레이어가 라인보다 클때
				for (int j = width; m_PlayerPos.y - j > m_LinePos[1].y; j += width) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y - j), "pull"), "Pull");//
				}
				std::cout << arr << "오른쪽 위" << std::endl;
			}
			else {// 플레이어가 라인보다 작을때
				for (int j = width; m_PlayerPos.y + j < m_LinePos[1].y; j += width) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y + j), "pull"), "Pull");//
				}
				std::cout << arr << "오른쪽 밑" << std::endl;
			}
		}
	}
	arr = 0;

}

void GroundMgr::ResetArr()
{
	arr = 0;
}

void GroundMgr::Update(float deltaTime, float time)
{
}

void GroundMgr::Render()
{
}
