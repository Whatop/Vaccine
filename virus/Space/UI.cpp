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
	m_UI = Sprite::Create(L"Painting/Map/UI.png");
	m_Text = new TextMgr();
	m_Text->Init(65, true, false, "±¼¸²");
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

	Renderer::GetInst()->GetSprite()->End();
}
