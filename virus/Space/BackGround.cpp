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
	m_Cut = 0;
}

BackGround::~BackGround()
{
}

void BackGround::Update(float deltaTime, float time)
{
	m_Count += dt;
	if (SceneDirector::GetInst()->GetScene() == SceneState::INTRO) {
		if (m_Count >= 5.f && m_Cut >= 13)
		{

			if (m_BackGround->A >= 0)
				m_BackGround->A -= 5;
			else if (m_BackGround->A <= 0) {
				m_Cut += 1;

			}

			if () {
				m_BackGround->m_CurrentFrame += 1;
			}
			m_Count = 0;
		}
	}
	if (m_BackGround->m_CurrentFrame >= End - 1)
	{
		ObjMgr->RemoveObject(this);
	}
	m_BackGround ->Update(deltaTime, time);
}

void BackGround::Render()
{
	m_BackGround->Render();
}

void BackGround::OnCollision(Object* other)
{
}
