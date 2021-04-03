#include "stdafx.h"
#include "Stage2.h"
#include "Player.h"

Stage2::Stage2()
{
}

Stage2::~Stage2()
{
}
//��Ʈ�� ����� -> �޴����� ���ӼҰ�, ���ӹ��, ���ӷ�ŷ. ũ���� ����
void Stage2::Init() // �������� 1 ��� ��ü�� �ϰ�, �������� 2�� ����� ������ �Ѵ�. �ٴ� ���̶�� �ʷ��ʷ��ϸ� �����Ⱑ �Ȼ�� 
{
	ObjMgr->Release();

	m_BG = Sprite::Create(L"Painting/Stage1/Stage1.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);
	m_Virus = Sprite::Create(L"Painting/Stage1/Virus.png");
	m_Virus->SetPosition(1920 / 2, 1080 / 2);

	SceneDirector::GetInst()->SetScene(SceneState::STAGE2);
	GameMgr::GetInst()->ReleaseUI();
	GameMgr::GetInst()->CreatePlayer();
	GameMgr::GetInst()->SetLimit();
	GameMgr::GetInst()->CreateUI();
	GameMgr::GetInst()->SpawnItem();
	GameMgr::GetInst()->SpawnEnemy();

	m_Cut = 0;
	m_Move = 0;

}

void Stage2::Release()
{
}

void Stage2::Update(float deltaTime, float time)
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

void Stage2::Render()
{
	m_BG->Render();
	m_Virus->Render();
}
