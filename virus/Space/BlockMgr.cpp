#include "stdafx.h"
#include "BlockMgr.h"

BlockMgr::BlockMgr(Vec2 Pos,std::string tag)
{
	type_item = false;
	type_enemy = false;
	BlockType(tag,Pos);
}

BlockMgr::~BlockMgr()
{
}
//속도 2칸씩이동 
void BlockMgr::BlockType(std::string tag,Vec2 Pos) // Clone ,아이템(속도,방어력,무적,생명력),Enemy(속도,크기,점멸,톡시노)
{
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) {
		if (tag == "clone") { //클론, 치료되면 이팩트 나오도록 설정
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Player.png");
			m_Blocks->A = 200;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Ground.png");
			m_Blocks->A = 200;
		}
		if (tag == "pull") { //안에 채워주는 친구
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Pull.png");
		}
		//item
		if (tag == "speed") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Speed.png");
			type_item = true;
		}
		if (tag == "ammor") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Ammor.png");
			type_item = true;
		}
		if (tag == "invincible") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Invincible.png");
			type_item = true;
		}
		if (tag == "heal") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Heal.png");
			type_item = true;
		}
		if (tag == "random") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Random.png");
			type_item = true;
		}
		//obstacle(장애물)
		if (tag == "column") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Obstacle/Column.png");
			m_Blocks->A = 200;
		}

		//enemy 
		if (tag == "fast") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Fast.png");
		}
		if (tag == "flash") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Flash.png");
		}
		if (tag == "giant") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Giant.png");
		}
		if (tag == "toxino") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Toxino.png");
		}
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2) {
		if (tag == "clone") { //클론, 치료되면 이팩트 나오도록 설정
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Player.png");
			m_Blocks->A = 200;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Ground.png");
			m_Blocks->A = 200;
		}
		if (tag == "pull") { //안에 채워주는 친구
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Pull.png");
		}
		//item
		if (tag == "speed") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Speed.png");
			type_item = true;
		}
		if (tag == "ammor") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Ammor.png");
			type_item = true;
		}
		if (tag == "invincible") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Invincible.png");
			type_item = true;
		}
		if (tag == "heal") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Heal.png");
			type_item = true;
		}
		if (tag == "random") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Random.png");
			type_item = true;
		}
		//obstacle(장애물)
		if (tag == "column") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Obstacle/Column.png");
			m_Blocks->A = 200;
		}

		//enemy 
		if (tag == "fast") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Fast.png");
		}
		if (tag == "flash") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Flash.png");
		}
		if (tag == "giant") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Giant.png");
		}
		if (tag == "toxino") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Toxino.png");
		}
	}
	m_Blocks->SetParent(this);
	SetPosition(Pos.x, Pos.y);
	_tag = tag;
}

void BlockMgr::Update(float deltaTime, float time)
{
	//enemy 움직임, 2스테이지로 넘어가면 성능향상
	if (_tag == "fast") { 
		// 백신선이나 백신에 붙이치면 붉은 Effect나오며 사라짐
	}
	if (_tag == "flash") {
	}
	if (_tag == "giant") {
	}
	if (_tag == "toxino") {
	}
	
	if (_tag == "pull") {

	}
}

void BlockMgr::Render()
{
	m_Blocks->Render();
}

void BlockMgr::OnCollision(Object* other)
{
	//item
	if (type_item) {
		if (other->m_Tag == "Player") {
			ObjMgr->RemoveObject(this);
		}
	}
	if (_tag == "pull") {
		if (other->m_Tag == "Player") {
			ObjMgr->RemoveObject(this);
		}
	}
}
