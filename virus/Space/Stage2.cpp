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
//인트로 만들기 -> 메뉴에선 게임소개, 게임방법, 게임랭킹. 크래디 선택
void Stage2::Init() // 스테이지 1 배경 신체로 하고, 스테이지 2의 배경을 숲으로 한다. 근대 숲이라고 초록초록하면 분위기가 안사니 
{
	ObjMgr->Release();

	SceneDirector::GetInst()->SetScene(SceneState::STAGE2);
	m_Pause = false;
	GameMgr::GetInst()->CreatePlayer();
	GameMgr::GetInst()->SpawnGiant(Vec2(300,300));
	GameMgr::GetInst()->SpawnFast(Vec2(300,300));
	GameMgr::GetInst()->SetLimit();
	GameMgr::GetInst()->SpawnItem(Vec2(0, 0)); // 안좌표는 그냥 임시좌표 이친구가 영향줄수 있는것은 없다


	m_Text = new TextMgr();
	m_Text->Init(32, true, false, "Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);

}

void Stage2::Release()
{
}

void Stage2::Update(float deltaTime, float time)
{
	if (INPUT->GetKey(VK_F4) == KeyState::DOWN) // 메뉴화면 이동
	{
		SceneDirector::GetInst()->ChangeScene(new MenuScene());
		std::cout << "메뉴로이동" << std::endl;
	}
	else if (INPUT->GetKey(VK_F5) == KeyState::DOWN) // 스테이지 1 이동
	{
		SceneDirector::GetInst()->ChangeScene(new Stage1());
		std::cout << "1로이동" << std::endl;
	}
	else if (INPUT->GetKey(VK_F6) == KeyState::DOWN) // 스테이지 2 이동
	{
		SceneDirector::GetInst()->ChangeScene(new Stage2());
		std::cout << "2로이동" << std::endl;
	}

}

void Stage2::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(GameMgr::GetInst()->m_Hp), 1750, 980);
	m_Text->print("Score : " + std::to_string(GameMgr::GetInst()->m_Score), 1920 / 2 - 100, 0);
	Renderer::GetInst()->GetSprite()->End();
}
