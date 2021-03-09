#include "stdafx.h"
#include "MenuScene.h"
#include "MainScene.h"
#include "MenuScene.h"

MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
}
void MenuScene::Init() 
{
    m_Start = Sprite::Create(L"Painting/Button/start.png");
    m_Start->SetPosition(300, 100);

    m_Report = Sprite::Create(L"Painting/Button/report.png");
    m_Report->SetPosition(300, 300);
    
    m_Way = Sprite::Create(L"Painting/Button/way.png");
    m_Way->SetPosition(300, 500);
  
    m_Rank = Sprite::Create(L"Painting/Button/rank.png");
    m_Rank->SetPosition(300, 700);
  
    m_Credit = Sprite::Create(L"Painting/Button/credit.png");
    m_Credit->SetPosition(300, 900);

   // ObjMgr->AddObject(new BackGround())
    
}

void MenuScene::Release()
{
}

void MenuScene::Update(float deltaTime, float time)
{
    //���ӽ���, ���ӼҰ�, ���ӹ��, ���ӷ�ŷ(score), ũ����(credit)
    if ( CollisionMgr::GetInst()->MouseWithBoxSize(m_Start) && INPUT->GetButtonDown() == true)
    {
        ObjMgr->Release();
        SceneDirector::GetInst()->ChangeScene(new MainScene());
    }
    else if ( CollisionMgr::GetInst()->MouseWithBoxSize(m_Report) && INPUT->GetButtonDown() == true)
    {
        ObjMgr->Release();
    }
    else if ( CollisionMgr::GetInst()->MouseWithBoxSize(m_Way) && INPUT->GetButtonDown() == true)
    {
        ObjMgr->Release();
    }
    else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Rank) && INPUT->GetButtonDown() == true)
    {
        ObjMgr->Release();
    }
    else if ( CollisionMgr::GetInst()->MouseWithBoxSize(m_Credit) && INPUT->GetButtonDown() == true)
    {
        ObjMgr->Release();
    }
}

void MenuScene::Render()
{
    m_Start->Render();
    m_Report->Render();
    m_Way->Render();
    m_Rank->Render();
    m_Credit->Render();
}
