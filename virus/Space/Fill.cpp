#include "stdafx.h"
#include "Fill.h"

Fill::Fill(Vec2 MyPos, Vec2 Scale,int type)
{
	m_Fill = Sprite::Create(L"Painting/Pill.png");
	m_Fill->SetParent(this);
	SetPosition(MyPos.x,MyPos.y);
	SetScale(Scale.x,Scale.y);
	m_Type = type;

}

Fill::~Fill()
{
}

void Fill::Update(float deltaTime, float Time)
{
	type += dt;
	if (m_Type) {
		m_Fill->A = 130;
		m_Fill->R = 30;
		m_Fill->G = 122;
		m_Fill->B = 30;
	}
	else{
		ObjMgr->CollisionCheak(this, "Clone");
		ObjMgr->CollisionCheak(this, "Monster");
		m_Fill->A = 0;
		if (type > 1)
			ObjMgr->RemoveObject(this);

		std::cout << m_Fill->m_Rect.left << std::endl;
		std::cout << m_Fill->m_Rect.right << std::endl;
		std::cout << m_Fill->m_Rect.top << std::endl;
		std::cout << m_Fill->m_Rect.bottom << std::endl;
		
		std::cout << m_Collision.left << std::endl;
		std::cout << m_Collision.right << std::endl;
		std::cout << m_Collision.top << std::endl;
		std::cout << m_Collision.bottom << std::endl;
	}
	

}

void Fill::Render()
{
	m_Fill->Render();
}

void Fill::OnCollision(Object* obj)
{
}
