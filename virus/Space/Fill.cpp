#include "stdafx.h"
#include "Fill.h"

Fill::Fill(Vec2 MyPos, Vec2 Scale,int type)
{
	if(SceneDirector::GetInst()->GetScene()==SceneState::STAGE1)
	m_Fill = Sprite::Create(L"Painting/Pill1.png");
	if (SceneDirector::GetInst()->GetScene() == SceneState::STAGE2)
		m_Fill = Sprite::Create(L"Painting/Pill2.png");
	m_Fill->SetParent(this);
	SetPosition(MyPos.x,MyPos.y);
	SetScale(Scale.x,Scale.y);
	m_Type = type;
	m_Layer = -1;
}

Fill::~Fill()
{
}

void Fill::Update(float deltaTime, float Time)
{
	type += dt;
	if (m_Type) {
		m_Fill->R = 116;
		m_Fill->G = 192;
		m_Fill->B = 99;
	}
	else{
		m_Fill->A = 0;
		//积己
		if (type > 1) {
			ObjMgr->RemoveObject(this);
			std::cout << "哭率 :" <<   m_Collision.left << std::endl;
			std::cout << "坷弗率 :" << m_Collision.right << std::endl;
			std::cout << "困率 :" <<   m_Collision.top << std::endl;
			std::cout << "酒贰率 :" << m_Collision.bottom << std::endl;
		}
	}
	

}

void Fill::Render()
{
	m_Fill->Render();
}

void Fill::OnCollision(Object* obj)
{
}
