#include "stdafx.h"
#include "Stage1.h"
#include "Stage2.h"
#include "MenuScene.h"
#include "BlockMgr.h"
#include "Player.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}
//��Ʈ�� ����� -> �޴����� ���ӼҰ�, ���ӹ��, ���ӷ�ŷ. ũ���� ����
void Stage1::Init() // �������� 1 ��� ��ü�� �ϰ�, �������� 2�� ����� ������ �Ѵ�. �ٴ� ���̶�� �ʷ��ʷ��ϸ� �����Ⱑ �Ȼ�� 
{
	ObjMgr->Release();
	SceneDirector::GetInst()->SetScene(SceneState::STAGE1);
	GameMgr::GetInst()->CreateUI();
	GameMgr::GetInst()->SetLimit();
	GameMgr::GetInst()->SpawnItem(Vec2(0, 0));
	GameMgr::GetInst()->SpawnFast(Vec2(630, 90));
	m_HideGrid = false;

	m_TileSize = Vec2(60, 60);
	m_GridSize = Vec2(60, 60);

	m_Text = new TextMgr();
	m_Text->Init(32, true, false, "Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);

	for (int i = 0; i < 100; i++)
	{
		Sprite* v = Sprite::Create(L"Painting/Map/Vertical.png");
		v->SetPosition(m_GridSize.x * i, App::GetInst()->m_Height / 2);
		Sprite* h = Sprite::Create(L"Painting/Map/Horizontal.png");
		h->SetPosition(App::GetInst()->m_Width / 2, m_GridSize.y * i);

		m_Vertical.push_back(v);
		m_Horizontal.push_back(h);
	}
	GameMgr::GetInst()->CreatePlayer();




	//��ֹ��� ��
	ObjMgr->AddObject(new BlockMgr(Vec2(1170, 540 + 30), "column"), "Column");//��ֹ�

	//ObjMgr->AddObject(new BackGround(L"Painting/BackGround/Stage1-", 1, 1, 2, Vec2(1920/2, 1080/2)), "BackGround");
}

void Stage1::Release()
{
	GameMgr::GetInst()->ReleaseUI();
}

void Stage1::Update(float deltaTime, float time)
{
	if (INPUT->GetKey(VK_F4) == KeyState::DOWN) // �޴�ȭ�� �̵�
	{
		SceneDirector::GetInst()->ChangeScene(new MenuScene());
		std::cout << "�޴����̵�" << std::endl;
	}
	else if (INPUT->GetKey(VK_F5) == KeyState::DOWN) // �������� 1 �̵�
	{
		SceneDirector::GetInst()->ChangeScene(new Stage1());
		std::cout << "1���̵�" << std::endl;
	}
	else if (INPUT->GetKey(VK_F6) == KeyState::DOWN) // �������� 2 �̵�
	{
		SceneDirector::GetInst()->ChangeScene(new Stage2());
		std::cout << "2���̵�" << std::endl;
	}

	m_PrevSize = m_GridSize;


	if (INPUT->GetKey(VK_F7) == KeyState::DOWN)
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
			m_Vertical.at(i)->SetPosition(m_GridSize.x * i, App::GetInst()->m_Height / static_cast<float>(2));
			m_Horizontal.at(i)->SetPosition(App::GetInst()->m_Width / 2, m_GridSize.y * i);
		}
	}
}

void Stage1::Render()
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
	}
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + "  " + std::to_string(INPUT->GetMousePos().y)
		+ "\n" + std::to_string(dt) + "  " + std::to_string(gt), 250, 900);
	Renderer::GetInst()->GetSprite()->End();
}
