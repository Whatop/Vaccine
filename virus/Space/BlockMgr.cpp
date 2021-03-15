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
		m_Speed = 60.f;
		if (tag == "clone") { //Ŭ��, ġ��Ǹ� ����Ʈ �������� ���� pull �̶� �������� ���� �ȵǵ���
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Clone.png");
			m_Layer = 2;
			m_Blocks->A = 100;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Block/Ground.png");
			m_Blocks->A = 200;
		}
		if (tag == "pull") { //�ȿ� ä���ִ� ģ�� 
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
		//obstacle(��ֹ�)
		if (tag == "column") {
			m_Blocks = Sprite::Create(L"Painting/Stage1/Obstacle/Column.png");
			m_Blocks->A = 200;
		}

		//enemy 
		if (tag == "fast") { //ũ�� 1 
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Fast.png");
		}
		if (tag == "flash") {//ũ�� 1~2
			int random = rand() % 2 + 1;
			if (random == 1)
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Flash.png");

			if (random == 2)
				m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/FlashLong.png");
		}
		if (tag == "giant") {//ũ�� 4
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Giant.png");
		}
		if (tag == "toxino") {//ũ�� 4
			m_Blocks = Sprite::Create(L"Painting/Stage1/Enemy/Toxino.png");
		}
	}
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2) {
		m_Speed = 40.f;
		if (tag == "clone") { //Ŭ��, ġ��Ǹ� ����Ʈ �������� ���� pull �̶� �������� ���� �ȵǵ���
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Clone.png");
			m_Layer = 2;
		}
		if (tag == "ground") {
			m_Blocks = Sprite::Create(L"Painting/Stage2/Block/Ground.png");
			m_Blocks->A = 200;
		}
		if (tag == "pull") { //�ȿ� ä���ִ� ģ��
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
			//����Ʈ �־����
		} 
	}
}
