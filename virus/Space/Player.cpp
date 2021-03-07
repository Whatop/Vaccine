#include "stdafx.h"
#include "Player.h"
#include "BlockMgr.h"

Player::Player(Vec2 Pos) // ����¿� ���� ĳ���� ������ ���Ѵٳ׿�
{
	m_Player = Sprite::Create(L"Painting/Block/Player.png");
	m_Player->SetParent(this);
	SetPosition(Pos.x,Pos.y);

	m_TileSize = Vec2(40, 40);
	m_GridSize = Vec2(40, 40);
		
	Movement = false;
	jtime = 0.f;
	m_Hp = 5;
}

Player::~Player()
{
}

void Player::CheatKey()
{
	if (INPUT->GetKey(VK_F1) == KeyState::PRESS) // ����
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey(VK_F2) == KeyState::PRESS) // ������ ���� ���
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey(VK_F3) == KeyState::PRESS) // ����� ����
	{
		if (m_Hp < 5)
			m_Hp += 1;
	}
	if (INPUT->GetKey(VK_F4) == KeyState::PRESS) // �޴�ȭ�� �̵�
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey(VK_F5) == KeyState::PRESS) // �������� 1 �̵�
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey(VK_F6) == KeyState::PRESS) // �������� 2 �̵�
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
}

void Player::Update(float deltaTime, float Time) // BlockMgr bool ���� �����ϴ븶�� �Ѱ��� ���� �� �߰��ؾ� �ɼ�������
{
	jtime += dt;
	
	if (jtime >= 0.2f) {
		if (INPUT->GetKey('W') == KeyState::PRESS && m_Position.y > 60)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
				Movement = false;
			}
			m_Position.y -= 40;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x > 60)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
				Movement = false;
			}
			m_Position.x -= 40;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('S') == KeyState::PRESS && m_Position.y < 1020)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
				Movement = false;
			}
			m_Position.y += 40;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x < 1840)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
				Movement = false;
			}
			m_Position.x += 40;
			jtime = 0.f;
		}
	}
}

void Player::Render()
{
	m_Player->Render();
}

void Player::OnCollision(Object* obj)
{
	//�����۱���
}
