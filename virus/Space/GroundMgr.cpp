#include "stdafx.h"
#include "GroundMgr.h"
#include "BlockMgr.h"

GroundMgr::GroundMgr()
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
	std::cout << arr << "���°��" << std::endl;
	arr++;
}

void GroundMgr::Fill()// �ȿ� ä���ִ� ģ�� ����,��ġ ���� �ڵ���
{
	if (m_PlayerPos.x > m_LinePos[1].x) { // �÷��̾ ���κ��� Ŭ��
		for (int i = 60; m_PlayerPos.x - i > m_LinePos[1].x; i += 60) {
			if (m_PlayerPos.y > m_LinePos[1].y) { // �÷��̾ ���κ��� Ŭ��
				for (int j = 60; m_PlayerPos.y - j > m_LinePos[1].y; j += 60) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y - j), "pull"), "Ground");//
				}
			}
			else {// �÷��̾ ���κ��� ������
				for (int j = 60; m_PlayerPos.y + j < m_LinePos[1].y; j += 60) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y + j), "pull"), "Ground");//
				}
			}
		}
	}
	else { // �÷��̾ ���κ�������
		for (int i = 60; m_PlayerPos.x + i < m_LinePos[1].x; i += 60) {
			if (m_PlayerPos.y > m_LinePos[1].y) { // �÷��̾ ���κ��� Ŭ��
				for (int j = 60; m_PlayerPos.y - j > m_LinePos[1].y; j += 60) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y - j), "pull"), "Ground");//
				}
			}
			else {// �÷��̾ ���κ��� ������
				for (int j = 60; m_PlayerPos.y + j < m_LinePos[1].y; j += 60) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y + j), "pull"), "Ground");//
				}

			}
		}
	}
	arr = 0;

	std::cout << "Player x" << m_PlayerPos.x << std::endl;
	std::cout << "Player y" << m_PlayerPos.y << std::endl;
	std::cout << "x�ι�° ��°��" << m_LinePos[1].x << std::endl;
	std::cout << "y�ι�° ��°��" << m_LinePos[1].y << std::endl;
}

void GroundMgr::Update(float deltaTime, float time)
{
}

void GroundMgr::Render()
{
}
