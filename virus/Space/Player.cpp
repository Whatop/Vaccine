#include "stdafx.h"
#include "Player.h"
#include "BlockMgr.h"

Player::Player(Vec2 Pos) // 생명력에 따라 캐릭터 색깔이 변한다네요
{
	if(SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
		m_Player = Sprite::Create(L"Painting/Stage1/Block/Player.png");
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
		m_Player = Sprite::Create(L"Painting/Stage2/Block/Player.png");
	m_Player->SetParent(this);
	SetPosition(Pos.x,Pos.y);

	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) {
		m_TileSize = Vec2(60, 60);
		m_GridSize = Vec2(60, 60);
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2) {
		m_TileSize = Vec2(40, 40);
		m_GridSize = Vec2(40, 40);
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
	m_Layer = 1;
}

Player::~Player()
{
}

void Player::CheatKey()
{
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN) // 무적
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey(VK_F2) == KeyState::DOWN) // 아이템 랜덤 사용
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey(VK_F3) == KeyState::DOWN) // 생명력 증가
	{
		if (m_Hp < 5)
			m_Hp += 1;
	}
	if (INPUT->GetKey(VK_F4) == KeyState::DOWN) // 메뉴화면 이동
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey(VK_F5) == KeyState::DOWN) // 스테이지 1 이동
	{
		std::cout << m_Position.x << std::endl;
		std::cout << m_Position.y << std::endl;
	}
	if (INPUT->GetKey(VK_F6) == KeyState::DOWN) // 스테이지 2 이동
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
		//score 오르도록
	}
	UI::GetInst()->m_Hp = m_Hp; 
}

void Player::Update(float deltaTime, float Time) // BlockMgr bool 만들어서 움직일대마다 한개씩 조건 더 추가해야 될수도있음
{
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
		m_Speed = 60;
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
		m_Speed = 40;
	if (INPUT->GetKey('O') == KeyState::DOWN)
		GroundMgr::GetInst()->PlayerPos(m_Position);
	if (INPUT->GetKey('P') == KeyState::DOWN)
		GroundMgr::GetInst()->LinePos(m_Position);
	if (INPUT->GetKey('F') == KeyState::DOWN) {//PlayerPos랑 LinePos가 같다면 x나 y 축이 같지 않고 초기 위치로
												//돌아가거나 벽에 닿는다면 실행 클론과 닿았을때 초기위치를 초기화한다면? 
												//문제가 될까? 
		GroundMgr::GetInst()->Fill();
	}
	ObjMgr->CollisionCheak(this, "Speed");
	ObjMgr->CollisionCheak(this, "Ammor");
	ObjMgr->CollisionCheak(this, "Heal");
	ObjMgr->CollisionCheak(this, "Invincible");
	ObjMgr->CollisionCheak(this, "Random");

	jtime += dt;
	
	if (jtime >= limit && SceneDirector::GetInst()->GetScene()==SceneState::STAGE2) {
		if (INPUT->GetKey('W') == KeyState::PRESS && m_Position.y > 60)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
				Movement = false;
			}
			m_Position.y -= m_Speed;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x > 60)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
				Movement = false;
			}
			m_Position.x -= m_Speed;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('S') == KeyState::PRESS && m_Position.y < 1020)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
				Movement = false;
			}
			m_Position.y += m_Speed;
			jtime = 0.f;
		}
		else if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x < 1840)
		{
			Movement = true;
			if (Movement) {
				ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
				Movement = false;
			}
			m_Position.x += m_Speed;
			jtime = 0.f;
		}
	}
	else if (jtime >= limit && SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) {
	if (INPUT->GetKey('W') == KeyState::PRESS && m_Position.y > 90)
	{
		Movement = true;
		if (Movement) {
			ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
			Movement = false;
		}
		m_Position.y -= m_Speed;
		jtime = 0.f;
	}
	else if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x > 90)
	{
		Movement = true;
		if (Movement) {
			ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
			Movement = false;
		}
		m_Position.x -= m_Speed;
		jtime = 0.f;
	}
	else if (INPUT->GetKey('S') == KeyState::PRESS && m_Position.y < 990)
	{
		Movement = true;
		if (Movement) {
			ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
			Movement = false;
		}
		m_Position.y += m_Speed;
		jtime = 0.f;
	}
	else if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x < 1830)
	{
		Movement = true;
		if (Movement) {
			ObjMgr->AddObject(new BlockMgr(Vec2(m_Position.x, m_Position.y), "clone"), "Clone");
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
	//아이템구현
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
