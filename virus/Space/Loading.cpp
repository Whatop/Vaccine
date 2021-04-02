#include "stdafx.h"
#include "Loading.h"
#include "MenuScene.h"
#include "Stage1.h"
#include "Stage2.h"
#include "ReportScene.h"
#include "RankScene.h"
#include "CreditScene.h"
#include "WayScene.h"

Loading::Loading(int type)
{
	if (type == 0) {
		frame = 13;
		m_Loding = new Animation();
		m_Loding->AddContinueFrame(L"Painting/Effect/ChangeScene/", 1, frame);
	}
	/*else if(type == boss){
		m_Loding = new Animation();
		m_Loding->AddFrame(L"Painting/loading/", 0, 10);
		std::cout << "에러값" << std::endl;
	}
	else if (type== none) {
		m_Loding = new Animation();
		m_Loding->AddFrame(L"Painting/loading/", 0, 10);
		std::cout << "에러값" << std::endl;
	}*/
	m_Loding->Init(0.024f, true);;
	m_Loding->SetParent(this);
	m_Layer = 10;
	SetPosition(1920 / 2, 1080 / 2);
}

Loading::~Loading()
{
}

void Loading::Update(float deltaTime, float Time)
{
	if (m_Loding->m_CurrentFrame >= frame - 4) {
		ObjMgr->RemoveObject(this);

		if (SceneDirector::GetInst()->GetScene() == SceneState::MENU)
			SceneDirector::GetInst()->ChangeScene(new MenuScene());

		else if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1)
			SceneDirector::GetInst()->ChangeScene(new Stage1());

		else if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
			SceneDirector::GetInst()->ChangeScene(new Stage2());

		else if (SceneDirector::GetInst()->GetScene() == SceneState::REPORT)
			SceneDirector::GetInst()->ChangeScene(new ReportScene);

		else if (SceneDirector::GetInst()->GetScene() == SceneState::RANK)
			SceneDirector::GetInst()->ChangeScene(new RankScene);

		else if (SceneDirector::GetInst()->GetScene() == SceneState::WAY)
			SceneDirector::GetInst()->ChangeScene(new WayScene);

		else if (SceneDirector::GetInst()->GetScene() == SceneState::CREDIT)
			SceneDirector::GetInst()->ChangeScene(new CreditScene);

	}
	m_Loding->Update(deltaTime, Time);
}

void Loading::Render()
{
	m_Loding->Render();
}
