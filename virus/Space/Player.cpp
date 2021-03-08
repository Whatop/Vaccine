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
	itime = 0.f;
	limit = 0.2f;
	m_Hp = 5;
	m_Speed = 40;

	_Speed = false;
	_Heal = false;
	_Invincible = false;
	_Ammor = false;
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

void Player::Buff()
{
	
	if (_Speed) {
		itime += dt;
		limit= 0.1f;
		if (itime >= 5.f) {
			_Speed = false;
			itime = 0;
			limit = 0.2f;
		}
	}
	else if (_Ammor) {

	}
	else if (_Invincible) {

	}
	else if (_Heal) {
		if (m_Hp < 5)
			m_Hp += 1; 
		//else
		//score ��������
	}
	UI::GetInst()->m_Hp = m_Hp; 
}

void Player::Update(float deltaTime, float Time) // BlockMgr bool ���� �����ϴ븶�� �Ѱ��� ���� �� �߰��ؾ� �ɼ�������
{
	ObjMgr->CollisionCheak(this, "Speed");
	ObjMgr->CollisionCheak(this, "Ammor");
	ObjMgr->CollisionCheak(this, "Heal");
	ObjMgr->CollisionCheak(this, "Invincible");
	ObjMgr->CollisionCheak(this, "Random");

	jtime += dt;
	
	if (jtime >= limit) {
		if (INPUT->GetKey('W') == KeyState::PRESS && m_Position.y > 60)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
				Movement = false;
			}
			m_Position.y -= m_Speed;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x > 60)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
				Movement = false;
			}
			m_Position.x -= m_Speed;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('S') == KeyState::PRESS && m_Position.y < 1020)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
				Movement = false;
			}
			m_Position.y += m_Speed;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x < 1840)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "player"), "Clone");
				Movement = false;
			}
			m_Position.x += m_Speed;
			jtime = 0.f;
		}
	}

	CheatKey();
	Buff();
}

void Player::Render()
{
	m_Player->Render();
}

void Player::OnCollision(Object* obj)
{
	//�����۱���
	if (obj->m_Tag == "Speed") {
		_Speed = true;
	}
	if (obj->m_Tag == "Ammor") {
		_Ammor = true;
	}
	if (obj->m_Tag == "Invincible") {
		_Invincible = true;
	}
	if (obj->m_Tag == "Heal") {
		_Heal = true;
	}
}
