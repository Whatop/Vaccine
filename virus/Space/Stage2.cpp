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

	SceneDirector::GetInst()->SetScene(SceneState::STAGE2);
	GameMgr::GetInst()->CreatePlayer();
	GameMgr::GetInst()->SpawnGiant(Vec2(300,300));
	GameMgr::GetInst()->SpawnFast(Vec2(300,300));
	GameMgr::GetInst()->SetLimit();
	GameMgr::GetInst()->SpawnItem(Vec2(0, 0)); // ����ǥ�� �׳� �ӽ���ǥ ��ģ���� �����ټ� �ִ°��� ����


	m_Text = new TextMgr();
	m_Text->Init(50, true, false, "Determination Mono");
	m_Text->SetColor(255, 255, 255, 255);

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
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(GameMgr::GetInst()->m_Hp), 160, 0);
	m_Text->print("Score : " + std::to_string(GameMgr::GetInst()->m_Score),1920/2, 0);
	Renderer::GetInst()->GetSprite()->End();
}
