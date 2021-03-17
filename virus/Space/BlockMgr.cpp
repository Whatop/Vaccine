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
		m_Speed = 60.f;
		if (tag == "clone") { //클론, 치료되면 이팩트 나오도록 설정 pull 이랑 만났을때 생성 안되도록
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Clone.png");
			m_Layer = 2;
			m_Blocks->A = 100;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Ground.png");
			m_Blocks->A = 200;
		}
		if (tag == "pull") { //안에 채워주는 친구 
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Pull.png");
			m_Blocks->R = 0;
			m_Blocks->G = 255;
			m_Blocks->B = 0;
			m_Layer = 0;
		}
		if (tag == "clone-pull") { 
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Clone.png");
			m_Blocks->R = 0;
			m_Blocks->G = 255;
			m_Blocks->B = 0;
			m_Layer = 0;
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
		if (tag == "fast") { //크기 1 
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Fast.png");
		}
		if (tag == "flash") {//크기 1~2
			int random = rand() % 2 + 1;
			if (random == 1)
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Flash.png");

			if (random == 2)
				m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/FlashLong.png");
		}
		if (tag == "giant") {//크기 4
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Giant.png");
		}
		if (tag == "toxino") {//크기 4
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Toxino.png");
		}
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2) {
		m_Speed = 40.f;
		if (tag == "clone") { //클론, 치료되면 이팩트 나오도록 설정 pull 이랑 만났을때 생성 안되도록
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Clone.png");
			m_Layer = 2;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Ground.png");
			m_Blocks->A = 200;
		}
		if (tag == "pull") { //안에 채워주는 친구
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Pull.png");
		}
		if (tag == "clone-pull") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Pull.png");
			m_Blocks->R = 0;
			m_Blocks->G = 255;
			m_Blocks->B = 0;
			m_Layer = 0;
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
	
	if (_tag == "pull") { // 
		ObjMgr->CollisionCheak(this, "Clone");
		ObjMgr->CollisionCheak(this, "Player");
	}
	if (_tag == "clone-pull") { // 
			ObjMgr->CollisionCheak(this, "Player");
	}
	if (_tag == "clone") { // 
		ObjMgr->CollisionCheak(this, "Pull");
		ObjMgr->CollisionCheak(this, "Player");
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
	if (_tag == "clone") {
		if (other->m_Tag == "Pull") {
			ObjMgr->AddObject(new BlockMgr(m_Position, "clone-pull"), "Pull");
				ObjMgr->RemoveObject(this);
			//이팩트 넣어야지
		} 
	}
}
