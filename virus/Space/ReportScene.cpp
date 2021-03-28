#include "stdafx.h"
#include "ReportScene.h"
#include "MenuScene.h"

ReportScene::ReportScene()
{
}

ReportScene::~ReportScene()
{
}

void ReportScene::Init()
{
	m_BG = Sprite::Create(L"Painting/Scene/Report.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_Back = Sprite::Create(L"Painting/Button/ReturnTitle.png");
	m_Back->SetPosition(1700, 950);
}

void ReportScene::Release()
{
}

void ReportScene::Update(float deltaTime, float Time)
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Back) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new MenuScene());
	}
}

void ReportScene::Render()
{
	m_BG->Render();
	m_Back->Render();
}
