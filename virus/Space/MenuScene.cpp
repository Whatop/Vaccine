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
    m_Start = Sprite::Create(L"Painting/GameStart.png");
    m_Start->SetPosition(300, 100);

    m_Report = Sprite::Create(L"Painting/IntroDuce.png");
    m_Report->SetPosition(300, 300);
    
    m_Way = Sprite::Create(L"Painting/Explain.png");
    m_Way->SetPosition(300, 500);
  
    m_Rank = Sprite::Create(L"Painting/Ranking.png");
    m_Rank->SetPosition(300, 700);
  
    m_Credit = Sprite::Create(L"Painting/Back.png");
    m_Credit->SetPosition(1920 / 2, 1080 / 2);
    
}

void MenuScene::Release()
{
}

void MenuScene::Update(float deltaTime, float time)
{
    //게임시작, 게임소개, 게임방법, 게임랭킹(score), 크래딧(credit)
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

