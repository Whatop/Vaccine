#include "stdafx.h"
#include "BlockMgr.h"

BlockMgr::BlockMgr(Vec2 Pos,std::string tag)
{
	BlockType(tag,Pos);
}

BlockMgr::~BlockMgr()
{
}
//�ӵ� 2ĭ���̵� 
void BlockMgr::BlockType(std::string tag,Vec2 Pos) // Clone ,������(�ӵ�,����,����,�����),Enemy(�ӵ�,ũ��,����,��ó�)
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
