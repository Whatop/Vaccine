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
	arr++;
	std::cout << arr << "��° ��" << std::endl;
}

void GroundMgr::Fill()// �ȿ� ä���ִ� ģ�� ����,��ġ ���� �ڵ���
{
	//�̰��� �ʱ� ��ġ�� ���ư�����
	if (m_PlayerPos.x > m_LinePos[1].x) {
			if (m_PlayerPos.y > m_LinePos[1].y) { 
				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x-60, m_PlayerPos.y- 60), "pull"), "Ground");//
			}
			else {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x- 60, m_PlayerPos.y+ 60), "pull"), "Ground");//
			}
	}
	else { 
			if (m_PlayerPos.y > m_LinePos[1].y) { 
				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x+ 60, m_PlayerPos.y - 60), "pull"), "Ground");//
			}
			else {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_PlayerPos.x+ 60, m_PlayerPos.y + 60), "pull"), "Ground");//
			}
	}
}

void GroundMgr::Update(float deltaTime, float time)
{
}

void GroundMgr::Render()
{
}
