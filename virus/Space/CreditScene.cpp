#include "stdafx.h"
#include "CreditScene.h"
#include "MenuScene.h"

CreditScene::CreditScene()
{
}

CreditScene::~CreditScene()
{
}

void CreditScene::Init()
{
	m_BG = Sprite::Create(L"Painting/Scene/Credit.png");
	m_BG->SetPosition(1920 / 2, 4024 / 2);

	m_Back = Sprite::Create(L"Painting/Scene/BackButton.png");
	m_Back->SetPosition(1700, 900);
}

void CreditScene::Release()
{
}

void CreditScene::Update(float deltaTime, float Time)
{
	stoptime += dt;
	if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Back) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new MenuScene());
	}
	if(stoptime >= 0.5f&& m_BG->m_Position.y >= -1500)
	m_BG->Translate(0, -200 * dt);

	std::cout << m_BG->m_Position.y << std::endl;


}

void CreditScene::Render()
{
	m_BG->Render();
	m_Back->Render();
}
