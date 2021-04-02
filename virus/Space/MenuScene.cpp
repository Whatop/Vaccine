#include "stdafx.h"
#include "MenuScene.h"

MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
}
void MenuScene::Init() 
{
    ObjMgr->Release();
    m_MainScene = Sprite::Create(L"Painting/MainScene.png");
    m_MainScene->SetPosition(1920/2, 1080/2);

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
    //게임시작, 게임소개, 게임방법, 게임랭킹(score), 크래딧(credit)
    if ( CollisionMgr::GetInst()->MouseWithBoxSize(m_Start) && INPUT->GetButtonDown())
    {
        SceneDirector::GetInst()->SetScene(SceneState::STAGE1);
        ObjMgr->AddObject(new Loading(0), "SceneChange");
    }
    else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Report) && INPUT->GetButtonDown())
    {
        SceneDirector::GetInst()->SetScene(SceneState::REPORT);
        ObjMgr->AddObject(new Loading(0), "SceneChange");
    }
    else if ( CollisionMgr::GetInst()->MouseWithBoxSize(m_Way) && INPUT->GetButtonDown())
    {
        SceneDirector::GetInst()->SetScene(SceneState::WAY);
        ObjMgr->AddObject(new Loading(0), "SceneChange");
    }
    else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Rank) && INPUT->GetButtonDown())
    {
        SceneDirector::GetInst()->SetScene(SceneState::RANK);
        ObjMgr->AddObject(new Loading(0), "SceneChange");
    }
    else if ( CollisionMgr::GetInst()->MouseWithBoxSize(m_Credit) && INPUT->GetButtonDown())
    {
        SceneDirector::GetInst()->SetScene(SceneState::CREDIT);
        ObjMgr->AddObject(new Loading(0), "SceneChange");
    }
}

void MenuScene::Render()
{
    m_MainScene->Render();
    m_Start->Render();
    m_Report->Render();
    m_Way->Render();
    m_Rank->Render();
    m_Credit->Render();
}

