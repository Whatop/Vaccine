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
//�ӵ� 2ĭ���̵� 
void BlockMgr::BlockType(std::string tag,Vec2 Pos) // Clone ,������(�ӵ�,����,����,�����),Enemy(�ӵ�,ũ��,����,��ó�)
{
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) {
		if (tag == "clone") { //Ŭ��, ġ��Ǹ� ����Ʈ �������� ����
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Player.png");
			m_Blocks->A = 200;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Ground.png");
			m_Blocks->A = 200;
		}
		if (tag == "pull") { //�ȿ� ä���ִ� ģ��
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
		//obstacle(��ֹ�)
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
		if (tag == "clone") { //Ŭ��, ġ��Ǹ� ����Ʈ �������� ����
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Player.png");
			m_Blocks->A = 200;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Ground.png");
			m_Blocks->A = 200;
		}
		if (tag == "pull") { //�ȿ� ä���ִ� ģ��
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
		//obstacle(��ֹ�)
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
	//enemy ������, 2���������� �Ѿ�� �������
	if (_tag == "fast") { 
		// ��ż��̳� ��ſ� ����ġ�� ���� Effect������ �����
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
