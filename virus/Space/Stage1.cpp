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
	m_BG = Sprite::Create(L"Painting/Stage1/Stage1.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);
	m_Virus = Sprite::Create(L"Painting/Stage1/Virus.png");
	m_Virus->SetPosition(1920 / 2, 1080 / 2);


	ObjMgr->Release();
	SceneDirector::GetInst()->SetScene(SceneState::STAGE1);
	GameMgr::GetInst()->CreatePlayer();
	GameMgr::GetInst()->SetLimit();
	GameMgr::GetInst()->SpawnItem(Vec2(0, 0));
//	GameMgr::GetInst()->SpawnFast(Vec2(630, 90));
	GameMgr::GetInst()->SpawnFlash(Vec2(630, 90));
//	GameMgr::GetInst()->SpawnGiant(Vec2(630, 90));
//	GameMgr::GetInst()->SpawnToxino(Vec2(630, 90));
	m_HideGrid = false;

	m_Text = new TextMgr();
	m_Text->Init(32, true, false, "Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);


	//��ֹ��� ��
	ObjMgr->AddObject(new BlockMgr(Vec2(1170, 540 + 30), "column"), "Column");//��ֹ�

	ObjMgr->AddObject(new BackGround(L"Painting/Stage", 1, 1, 2, Vec2(1920/2, 1080/2)), "BackGround");
}

void Stage1::Release()
{
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

}

void Stage1::Render()
{
	m_BG->Render();
	m_Virus->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(GameMgr::GetInst()->m_Hp), 1750, 980);
	m_Text->print("Score : " + std::to_string(GameMgr::GetInst()->m_Score), 1920 / 2 - 100, 0);
	Renderer::GetInst()->GetSprite()->End();
}
