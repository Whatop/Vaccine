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
	std::cout << arr << "��° ��" << std::endl;
}

void GroundMgr::Fill()// �÷��̾� ��ġ�� ���� ��ġ ���̿� ���� ä������
{
	// ���� �����ʰ� ���� ä�ﶧ
	//m_InPos.x = m_PlayerPos.x - m_LinePos[1].x;
	//m_InPos.y = m_PlayerPos.y - m_LinePos[1].y;
	if (m_PlayerPos.x > m_LinePos[1].x) { // �÷��̾ ���κ��� Ŭ��
		for (int i = 40; m_PlayerPos.x - i < m_LinePos[1].x; i += 40) {
			if (m_PlayerPos.y > m_LinePos[1].y) { // �÷��̾ ���κ��� Ŭ��
				for (int j = 40; m_PlayerPos.y + j < m_LinePos[1].y; j += 40) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y + j), "clone"), "Clone");//�̰Ŷ� �÷��̾ ��ȯ�ϴ� �װŶ� ������ ���������
				}
			}
			else {// �÷��̾ ���κ��� ������
				for (int j = 40; m_PlayerPos.y - j < m_LinePos[1].y; j += 40) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x - i, m_PlayerPos.y - j), "clone"), "Clone");//�̰Ŷ� �÷��̾ ��ȯ�ϴ� �װŶ� ������ ���������
				}
			}
		}
	}
	else { //������ �÷��̾�� Ŭ��
		for (int i = 40; m_PlayerPos.x + i > m_LinePos[1].x; i += 40) {
			if (m_PlayerPos.y > m_LinePos[1].y) { // �÷��̾ ���κ��� Ŭ��
				for (int j = 40; m_PlayerPos.y + j < m_LinePos[1].y; j += 40) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y + j), "clone"), "Clone");//�̰Ŷ� �÷��̾ ��ȯ�ϴ� �װŶ� ������ ���������
				}
			}
			else {// �÷��̾ ���κ��� ������
				for (int j = 40; m_PlayerPos.y - j < m_LinePos[1].y; j += 40) {
					ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x + i, m_PlayerPos.y - j), "clone"), "Clone");//�̰Ŷ� �÷��̾ ��ȯ�ϴ� �װŶ� ������ ���������
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
