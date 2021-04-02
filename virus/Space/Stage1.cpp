#include "stdafx.h"
#include "BlockMgr.h"
#include "Stage1.h"
#include "Player.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}
//��Ʈ�� ����� -> �޴����� ���ӼҰ�, ���ӹ��, ���ӷ�ŷ. ũ���� ����
void Stage1::Init() // �������� 1 ��� ��ü�� �ϰ�, �������� 2�� ����� ������ �Ѵ�. �ٴ� ���̶�� �ʷ��ʷ��ϸ� �����Ⱑ �Ȼ�� 
{
	ObjMgr->Release();

	m_BG = Sprite::Create(L"Painting/Stage1/Stage1.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);
	m_Virus = Sprite::Create(L"Painting/Stage1/Virus.png");
	m_Virus->SetPosition(1920 / 2, 1080 / 2);

	SceneDirector::GetInst()->SetScene(SceneState::STAGE1);
	GameMgr::GetInst()->CreatePlayer();
	GameMgr::GetInst()->SetLimit();
	GameMgr::GetInst()->SpawnItem();
//	GameMgr::GetInst()->SpawnFast(Vec2(630, 90));
	GameMgr::GetInst()->SpawnFlash(Vec2(630, 90));
//	GameMgr::GetInst()->SpawnGiant(Vec2(630, 90));
//	GameMgr::GetInst()->SpawnToxino(Vec2(630, 90));

	
	m_Text = new TextMgr();
	m_Text->Init(50, true, false, "Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);


	//��ֹ��� ��
	ObjMgr->AddObject(new BlockMgr(Vec2(1170, 540 + 30), "column"), "Column");//��ֹ�

}

void Stage1::Release()
{
}

void Stage1::Update(float deltaTime, float time)
{
	m_Move += dt;
	if (m_Move > 1) {
		switch (m_Cut) {
		case 1:
			m_Virus->Translate(1000 * dt, 0);
			m_Cut++;
			m_Move = 0;
			break;
		case 2:
			m_Virus->Translate(0, -1000 * dt);
			m_Cut++;
			m_Move = 0;
			break;
		case 3:
			m_Virus->Translate(-1000 * dt, 0);
			m_Cut++;
			m_Move = 0;
			break;
		case 4:
			m_Virus->Translate(0, 1000 * dt);
			m_Cut = 1;
			m_Move = 0;
			break;
		}
	}
}

void Stage1::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(GameMgr::GetInst()->m_Hp), 160, 0);
	m_Text->print("Score : " + std::to_string(GameMgr::GetInst()->m_Score), 1920 / 2, 0);
	Renderer::GetInst()->GetSprite()->End();
	m_BG->Render();
	m_Virus->Render();
}
