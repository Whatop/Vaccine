#include "stdafx.h"
#include "Stage1.h"
#include "BlockMgr.h"
#include "Player.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}
//인트로 만들기 -> 메뉴에선 게임소개, 게임방법, 게임랭킹. 크래디 선택
void Stage1::Init() // 스테이지 1 배경 신체로 하고, 스테이지 2의 배경을 숲으로 한다. 근대 숲이라고 초록초록하면 분위기가 안사니 
{
	SceneDirector::GetInst()->SetScene(SceneState::STAGE1);
	m_HideGrid = false;
	m_Pause = false;

	m_TileSize = Vec2(60, 60);
	m_GridSize = Vec2(60, 60);

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
	ObjMgr->AddObject(new Player(Vec2(90, 90)), "Player");//백신 왼쪽위
	for (int a = 30; a < 1920; a += 60) {
		ObjMgr->AddObject(new BlockMgr(Vec2(a, 30), "ground"), "Ground");//
		ObjMgr->AddObject(new BlockMgr(Vec2(a, 1050), "ground"), "Ground");//벽
	}
	for (int a = 90; a < 1050; a += 60) {
		ObjMgr->AddObject(new BlockMgr(Vec2(30, a), "ground"), "Ground");//벽
		ObjMgr->AddObject(new BlockMgr(Vec2(1890, a), "ground"), "Ground");//벽
	}

	ObjMgr->AddObject(new BlockMgr(Vec2(270, 240 + 30), "speed"), "Speed");//아이템 스피드 3회
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 300 + 30), "ammor"), "Ammor");//아이템 방어 3회
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 360 + 30), "invincible"), "Invincible");//아이템 무적 1회
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 420 + 30), "heal"), "Heal");//아이템 체력회복 +1 풀리면 점수 오름 2회
	ObjMgr->AddObject(new BlockMgr(Vec2(270, 480) + 30, "random"), "Random");//아이템 랜덤 5회

}

void Stage1::Release()
{
}

void Stage1::Update(float deltaTime, float time)
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
	}/*
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + "  " + std::to_string(INPUT->GetMousePos().y)
		+ "\n" + std::to_string(dt) + "  " + std::to_string(gt), 250, 900);
	Renderer::GetInst()->GetSprite()->End();

	*/
}
