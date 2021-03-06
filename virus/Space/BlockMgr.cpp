#include "stdafx.h"
#include "BlockMgr.h"

BlockMgr::BlockMgr(Vec2 Pos,std::string tag)
{
	BlockType(tag,Pos);
}

BlockMgr::~BlockMgr()
{
}

void BlockMgr::BlockType(std::string tag,Vec2 Pos) // Clone , Enemy(¼Óµµ,Å©±â,Á¡¸ê,Åå½Ã³ë)
{
	if (tag == "player") {
		m_Blocks = Sprite::Create(L"Painting/Player.png");
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
