#include "stdafx.h"
#include "BlockMgr.h"

BlockMgr::BlockMgr(Vec2 Pos,std::string tag)
{
	type_item = false;
	type_enemy = false;
	flashstack = 0;
	flashtime = 0;
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
			m_Layer = -1;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Ground.png");
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
		}

		//enemy 
		if (tag == "fast") { //크기 1 
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Fast.png");
			type_enemy = true;
			m_Hp = 1;
		}

		if (tag == "flash") {//크기 1~2
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Flash.png");
			m_Hp = 1;
			type_enemy = true;
			Moveif = 0.75f;
		}
		if (tag == "flashgiant") {//크기 1~2
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/FlashGiant.png");
			m_Hp = 1;
			type_enemy = true;
			Moveif = 0.75f;
		}
		if (tag == "giant") {//크기 4
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Giant.png");
			type_enemy = true;
			m_Hp = 1;
		}
		if (tag == "toxino") {//크기 4
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Toxino.png");
			type_enemy = true;
			m_Hp = 3;
		}
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2) {
		m_Speed = 40.f;
		if (tag == "clone") { //클론, 치료되면 이팩트 나오도록 설정 pull 이랑 만났을때 생성 안되도록
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Clone.png");
			m_Layer = -1;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Ground.png");
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
		}

		//enemy 
		if (tag == "fast") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Fast.png");
			 type_enemy = true;
			 m_Hp = 1;
		}
		if (tag == "flash") {//크기 1~2
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Flash.png");
			m_Hp = 1;
			type_enemy = true;
			Moveif = 0.75f;
		}
		if (tag == "flashgiant") {//크기 1~2
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/FlashGiant.png");
			m_Hp = 1;
			type_enemy = true;
			Moveif = 0.75f;
		}
		if (tag == "giant") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Giant.png");
			type_enemy = true;
			m_Hp = 1;
		}
		if (tag == "toxino") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Toxino.png");
			type_enemy = true;
			m_Hp = 3;
		}
	}
	m_Blocks->SetParent(this);
	SetPosition(Pos.x, Pos.y);
	_tag = tag;
}

void BlockMgr::Update(float deltaTime, float time)
{
	MoveTime += dt;
	//enemy 움직임, 2스테이지로 넘어가면 성능향상
	if (_tag == "fast") { // Fill이랑 닿으면 속도 업 + Clone이랑 닿으면 플레이어 피해 입음
		// 백신선이나 백신에 붙이치면 붉은 Effect나오며 사라짐
		if (MoveTime > 0.5f) {

				if (GameMgr::GetInst()->m_LinePos[0].x > m_Position.x && m_Position.x < 1920 - m_Speed) {
					Translate(m_Speed, 0);
				}
				else if( GameMgr::GetInst()->m_LinePos[0].x < m_Position.x && m_Position.x > 0 + m_Speed){
					Translate(-m_Speed, 0);
				}
				else if (GameMgr::GetInst()->m_LinePos[0].y > m_Position.y && m_Position.x < 1080 - m_Speed) {
					Translate(0, m_Speed);
				}
				else if(GameMgr::GetInst()->m_LinePos[0].y < m_Position.y && m_Position.y > 0 + m_Speed){
					Translate(0, -m_Speed);
				}
		
			MoveTime = 0;
		}
	}
	
	if (_tag == "flash") {
		if (MoveTime > Moveif) {

				if (GameMgr::GetInst()->m_LinePos[0].x > m_Position.x && m_Position.x < 1920 - m_Speed) {
					Translate(m_Speed, 0);
					if (flashstack != 3)
						flashstack++;
				}
				else if (GameMgr::GetInst()->m_LinePos[0].x < m_Position.x && m_Position.x > 0 + m_Speed) {
					Translate(-m_Speed, 0);
					if (flashstack != 3)
						flashstack++;
				}
				else if (GameMgr::GetInst()->m_LinePos[0].y > m_Position.y && m_Position.x < 1080 - m_Speed) {
					Translate(0, m_Speed);
					if (flashstack != 3)
						flashstack++;
				}
				else if (GameMgr::GetInst()->m_LinePos[0].y < m_Position.y && m_Position.y > 0 + m_Speed) {
					Translate(0, -m_Speed);
					if (flashstack != 3)
						flashstack++;
			}
			if (flashstack == 3) {
				flashtime += 1;
				m_Blocks->A = 0;
				Moveif = 0.2f;
				if (flashtime > 5) {
					m_Blocks->A = 255;
					flashstack = 0;
					flashtime = 0;
					Moveif = 0.75f;
				}
			}

			MoveTime = 0;
		}
	}

	if (_tag == "flashgiant") {
		if (MoveTime > Moveif) {

				if (GameMgr::GetInst()->m_LinePos[0].x > m_Position.x && m_Position.x < 1920 - m_Speed) {
					Translate(m_Speed, 0);
					if (flashstack != 3)
						flashstack++;
				}
				else if (GameMgr::GetInst()->m_LinePos[0].x < m_Position.x && m_Position.x > 0 + m_Speed) {
					Translate(-m_Speed, 0);
					if (flashstack != 3)
						flashstack++;
				}
				else if (GameMgr::GetInst()->m_LinePos[0].y > m_Position.y && m_Position.x < 1080 - m_Speed) {
					Translate(0, m_Speed);
					if (flashstack != 3)
						flashstack++;
				}
				else if (GameMgr::GetInst()->m_LinePos[0].y < m_Position.y && m_Position.y > 0 + m_Speed) {
					Translate(0, -m_Speed);
					if (flashstack != 3)
						flashstack++;
				}
			
			if (flashstack == 3) {
				flashtime += 1;
				m_Blocks->A = 0;
				Moveif = 0.2f;
				if (flashtime > 5) {
					m_Blocks->A = 255;
					flashtime = 0;
					flashstack = 0;
					Moveif = 0.75f;
				}
			}

			MoveTime = 0;
		}
	}  

	if (_tag == "giant") {
		if (MoveTime > 1) {
			int XorY = rand() % 1 + 0;

			if (XorY) { // X
				if (GameMgr::GetInst()->m_LinePos[0].x > m_Position.x) {
					Translate(m_Speed, 0);
				}
				else {
					Translate(-m_Speed, 0);
				}
			}
			if (!XorY) { // Y
				if (GameMgr::GetInst()->m_LinePos[0].y > m_Position.y) {
					Translate(0, m_Speed);
				}
				else {
					Translate(0, -m_Speed);
				}
			}
		}
	}
	if (_tag == "toxino") {
		if (MoveTime > 0.5f) {
			int XorY = rand() % 1 + 0;

			if (XorY) { // X
				if (GameMgr::GetInst()->m_LinePos[0].x > m_Position.x) {
					Translate(m_Speed, 0);
				}
				else {
					Translate(-m_Speed, 0);
				}
			}
			if (!XorY) { // Y
				if (GameMgr::GetInst()->m_LinePos[0].y > m_Position.y) {
					Translate(0, m_Speed);
				}
				else {
					Translate(0, -m_Speed);
				}
			}
		}
	}

	if (_tag == "clone") { // 
		ObjMgr->CollisionCheak(this, "Fill");
	}
	if (type_enemy && flashstack != 3) {
		ObjMgr->CollisionCheak(this, "ColBox");
		if(m_Hp <= 0)
			ObjMgr->RemoveObject(this);
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
		if (other->m_Tag == "Fill") {
				ObjMgr->RemoveObject(this);
			//이팩트 넣어야지
		} 
	}
	if (type_enemy) {
		if (other->m_Tag == "ColBox") {
			
			//이팩트 넣어야지
			m_Hp -= 1; //피 달고 저거 불 판정 넣고 
		}
	}
}
