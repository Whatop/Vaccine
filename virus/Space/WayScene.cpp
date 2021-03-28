#include "stdafx.h"
#include "WayScene.h"
#include "MenuScene.h"

WayScene::WayScene()
{
}

WayScene::~WayScene()
{
}

void WayScene::Init()
{
	m_BG = Sprite::Create(L"Painting/Scene/Way.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_Back = Sprite::Create(L"Painting/Button/ReturnTitle.png");
	m_Back->SetPosition(1700, 900);
}

void WayScene::Release()
{
}

void WayScene::Update(float deltaTime, float Time)
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Back) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new MenuScene());
	}
}

void WayScene::Render()
{
	m_BG->Render();
	m_Back->Render();
}
