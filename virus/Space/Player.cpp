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
	_Random = false;
	GODMODE = false;
	m_Layer = 3;
	m_State = MoveState::NONE;



	GameMgr::GetInst()->PlayerPos(m_Position);

	std::cout << m_Position.x << std::endl;
	std::cout << m_Position.y << std::endl;
}

Player::~Player()
{
}

void Player::CheatKey()
{
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN) // ����
	{
		if (GODMODE) {
			GODMODE = false;
			std::cout << "����off" << std::endl;
		}
		else {
			GODMODE = true;
			std::cout << "����on" << std::endl;
		}
	}
	else if (INPUT->GetKey(VK_F2) == KeyState::DOWN || _Random) // ������ ���� ���
	{
		int random = rand() % 4 + 1;

		if (random == 1) {
			_Speed = true;
			std::cout << "���ǵ�" << std::endl;
		}
		else if (random == 2) {
			_Invincible = true;
			std::cout << "��ù���" << std::endl;
		}
		else if (random == 3) {
			_Heal = true;
			std::cout << "ȸ��" << std::endl;
		}
		else if (random == 4) {
			_Ammor = true;
			std::cout << "���" << std::endl;
		}
		_Random = false;
	}
	else if (INPUT->GetKey(VK_F3) == KeyState::DOWN) // ����� ����
	{
		ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Invincible", 1, 1, 2, m_Position), "Effect");
		if (m_Hp < 5)
			m_Hp += 1;
		else
			GameMgr::GetInst()->AddScore(100);
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
	if (_Ammor) {
		//ObjMgr->AddObject(new EffectMgr())
		ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Defence", 1, 1, 2, m_Position), "Effect");
	}
	//}_Hit
	if (_Invincible) {
		ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/flash", 1, 1, 2, m_Position), "Effect");
		m_Invincible += dt;
		if (m_Invincible >= 3.f) {
			_Invincible = false;	 
			m_Invincible = 0;
		}
	}
	if (_Heal) {
		ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Invincible", 1, 1, 2, m_Position), "Effect");
		if (m_Hp < 5)
			m_Hp += 1;

		else
			GameMgr::GetInst()->AddScore(100);
		_Heal = false;
	}
	if (_Hit) {
		m_hit += dt;
		if (!_Ammor) {
			m_Player->R = 255;
		}
		if (m_hit > 0.1f)
			m_Player->A = 130;
		else if (m_hit > 0.2f)
			m_Player->A = 255;
		else if (m_hit > 0.3f)
			m_Player->A = 130;
		else if (m_hit > 0.4f)
			m_Player->A = 255;
		else if (m_hit > 0.5f)
			m_Player->A = 130;

		if (m_hit >= 0.6f) {
			_Hit = false;
			_Ammor = false;
			m_hit = 0;
			m_Player->A = 255;
			m_Player->R = 255;
			m_Player->G = 255;
			m_Player->B = 255;
		}
	}
}

void Player::Move()
{
	jtime += dt;
	if (jtime >= limit) {
		if (INPUT->GetKey('W') == KeyState::PRESS && m_Position.y > ylimit)
		{
			if (!create)
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");

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
			if (!create)
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
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
			if (!create)
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
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
			if (!create)
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");

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

void Player::Hp()
{
	GameMgr::GetInst()->m_Hp = m_Hp;
	UI::GetInst()->m_Hp = m_Hp;
	if (!_Hit) {
		if (m_Hp == 5) {
			m_Player->R = 116;
			m_Player->G = 192;
			m_Player->B = 99;
		}
		if (m_Hp == 4) {
			m_Player->R = 145;
			m_Player->G = 237;
			m_Player->B = 89;
		}
		if (m_Hp == 3) {
			m_Player->R = 211;
			m_Player->G = 237;
			m_Player->B = 89;
		}
		if (m_Hp == 2) {
			m_Player->R = 237;
			m_Player->G = 197;
			m_Player->B = 89;
		}
		if (m_Hp == 1) {
			m_Player->R = 237;
			m_Player->G = 123;
			m_Player->B = 61;
		}
		if (m_Hp <= 0) {
			m_Player->m_Visible = false;
			ObjMgr->DeleteObject("Clone");
			if (UI::GetInst()->TimeLimit < 0)
				ObjMgr->RemoveObject(this);

		}
		else
		{
			m_Player->m_Visible = true;
		}
		
	}
}

void Player::Update(float deltaTime, float Time) 
{
	GameMgr::GetInst()->HitCheak();
	GameMgr::GetInst()->m_PlayerPos = m_Position;
	GameMgr::GetInst()->_Ammor = _Ammor;
	GameMgr::GetInst()->_Invincible = _Invincible;
	GameMgr::GetInst()->Visible = m_Player->m_Visible;
	if (m_Hp > 0) 
		Move();

	CheatKey();
	Buff();
	Hp();
	create = false;
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
		m_Speed = 60;
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
		m_Speed = 40;


	if (INPUT->GetKey('P') == KeyState::DOWN) 
		GameMgr::GetInst()->LinePos(m_Position);
	if (INPUT->GetKey('F') == KeyState::DOWN || GameMgr::GetInst()->m_LinePos[0]==GameMgr::GetInst()->m_LinePos[4]||GameMgr::GetInst()->arr > 5) {
		GameMgr::GetInst()->Draw();
		GameMgr::GetInst()->PlayerPos(m_Position);
	}
	
	ObjMgr->CollisionCheak(this, "Fill");
	ObjMgr->CollisionCheak(this, "Clone");
	ObjMgr->CollisionCheak(this, "Column");
	if (!m_Invincible && !_Hit && !GODMODE) { 
		ObjMgr->CollisionCheak(this, "Monster");
	}

	if (GameMgr::GetInst()->_Hit&&!_Hit) {
		if(!_Ammor)
			m_Hp--;
			
		GameMgr::GetInst()->_Hit = false;
			_Hit = true;
		
	}

	//
	if (GameMgr::GetInst()->Keep) {
		m_Hp = 5;
		m_Player->m_Visible = true;
		GameMgr::GetInst()->Keep = false;

	}
}
void Player::Render() 
{
	m_Player->Render();

}

void Player::OnCollision(Object* obj)
{
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
	if (obj->m_Tag == "Random") {
		_Random = true;
	}
	if (obj->m_Tag == "Fill") {
		create = true;
		m_State = MoveState::NONE;
		GameMgr::GetInst()->arr = 0;
		GameMgr::GetInst()->PlayerPos(m_Position);
	}
	if (obj->m_Tag == "Clone") {
		create = true;
		GameMgr::GetInst()->LinePos(m_Position);
	}
	if (obj->m_Tag == "Column") {
		if (Movement == _up)		 {
			m_Position.y += m_Size.y;
		}
		else if (Movement == _down)  {
			m_Position.y -= m_Size.y;
		}
		else if (Movement == _right) {
			m_Position.x -= m_Size.x;
		}
		else if (Movement == _left)  {
			m_Position.x += m_Size.x;
		}
		m_Hp -= 1;
		_Hit = true;
	}
	if (obj->m_Tag == "Monster") {

		if (!_Hit) {
			if (!_Ammor) {
				m_Hp -= 1;
			}
			else if(_Ammor)
				_Ammor = false;

			_Hit = true;
		}
	}
}
