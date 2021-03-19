#include "stdafx.h"
#include "Player.h"
#include "BlockMgr.h"
#include "Stage1.h"
#include "Stage2.h"

Player::Player(Vec2 Pos) // ����¿� ���� ĳ���� ������ ���Ѵٳ׿�
{
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
		m_Player = Sprite::Create(L"Painting/Stage1/Block/Player.png");
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
		m_Player = Sprite::Create(L"Painting/Stage2/Block/Player.png");
	m_Player->SetParent(this);
	SetPosition(Pos.x, Pos.y);

	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) {
		m_TileSize = Vec2(60, 60);
		m_GridSize = Vec2(60, 60);
		xlimit = 90;
		ylimit = 90;
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2) {
		m_TileSize = Vec2(40, 40);
		m_GridSize = Vec2(40, 40);
		xlimit = 60;
		ylimit = 60;
	}
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
	m_Layer = 3;
	m_State = MoveState::NONE;

	m_Line = new LineMgr();
	m_Line->Init(1, true);
	m_Line->SetColor(D3DXCOLOR(255, 255, 255, 255));

	GameMgr::GetInst()->PlayerPos(m_Position);
}

Player::~Player()
{
}

void Player::CheatKey()
{
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN) // ����
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	else if (INPUT->GetKey(VK_F2) == KeyState::DOWN) // ������ ���� ���
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	else if (INPUT->GetKey(VK_F3) == KeyState::DOWN) // ����� ����
	{
		if (m_Hp < 5)
			m_Hp += 1;
	}
}

void Player::Buff()
{
	if (_Speed) {
		itime += dt;
		limit = 0.1f;
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

void Player::Move()
{
	jtime += dt;
	if (jtime >= limit) {
		if (INPUT->GetKey('W') == KeyState::PRESS && m_Position.y > ylimit)
		{
			//if (!create)
				//ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");

			if (m_State == MoveState::NONE) {
				Movement = _up;
			}
			if (Movement != _up && Movement != _down) {
				GameMgr::GetInst()->LinePos(m_Position);
				Movement = _up;
			}
			if (m_State == MoveState::UP) {
				Movement = _up;
			}
			m_State = MoveState::UP;

			m_Position.y -= m_Speed;
			jtime = 0.f;

		}
		else if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x > xlimit)
		{
			///if (!create)
			//	ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
			if (m_State == MoveState::NONE) {
				Movement = _left;
			}
			if (Movement != _left && Movement != _right) {
				GameMgr::GetInst()->LinePos(m_Position);
				Movement = _left;
			}
			if (m_State == MoveState::LEFT) {
				Movement = _left;
			}
			m_State = MoveState::LEFT;

			m_Position.x -= m_Speed;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('S') == KeyState::PRESS && m_Position.y < 1080 - ylimit)
		{
			//if (!create)
				//ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
			if (m_State == MoveState::NONE) {
				Movement = _down;
			}
			if (Movement != _up && Movement != _down) {
				GameMgr::GetInst()->LinePos(m_Position);
				Movement = _down;
			}
			if (m_State == MoveState::DOWN) {
				Movement = _down;
			}
			m_State = MoveState::DOWN;

			m_Position.y += m_Speed;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x < 1920 - xlimit)
		{
			//if (!create)
			//	ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");

			if (m_State == MoveState::NONE) {
				Movement = _right;
			}
			if (Movement != _left && Movement != _right) {
				GameMgr::GetInst()->LinePos(m_Position);
				Movement = _right;
			}
			if (m_State == MoveState::RIGHT) {
				Movement = _right;
			}
			m_State = MoveState::RIGHT;

			m_Position.x += m_Speed;
			jtime = 0.f;
		}
	}
}

void Player::Update(float deltaTime, float Time) // BlockMgr bool ���� �����ϴ븶�� �Ѱ��� ���� �� �߰��ؾ� �ɼ�������
{
	Move();
	CheatKey();
	Buff();
	create = false;
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
		m_Speed = 60;
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
		m_Speed = 40;

	if (INPUT->GetKey('O') == KeyState::DOWN) //Ŭ�п��� ��ų� FULL �ϰ� ���� �ٷ�
		GameMgr::GetInst()->PlayerPos(m_Position);
	if (INPUT->GetKey('P') == KeyState::DOWN) //Ŭ��, ġ��� �κ��̶� ������ ���ϵ��� ����
		GameMgr::GetInst()->LinePos(m_Position);
	if (INPUT->GetKey('F') == KeyState::DOWN) {
		//���ư��ų� ���� ��´ٸ� ���� Ŭ�а� ������� �ʱ���ġ�� �ʱ�ȭ�Ѵٸ�? 
		GameMgr::GetInst()->Fill();
		GameMgr::GetInst()->PlayerPos(m_Position);
	}
	ObjMgr->CollisionCheak(this, "Speed");
	ObjMgr->CollisionCheak(this, "Ammor");
	ObjMgr->CollisionCheak(this, "Heal");
	ObjMgr->CollisionCheak(this, "Invincible");
	ObjMgr->CollisionCheak(this, "Random");
	ObjMgr->CollisionCheak(this, "Pull");
	ObjMgr->CollisionCheak(this, "Clone");
	//
}
void Player::Render()
{
	m_Player->Render();
	m_Line->DrawLine(GameMgr::GetInst()->m_LinePos, 5);
	GameMgr::GetInst()->Draw();
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
	if (obj->m_Tag == "Pull") {  //Ŭ���� Pull�� �ƿ� �ٲٴ� �������� �ؾ߰��� ���� �׳� Ŭ�� �߹ٵ� ����Ǽ�, Clone�� �ϼ��Ǹ� �׳� Pull�� �ٲٱ�
		create = true;
		m_State = MoveState::NONE;
		GameMgr::GetInst()->PlayerPos(m_Position);
	}
	if (obj->m_Tag == "Clone") {  //Ŭ���� Pull�� �ƿ� �ٲٴ� �������� �ؾ߰��� ���� �׳� Ŭ�� �߹ٵ� ����Ǽ�, Clone�� �ϼ��Ǹ� �׳� Pull�� �ٲٱ�
		create = true;
		GameMgr::GetInst()->PlayerPos(m_Position);
	} // ���� ������ �簢���̶�� �׳� ū ������ �ҷ����� ���� ���� �� ���� ���� �ʹ� �ɸ�

}
