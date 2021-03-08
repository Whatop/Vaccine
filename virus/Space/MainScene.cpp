#include "stdafx.h"
#include "MainScene.h"
#include "BlockMgr.h"
#include "Player.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}
//��Ʈ�� ����� -> �޴����� ���ӼҰ�, ���ӹ��, ���ӷ�ŷ. ũ���� ����
void MainScene::Init() // �������� 1 ��� ��ü�� �ϰ�, �������� 2�� ����� ������ �Ѵ�. �ٴ� ���̶�� �ʷ��ʷ��ϸ� �����Ⱑ �Ȼ�� 
{
	m_HideGrid = false;
	m_Pause = false; 
	
	m_TileSize = Vec2(40, 40);
	m_GridSize = Vec2(40, 40);

	//m_Text = new TextMgr();
	//m_Text->Init(32, true, false, "Determination Mono");
	//m_Text->SetColor(255, 255, 255, 255);

	for (int i = 0; i < 100; i++)
	{
		Sprite* v = Sprite::Create(L"Painting/Map/Vertical.png");
		v->SetPosition(m_GridSize.x * i, App::GetInst()->m_Height / 2);
		Sprite* h = Sprite::Create(L"Painting/Map/Horizontal.png");
		h->SetPosition(App::GetInst()->m_Width / 2, m_GridSize.y * i);

		m_Vertical.push_back(v);
		m_Horizontal.push_back(h);
	}
	ObjMgr->AddObject(new Player(Vec2(60,60)), "Player");//��� ������
	for (int a = 20; a < 1920; a += 40) {
		ObjMgr->AddObject(new BlockMgr(Vec2(a, 20), "ground"), "Ground");//
		ObjMgr->AddObject(new BlockMgr(Vec2(a, 1060), "ground"), "Ground");//��
	}
	for (int a = 20; a < 1060; a += 40) {
		ObjMgr->AddObject(new BlockMgr(Vec2(20, a), "ground"), "Ground");//��
		ObjMgr->AddObject(new BlockMgr(Vec2(1900, a), "ground"), "Ground");//��
	}
	UI::GetInst()->Init();

	ObjMgr->AddObject(new BlockMgr(Vec2(220, 140), "speed"), "Speed");//������ ���ǵ� 3ȸ
	ObjMgr->AddObject(new BlockMgr(Vec2(220, 180), "ammor"), "Ammor");//������ ��� 3ȸ
	ObjMgr->AddObject(new BlockMgr(Vec2(220, 220), "invincible"), "Invincible");//������ ���� 1ȸ
	ObjMgr->AddObject(new BlockMgr(Vec2(220, 260), "heal"), "Heal");//������ ü��ȸ�� +1 Ǯ���� ���� ���� 2ȸ
	ObjMgr->AddObject(new BlockMgr(Vec2(220, 300), "random"), "Random");//������ ���� 5ȸ
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	m_PrevSize = m_GridSize;


	if (INPUT->GetKey(VK_TAB) == KeyState::DOWN)
	{
		if (m_Pause)
			m_Pause = false;
		else
			m_Pause = true;
	}

	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
	{
		if (m_HideGrid)
		{
			for (auto& iter : m_Vertical)
			{
				iter->m_Visible = true;
			}
			for (auto& iter : m_Horizontal)
			{
				iter->m_Visible = true;
			}

			m_HideGrid = false;
		}
		else
		{
			for (auto& iter : m_Vertical)
			{
				iter->m_Visible = false;
			}
			for (auto& iter : m_Horizontal)
			{
				iter->m_Visible = false;
			}

			m_HideGrid = true;
		}
	}
	if (m_PrevSize != m_GridSize)
	{
		for (int i = 0; i < 100; i++)
		{
			m_Vertical.at(i)->SetPosition(m_GridSize.x * i, App::GetInst()->m_Height / 2);
			m_Horizontal.at(i)->SetPosition(App::GetInst()->m_Width / 2, m_GridSize.y * i);
		}
	}
}

void MainScene::Render()
{
	for (auto& iter : m_Vertical)
	{
		if (abs(iter->m_Position.x - Camera::GetInst()->m_Position.x) > App::GetInst()->m_Width)
			iter->m_Position.x -= m_GridSize.x * 100;

		if (iter->m_Position.x < Camera::GetInst()->m_Position.x)
			iter->m_Position.x += m_GridSize.x * 100;

		iter->m_Position.y = Camera::GetInst()->m_Position.y + iter->m_Size.y / 2;

		iter->Render();
	}
	for (auto& iter : m_Horizontal)
	{
		if (abs(iter->m_Position.y - Camera::GetInst()->m_Position.y) > App::GetInst()->m_Height)
			iter->m_Position.y -= m_GridSize.y * 100;

		if (iter->m_Position.y < Camera::GetInst()->m_Position.y)
			iter->m_Position.y += m_GridSize.y * 100;

		iter->m_Position.x = Camera::GetInst()->m_Position.x + iter->m_Size.x / 2;

		iter->Render();
	}/*
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + "  " + std::to_string(INPUT->GetMousePos().y)
		+ "\n" + std::to_string(dt) + "  " + std::to_string(gt), 250, 900);
	Renderer::GetInst()->GetSprite()->End();

	*/
}
