#include "stdafx.h"
#include "GroundMgr.h"
#include "BlockMgr.h"

GroundMgr::GroundMgr()
{
	arr = 1;
	//memset(m_LinePos, 0, sizeof(m_LinePos));
}

GroundMgr::~GroundMgr()
{
}

void GroundMgr::PlayerPos(Vec2 Pos)
{
	m_LinePos[0] = Pos;
}	

void GroundMgr::LinePos(Vec2 LinePos)
{	m_LinePos[arr] = LinePos;
	std::cout << arr << "몇번째턴" << std::endl;
	arr++; 
}

void GroundMgr::Fill()// 안에 채워주는 친구 생산,위치 설정 코드임
{
	

 //if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) // 지금 클론을 PUll 로 바꿔야되는 상황이기때문에 width가 필요없어질수도 있음
	//	width = 60;
	//else if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
	//	width = 40;

	//if (m_PlayerPos.x == m_LinePos[1].x || m_PlayerPos.y == m_LinePos[1].y) {
	//	std::cout << arr << "생성실패" << std::endl;
	//}
	//if (m_PlayerPos.x != m_LinePos[0].x || m_PlayerPos.y != m_LinePos[0].y) {
	//	if (m_PlayerPos.x > m_LinePos[0].x) { // 플레이어가 라인보다 클때
	//		for (int i = 0; m_PlayerPos.x - i > m_LinePos[0].x; i += width) {
	//			if (m_PlayerPos.y > m_LinePos[0].y) { // 플레이어가 라인보다 클때
	//				for (int j = 0; m_PlayerPos.y - j > m_LinePos[0].y; j += width) {
	//					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y - j), "pull"), "Pull");//
	//				}
	//				std::cout << arr << "왼쪽 위" << std::endl;
	//			}
	//			else {// 플레이어가 라인보다 작을때
	//				for (int j = 0; m_PlayerPos.y + j < m_LinePos[0].y; j += width) {
	//					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y + j), "pull"), "Pull");//
	//				}
	//				std::cout << arr << "왼쪽 밑" << std::endl;
	//			}
	//		}
	//	}
	//	else { // 플레이어가 라인보다작음
	//		for (int i = width; m_PlayerPos.x + i < m_LinePos[1].x; i += width) {
	//			if (m_PlayerPos.y > m_LinePos[0].y) { // 플레이어가 라인보다 클때
	//				for (int j = width; m_PlayerPos.y - j > m_LinePos[1].y; j += width) {
	//					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y - j), "pull"), "Pull");//
	//				}
	//				std::cout << arr << "오른쪽 위" << std::endl;
	//			}
	//			else {// 플레이어가 라인보다 작을때
	//				for (int j = width; m_PlayerPos.y + j < m_LinePos[0].y; j += width) {
	//					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y + j), "pull"), "Pull");//
	//				}
	//				std::cout << arr << "오른쪽 밑" << std::endl;
	//			}
	//		}
	//	}
	//}
	//if (m_PlayerPos.x > m_LinePos[1].x) { // 플레이어가 라인보다 클때
	//	for (int i = width; m_PlayerPos.x - i > m_LinePos[1].x; i += width) {
	//		if (m_PlayerPos.y > m_LinePos[1].y) { // 플레이어가 라인보다 클때
	//			for (int j = width; m_PlayerPos.y - j > m_LinePos[1].y; j += width) {
	//				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y - j), "pull"), "Pull");//
	//			}
	//			std::cout << arr << "왼쪽 위" << std::endl;
	//		}
	//		else {// 플레이어가 라인보다 작을때
	//			for (int j = width; m_PlayerPos.y + j < m_LinePos[1].y; j += width) {
	//				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y + j), "pull"), "Pull");//
	//			}
	//			std::cout << arr << "왼쪽 밑" << std::endl;
	//		}
	//	}
	//}
	//else { // 플레이어가 라인보다작음
	//	for (int i = width; m_PlayerPos.x + i < m_LinePos[1].x; i += width) {
	//		if (m_PlayerPos.y > m_LinePos[1].y) { // 플레이어가 라인보다 클때
	//			for (int j = width; m_PlayerPos.y - j > m_LinePos[1].y; j += width) {
	//				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y - j), "pull"), "Pull");//
	//			}
	//			std::cout << arr << "오른쪽 위" << std::endl;
	//		}
	//		else {// 플레이어가 라인보다 작을때
	//			for (int j = width; m_PlayerPos.y + j < m_LinePos[1].y; j += width) {
	//				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y + j), "pull"), "Pull");//
	//			}
	//			std::cout << arr << "오른쪽 밑" << std::endl;
	//		}
	//	}
	//}
	arr = 1;

}

void GroundMgr::ResetArr()
{
	arr = 0;
}

void GroundMgr::SetLine() 
{
}

void GroundMgr::Update(float deltaTime, float time)
{
}

void GroundMgr::Render()
{
	Renderer::GetInst()->GetDevice()->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	Renderer::GetInst()->GetSprite()->End();
	Vertex  v[4] = {
 {m_LinePos[0].x, m_LinePos[0].y, 1.f, 1.f, COLORKEY_GREEN}, //z에는 아무값이 들어가도 상관없다.
 {m_LinePos[1].x, m_LinePos[1].y, 1.f, 1.f, COLORKEY_GREEN}, //w에도 아무값이 들어가도 상관없지만, 4개의 w값이 다 같아야 한다.
 {m_LinePos[2].x, m_LinePos[2].y, 1.f, 1.f, COLORKEY_GREEN},
 {m_LinePos[3].x, m_LinePos[3].y, 1.f, 1.f, COLORKEY_GREEN}};

	Renderer::GetInst()->GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(Vertex));
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
}
