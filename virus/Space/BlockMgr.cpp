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
//�ӵ� 2ĭ���̵� 
void BlockMgr::BlockType(std::string tag,Vec2 Pos) // Clone ,������(�ӵ�,����,����,�����),Enemy(�ӵ�,ũ��,����,��ó�)
{
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) {
		m_Speed = 60.f;
		if (tag == "clone") { //Ŭ��, ġ��Ǹ� ����Ʈ �������� ���� pull �̶� �������� ���� �ȵǵ���
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
		//obstacle(��ֹ�)
		if (tag == "column") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Obstacle/Column.png");
		}

		//enemy 
		if (tag == "fast") { //ũ�� 1 
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Fast.png");
			type_enemy = true;
			m_Hp = 1;
		}

		if (tag == "flash") {//ũ�� 1~2
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Flash.png");
			m_Hp = 1;
			type_enemy = true;
			Moveif = 0.75f;
		}
		if (tag == "flashgiant") {//ũ�� 1~2
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/FlashGiant.png");
			m_Hp = 1;
			type_enemy = true;
			Moveif = 0.75f;
		}
		if (tag == "giant") {//ũ�� 4
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Giant.png");
			type_enemy = true;
			m_Hp = 1;
		}
		if (tag == "toxino") {//ũ�� 4
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Toxino.png");
			type_enemy = true;
			m_Hp = 3;
		}
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2) {
		m_Speed = 40.f;
		if (tag == "clone") { //Ŭ��, ġ��Ǹ� ����Ʈ �������� ���� pull �̶� �������� ���� �ȵǵ���
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
		//obstacle(��ֹ�)
		if (tag == "column") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Obstacle/Column.png");
		}

		//enemy 
		if (tag == "fast") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Fast.png");
			 type_enemy = true;
			 m_Hp = 1;
		}
		if (tag == "flash") {//ũ�� 1~2
			m_Blocks = Sprite::Create(L"Painting/Stage2/Enemy/Flash.png");
			m_Hp = 1;
			type_enemy = true;
			Moveif = 0.75f;
		}
		if (tag == "flashgiant") {//ũ�� 1~2
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
	if (type_item) {
		m_Blocks->m_Visible = false;
	}
		_tag = tag;
	efttect = true;
}

void BlockMgr::Update(float deltaTime, float time)
{
	Move();
	if (type_item) {
		if (m_Blocks->m_Visible == true) {
			ObjMgr->CollisionCheak(this, "Player");
		}
		ObjMgr->CollisionCheak(this, "Fill");
	}
	if (_tag == "clone") {
		if (GameMgr::GetInst()->_Invincible) {
			ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/flash", 1, 0.5f, 2, m_Position), "Effect");
		}
		else if (GameMgr::GetInst()->_Ammor) {
			ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Defence", 1, 0.5f, 2, m_Position), "Effect");
		}
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
		if (other->m_Tag == "Fill") {
			m_Blocks->m_Visible = true;
		}
	}
	if (_tag == "clone") {
		if (other->m_Tag == "Fill") {
				ObjMgr->RemoveObject(this);
			//����Ʈ �־����
		} 
		if (other->m_Tag == "Monster") {
			if (!GameMgr::GetInst()->_Invincible) {
				GameMgr::GetInst()->_Hit = true;
				GameMgr::GetInst()->hit = true;
			}
		}
	}
	if (type_enemy) {
		if (other->m_Tag == "ColBox") {
			
			//����Ʈ �־����
			m_Hp -= 1; //�� �ް� ���� �� ���� �ְ� 
		}
	}
}

void BlockMgr::Move()
{
	MoveTime += dt;
	//enemy ������, 2���������� �Ѿ�� �������
	if (_tag == "fast") { // Fill�̶� ������ �ӵ� �� + Clone�̶� ������ �÷��̾� ���� ����
		// ��ż��̳� ��ſ� ����ġ�� ���� Effect������ �����
		if (MoveTime > 0.5f) {

			if (GameMgr::GetInst()->m_LinePos[0].x > m_Position.x && m_Position.x < 1920 - m_Speed) {
				Translate(m_Speed, 0);
			}
			else if (GameMgr::GetInst()->m_LinePos[0].x < m_Position.x && m_Position.x > 0 + m_Speed) {
				Translate(-m_Speed, 0);
			}

			if (GameMgr::GetInst()->m_LinePos[0].y > m_Position.y && m_Position.x < 1080 - m_Speed) {
				Translate(0, m_Speed);
			}
			else if (GameMgr::GetInst()->m_LinePos[0].y < m_Position.y && m_Position.y > 0 + m_Speed) {
				Translate(0, -m_Speed);
			}

			MoveTime = 0;
		}
	}

	if (_tag == "flash") {
		if (MoveTime > Moveif) {

			if (GameMgr::GetInst()->m_PlayerPos.x > m_Position.x && m_Position.x < 1920 - m_Speed) {
				Translate(m_Speed, 0);
				if (flashstack != 3)
					flashstack++;
			}
			else if (GameMgr::GetInst()->m_PlayerPos.x < m_Position.x && m_Position.x > 0 + m_Speed) {
				Translate(-m_Speed, 0);
				if (flashstack != 3)
					flashstack++;
			}
			if (GameMgr::GetInst()->m_PlayerPos.y > m_Position.y && m_Position.x < 1080 - m_Speed) {
				Translate(0, m_Speed);
				if (flashstack != 3)
					flashstack++;
			}
			else if (GameMgr::GetInst()->m_PlayerPos.y < m_Position.y && m_Position.y > 0 + m_Speed) {
				Translate(0, -m_Speed);
				if (flashstack != 3)
					flashstack++;
			}
			if (flashstack == 3) {

				if (efttect) {
					ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/flash", 1, 2, 2, m_Position), "Effect");
					efttect = false;
				}

				flashtime += 1;
				m_Blocks->A = 0;
				Moveif = 0.2f;
				if (flashtime > 5) {
					m_Blocks->A = 255;
					flashstack = 0;
					flashtime = 0;
					Moveif = 0.75f;
					efttect = true;
					ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/flash", 1, 2, 2, m_Position), "Effect");
				}
			}

			MoveTime = 0;
		}
	}

	if (_tag == "flashgiant") {
		if (MoveTime > Moveif) {

			if (GameMgr::GetInst()->m_PlayerPos.x > m_Position.x && m_Position.x < 1920 - m_Speed) {
				Translate(m_Speed, 0);
				if (flashstack != 3)
					flashstack++;
			}
			else if (GameMgr::GetInst()->m_PlayerPos.x < m_Position.x && m_Position.x > 0 + m_Speed) {
				Translate(-m_Speed, 0);
				if (flashstack != 3)
					flashstack++;
			}
			else if (GameMgr::GetInst()->m_PlayerPos.y > m_Position.y && m_Position.x < 1080 - m_Speed) {
				Translate(0, m_Speed);
				if (flashstack != 3)
					flashstack++;
			}
			else if (GameMgr::GetInst()->m_PlayerPos.y < m_Position.y && m_Position.y > 0 + m_Speed) {
				Translate(0, -m_Speed);
				if (flashstack != 3)
					flashstack++;
			}

			if (flashstack == 3) {
				if (efttect) {
					ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/flash", 1, 1, 2, m_Position), "Effect");
					efttect = false;
				}
				flashtime += 1;
				m_Blocks->A = 0;
				Moveif = 0.2f;
				if (flashtime > 5) {
					m_Blocks->A = 255;
					flashtime = 0;
					flashstack = 0;
					Moveif = 0.75f;
					efttect = true;
					ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/flash", 1, 1, 2, m_Position), "Effect");
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
		if (!(GameMgr::GetInst()->hit)) { // ���� �ʾ�����
			//ObjMgr->CollisionCheak(this, "Monster");
			m_Blocks->R = 255;
			m_Blocks->G = 255;
			m_Blocks->B = 255;
		}
		else {
			m_Blocks->A = 255;
			m_Blocks->R = 237;
			m_Blocks->G = 123;
			m_Blocks->B = 61;
		}
		if (!(GameMgr::GetInst()->hit)) {
			if (GameMgr::GetInst()->m_Hp == 5) {
				m_Blocks->R = 116;
				m_Blocks->G = 192;
				m_Blocks->B = 99;
			}
			if (GameMgr::GetInst()->m_Hp == 4) {
				m_Blocks->R = 145;
				m_Blocks->G = 237;
				m_Blocks->B = 89;
			}
			if (GameMgr::GetInst()->m_Hp == 3) {
				m_Blocks->R = 211;
				m_Blocks->G = 237;
				m_Blocks->B = 89;
			}
			if (GameMgr::GetInst()->m_Hp == 2) {
				m_Blocks->R = 237;
				m_Blocks->G = 197;
				m_Blocks->B = 89;
			}
			if (GameMgr::GetInst()->m_Hp == 1) {
				m_Blocks->R = 237;
				m_Blocks->G = 123;
				m_Blocks->B = 61;
			}
			//�������� �ٽ� �̾��ϱ� / �ð��� 0�� ���ϸ� �׵���
		}
	}
	if (type_enemy && flashstack != 3) {
		if (!(GameMgr::GetInst()->hit)) { // ���� �ʾ�����
			ObjMgr->CollisionCheak(this, "Clone");
			//m_Blocks->R = 255;
			//m_Blocks->G = 255;
			//m_Blocks->B = 255;
		}
		ObjMgr->CollisionCheak(this, "ColBox");
		if (m_Hp <= 0)
			ObjMgr->RemoveObject(this);
	}
}