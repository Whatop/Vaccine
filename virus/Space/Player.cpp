#include "stdafx.h"
#include "Player.h"
#include "BlockMgr.h"

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);
	SetPosition(Pos.x,Pos.y);

	m_TileSize = Vec2(40, 40);
	m_GridSize = Vec2(40, 40);

	Movement = false;
}

Player::~Player()
{
}

void Player::Update(float deltaTime, float Time) // BlockMgr bool 만들어서 움직일대마다 한개씩 조건 더 추가해야 될수도있음
{
	if (INPUT->GetKey(VK_F2) == KeyState::PRESS)
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey('W') == KeyState::DOWN&&m_Position.y > 20)
	{
		Movement = true;
		if (Movement) {
			ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
			Movement = false;
		}
		m_Position.y -= 40;
	}
	else if (INPUT->GetKey('A') == KeyState::DOWN && m_Position.x > 20)
	{ 
		Movement = true;
		if (Movement) {
			ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
			Movement = false;
		}
		m_Position.x -= 40;
	}
	else if (INPUT->GetKey('S') == KeyState::DOWN && m_Position.y < 1060)
	{
		Movement = true;
		if (Movement) {
			ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
			Movement = false;
		}
		m_Position.y += 40;
	}
	else if (INPUT->GetKey('D') == KeyState::DOWN && m_Position.y < 1900)
	{
		Movement = true;
		if (Movement) {
			ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
			Movement = false;
		}
		m_Position.x += 40;
	}

}

void Player::Render()
{
	m_Player->Render();
}

void Player::OnCollision(Object* obj)
{
}
