#include "stdafx.h"
#include "Fill.h"

Fill::Fill(Vec2 MyPos, Vec2 Scale)
{
	m_Fill = Sprite::Create(L"Painting/Pill.png");
	m_Fill->SetParent(this);
	SetPosition(MyPos.x,MyPos.y);
	SetScale(Scale.x,Scale.y);
}

Fill::~Fill()
{
}

void Fill::Update(float deltaTime, float Time)
{
}

void Fill::Render()
{
	m_Fill->Render();
}

void Fill::OnCollision(Object* obj)
{
}
