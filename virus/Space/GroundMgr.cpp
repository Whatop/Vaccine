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
	std::cout << arr << "���°��" << std::endl;
	arr++; 
}

void GroundMgr::Fill()// �ȿ� ä���ִ� ģ�� ����,��ġ ���� �ڵ���
{
	

 //if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) // ���� Ŭ���� PUll �� �ٲ�ߵǴ� ��Ȳ�̱⶧���� width�� �ʿ���������� ����
	//	width = 60;
	//else if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
	//	width = 40;

	//if (m_PlayerPos.x == m_LinePos[1].x || m_PlayerPos.y == m_LinePos[1].y) {
	//	std::cout << arr << "��������" << std::endl;
	//}
	//if (m_PlayerPos.x != m_LinePos[0].x || m_PlayerPos.y != m_LinePos[0].y) {
	//	if (m_PlayerPos.x > m_LinePos[0].x) { // �÷��̾ ���κ��� Ŭ��
	//		for (int i = 0; m_PlayerPos.x - i > m_LinePos[0].x; i += width) {
	//			if (m_PlayerPos.y > m_LinePos[0].y) { // �÷��̾ ���κ��� Ŭ��
	//				for (int j = 0; m_PlayerPos.y - j > m_LinePos[0].y; j += width) {
	//					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y - j), "pull"), "Pull");//
	//				}
	//				std::cout << arr << "���� ��" << std::endl;
	//			}
	//			else {// �÷��̾ ���κ��� ������
	//				for (int j = 0; m_PlayerPos.y + j < m_LinePos[0].y; j += width) {
	//					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y + j), "pull"), "Pull");//
	//				}
	//				std::cout << arr << "���� ��" << std::endl;
	//			}
	//		}
	//	}
	//	else { // �÷��̾ ���κ�������
	//		for (int i = width; m_PlayerPos.x + i < m_LinePos[1].x; i += width) {
	//			if (m_PlayerPos.y > m_LinePos[0].y) { // �÷��̾ ���κ��� Ŭ��
	//				for (int j = width; m_PlayerPos.y - j > m_LinePos[1].y; j += width) {
	//					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y - j), "pull"), "Pull");//
	//				}
	//				std::cout << arr << "������ ��" << std::endl;
	//			}
	//			else {// �÷��̾ ���κ��� ������
	//				for (int j = width; m_PlayerPos.y + j < m_LinePos[0].y; j += width) {
	//					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y + j), "pull"), "Pull");//
	//				}
	//				std::cout << arr << "������ ��" << std::endl;
	//			}
	//		}
	//	}
	//}
	//if (m_PlayerPos.x > m_LinePos[1].x) { // �÷��̾ ���κ��� Ŭ��
	//	for (int i = width; m_PlayerPos.x - i > m_LinePos[1].x; i += width) {
	//		if (m_PlayerPos.y > m_LinePos[1].y) { // �÷��̾ ���κ��� Ŭ��
	//			for (int j = width; m_PlayerPos.y - j > m_LinePos[1].y; j += width) {
	//				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y - j), "pull"), "Pull");//
	//			}
	//			std::cout << arr << "���� ��" << std::endl;
	//		}
	//		else {// �÷��̾ ���κ��� ������
	//			for (int j = width; m_PlayerPos.y + j < m_LinePos[1].y; j += width) {
	//				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y + j), "pull"), "Pull");//
	//			}
	//			std::cout << arr << "���� ��" << std::endl;
	//		}
	//	}
	//}
	//else { // �÷��̾ ���κ�������
	//	for (int i = width; m_PlayerPos.x + i < m_LinePos[1].x; i += width) {
	//		if (m_PlayerPos.y > m_LinePos[1].y) { // �÷��̾ ���κ��� Ŭ��
	//			for (int j = width; m_PlayerPos.y - j > m_LinePos[1].y; j += width) {
	//				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y - j), "pull"), "Pull");//
	//			}
	//			std::cout << arr << "������ ��" << std::endl;
	//		}
	//		else {// �÷��̾ ���κ��� ������
	//			for (int j = width; m_PlayerPos.y + j < m_LinePos[1].y; j += width) {
	//				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y + j), "pull"), "Pull");//
	//			}
	//			std::cout << arr << "������ ��" << std::endl;
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
 {m_LinePos[0].x, m_LinePos[0].y, 1.f, 1.f, COLORKEY_GREEN}, //z���� �ƹ����� ���� �������.
 {m_LinePos[1].x, m_LinePos[1].y, 1.f, 1.f, COLORKEY_GREEN}, //w���� �ƹ����� ���� ���������, 4���� w���� �� ���ƾ� �Ѵ�.
 {m_LinePos[2].x, m_LinePos[2].y, 1.f, 1.f, COLORKEY_GREEN},
 {m_LinePos[3].x, m_LinePos[3].y, 1.f, 1.f, COLORKEY_GREEN}};

	Renderer::GetInst()->GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(Vertex));
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
}
