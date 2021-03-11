#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(std::wstring filename, int start, int speed, int end, Vec2 Pos)
{
	m_BackGround = new Animation();
	m_BackGround->AddContinueFrame(filename, start, end);
	m_BackGround->Init(speed, true);
	m_BackGround->SetParent(this);
	m_BackGround->m_Position = Pos;

	Start = start;
	End = end;
}

BackGround::~BackGround()
{
}

void BackGround::Update(float deltaTime, float time)
{
	if (m_BackGround->m_CurrentFrame >= End - 1)
	{
		ObjMgr->RemoveObject(this);
	}
}

void BackGround::Render()
{
	m_BackGround->Render();
}

void BackGround::OnCollision(Object* other)
{
}
