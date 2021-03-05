#include "stdafx.h"
#include "Player.h"

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);
	SetPosition(Pos.x,Pos.y);

	m_TileSize = Vec2(40, 40);
	m_GridSize = Vec2(40, 40);
}

Player::~Player()
{
}

void Player::Update(float deltaTime, float Time)
{
	if (INPUT->GetKey(VK_F2) == KeyState::PRESS)
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey('W') == KeyState::PRESS)
	{
		m_Position.y -= 40;
	}
	else if (INPUT->GetKey('A') == KeyState::PRESS)
	{ 
		m_Position.x -= 40;
	}
	else if (INPUT->GetKey('S') == KeyState::PRESS)
	{
		m_Position.y += 40;
	}
	else if (INPUT->GetKey('D') == KeyState::PRESS)
	{
		m_Position.x += 40;
	}
	if ((m_Position.x / m_GridSize.x) * m_GridSize.x < 0 && (m_Position.y / m_GridSize.y) * m_GridSize.y < 0)
		SetPosition((int)(m_Position.x / m_GridSize.x) * m_GridSize.x - m_GridSize.x, (int)(m_Position.y / m_GridSize.y) * m_GridSize.y - m_GridSize.y);
	else if ((m_Position.x / m_GridSize.x) * m_GridSize.x < 0)
		SetPosition((int)(m_Position.x / m_GridSize.x) * m_GridSize.x - m_GridSize.x, (int)(m_Position.y / m_GridSize.y) * m_GridSize.y);
	else if ((m_Position.y / m_GridSize.y) * m_GridSize.y < 0)
		SetPosition((int)(m_Position.x / m_GridSize.x) * m_GridSize.x, (int)(m_Position.y / m_GridSize.y) * m_GridSize.y - m_GridSize.y);
	else
		SetPosition((int)(m_Position.x / m_GridSize.x) * m_GridSize.x, (int)(m_Position.y / m_GridSize.y) * m_GridSize.y);

}

void Player::Render()
{
	m_Player->Render();
}

void Player::OnCollision(Object* obj)
{
}
