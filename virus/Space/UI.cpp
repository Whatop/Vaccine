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

	m_Text = new TextMgr();
	m_Text->Init(45, true, false, "±¼¸²Ã¼");
	m_Text->SetColor(255, 255, 255, 255);

}

void UI::Release()
{
}

void UI::Update()
{
	/*for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
			PlayerPos = iter->m_Position;
	}*/

}

void UI::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(m_Hp), 1750, 980);
	m_Text->print("Score : " + std::to_string(m_Score), 1920 / 2 - 100, 0);
	Renderer::GetInst()->GetSprite()->End();
}
