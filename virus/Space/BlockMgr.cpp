#include "stdafx.h"
#include "BlockMgr.h"

BlockMgr::BlockMgr(Vec2 Pos,std::string tag)
{
	BlockType(tag,Pos);
}

BlockMgr::~BlockMgr()
{
}
//속도 2칸씩이동 
void BlockMgr::BlockType(std::string tag,Vec2 Pos) // Clone ,아이템(속도,방어력,무적,생명력),Enemy(속도,크기,점멸,톡시노)
{
	if (tag == "player") {
		m_Blocks = Sprite::Create(L"Painting/Block/Player.png");
		m_Blocks->A = 200;
	}	
	if (tag == "ground") {
		m_Blocks = Sprite::Create(L"Painting/Block/Ground.png");
		m_Blocks->A = 200;	
	}
	if (tag == "speed") {
		m_Blocks = Sprite::Create(L"Painting/Block/Speed.png");
		m_Blocks->A = 200;
	}
	if (tag == "ammor") {
		m_Blocks = Sprite::Create(L"Painting/Block/Ammor.png");
		m_Blocks->A = 200;
	}
	if (tag == "invincible") {
		m_Blocks = Sprite::Create(L"Painting/Block/Invincible.png");
		m_Blocks->A = 200;
	}
	if (tag == "heal") {
		m_Blocks = Sprite::Create(L"Painting/Block/Heal.png");
		m_Blocks->A = 200;
	}
	if (tag == "random") {
		m_Blocks = Sprite::Create(L"Painting/Block/Random.png");
		m_Blocks->A = 200;
	}
	m_Blocks->SetParent(this);
	SetPosition(Pos.x, Pos.y);
}

void BlockMgr::Update(float deltaTime, float time)
{
}

void BlockMgr::Render()
{
	m_Blocks->Render();
}

void BlockMgr::OnCollision(Object* other)
{
}
