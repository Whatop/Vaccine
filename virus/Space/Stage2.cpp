#include "stdafx.h"
#include "Stage1.h"
#include "Stage2.h"
#include "MenuScene.h"03
#include "BlockMgr.h"
#include "Player.h"

Stage2::Stage2()
{
}

Stage2::~Stage2()
{
}
//��Ʈ�� ����� -> �޴����� ���ӼҰ�, ���ӹ��, ���ӷ�ŷ. ũ���� ����
void Stage2::Init() // �������� 1 ��� ��ü�� �ϰ�, �������� 2�� ����� ������ �Ѵ�. �ٴ� ���̶�� �ʷ��ʷ��ϸ� �����Ⱑ �Ȼ�� 
{
	ObjMgr->Release();

	SceneDirector::GetInst()->SetScene(SceneState::STAGE2);
	m_Pause = false;
	GameMgr::GetInst()->CreatePlayer();
	GameMgr::GetInst()->SpawnGiant(Vec2(300,300));
	GameMgr::GetInst()->SpawnFast(Vec2(300,300));
	GameMgr::GetInst()->SetLimit();
	GameMgr::GetInst()->SpawnItem(Vec2(0, 0)); // ����ǥ�� �׳� �ӽ���ǥ ��ģ���� �����ټ� �ִ°��� ����


	m_Text = new TextMgr();
	m_Text->Init(32, true, false, "Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);

}

void Stage2::Release()
{
}

void Stage2::Update(float deltaTime, float time)
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

void Stage2::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(GameMgr::GetInst()->m_Hp), 1750, 980);
	m_Text->print("Score : " + std::to_string(GameMgr::GetInst()->m_Score), 1920 / 2 - 100, 0);
	Renderer::GetInst()->GetSprite()->End();
}
