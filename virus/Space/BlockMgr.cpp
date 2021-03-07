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
	if (tag == "player") { //Ŭ��, ġ��Ǹ� ����Ʈ �������� ����
		m_Blocks = Sprite::Create(L"Painting/Block/Player.png");
		m_Blocks->A = 200;
	}	
	if (tag == "ground") {
		m_Blocks = Sprite::Create(L"Painting/Block/Ground.png");
		m_Blocks->A = 200;	
	}
	//item
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
	//obstacle(��ֹ�)
	if (tag == "column") {
		m_Blocks = Sprite::Create(L"Painting/Obstacle/Column.png");
		m_Blocks->A = 200;
	}
	
	//enemy 
	if (tag == "fast") {
		m_Blocks = Sprite::Create(L"Painting/Enemy/Fast.png");
	}
	if (tag == "flash") {
		m_Blocks = Sprite::Create(L"Painting/Enemy/Flash.png");
	}
	if (tag == "giant") {
		m_Blocks = Sprite::Create(L"Painting/Enemy/Giant.png");
	}
	if (tag == "toxino") {
		m_Blocks = Sprite::Create(L"Painting/Enemy/Toxino.png");
	}
	m_Blocks->SetParent(this);
	SetPosition(Pos.x, Pos.y);
	_tag = tag;
}

void BlockMgr::Update(float deltaTime, float time)
{
	// ������, 2���������� �Ѿ�� �������
	if (_tag == "fast") { 
	}
	if (_tag == "flash") {
	}
	if (_tag == "giant") {
	}
	if (_tag == "toxino") {
	}
}

void BlockMgr::Render()
{
	m_Blocks->Render();
}

void BlockMgr::OnCollision(Object* other)
{
}
