#include "stdafx.h"
#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Init()
{
	//m_UI = Sprite::Create(L"Painting/Map/UI.png");

	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE1) {
		m_Text = new TextMgr();
		m_Text->Init(45, true, false, "궁서체");
		m_Text->SetColor(255, 255, 255, 255);
	}
	else if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2) {
		m_Text = new TextMgr();
		m_Text->Init(35, true, false, "궁서체");
		m_Text->SetColor(255, 133, 30, 0);
	}
	TimeLimit = 180;


}

void UI::Release()
{
}

void UI::Update()
{
	TimeLimit -= dt;
	
	if (TimeLimit > 0) {
		//
	}
}

void UI::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(m_Hp), 50, 0);
	m_Text->print("Score : " + std::to_string(GameMgr::GetInst()->m_Score), 250, 0);
	m_Text->print("제한시간 : " + std::to_string(int(TimeLimit)), 1920/2-150, 0);
	m_Text->print("치료진행도 : " + std::to_string(int(TimeLimit)), 1550, 0);
	Renderer::GetInst()->GetSprite()->End();
}