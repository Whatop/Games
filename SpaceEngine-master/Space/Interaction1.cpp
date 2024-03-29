#include "stdafx.h"
#include "Interaction1.h"

Interaction1::Interaction1(Vec2 Pos,std::string string)
{
	m_Interaction = new Animation();
	m_Interaction->SetParent(this);
	if (string == "Save" || string == "save") {
		m_Save = new Animation();
		m_Save->SetParent(this);
		m_Save->Init(1, false);
		m_Save->AddContinueFrame(L"Painting/Save", 0, 3);
		m_Interaction = m_Save;
	}
	else if (string == "Chest" || string == "chest") {
		m_Chest = new Animation();
		m_Chest->SetParent(this);
		m_Chest->Init(1, false);
		m_Chest->AddContinueFrame(L"Painting/Chest", 0, 3);
		m_Interaction = m_Chest;
	}
	else if (string == "Stat" || string == "stat") {
		m_State = new Animation();
		m_State->SetParent(this);
		m_State->Init(1, false);
		m_State->AddContinueFrame(L"Painting/Interaction", 1, 3);
		m_Interaction = m_State;
	}
	SetPosition(Pos);
	m_Interaction->m_CurrentFrame = 1;
	delayTime = 0;
	Game::GetInst()->Count++;
}

Interaction1::~Interaction1()
{
}


void Interaction1::Update(float deltaTime, float Time)
{
	if (Game::GetInst()->Count == 1) {
		delayTime += dt;
		std::cout << delayTime << std::endl;
		if (INPUT->GetKey(VK_LEFT) == KeyState::DOWN) {
			m_Interaction->m_CurrentFrame = 1;
		}
		else if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN && m_Interaction->m_CurrentFrame == 1) {
			m_Interaction->m_CurrentFrame = 2;
		}
		if (m_Interaction->m_CurrentFrame == 3) {
			if (INPUT->GetKey('Z') == KeyState::DOWN && delayTime > 0.3f) {//이것은 꼼수 Z눌렀을때 3으로 바로넘어가서 제한걸어놓음
				ObjMgr->RemoveObject(this);
				SceneDirector::GetInst()->m_Move = Interaction::MOVE;
				Game::GetInst()->isCount = true;
			}
		}
		else if (m_Interaction->m_CurrentFrame == 1) {
			if (INPUT->GetKey('Z') == KeyState::DOWN && delayTime > 0.3f) {//이것은 꼼수 Z눌렀을때 3으로 바로넘어가서 제한걸어놓음
				m_Interaction->m_CurrentFrame = 3;
			}
		} 
		else if (INPUT->GetKey('X') == KeyState::DOWN) {
			ObjMgr->RemoveObject(this);
			SceneDirector::GetInst()->m_Move = Interaction::MOVE;
			Game::GetInst()->isCount = true;
		}


	}
	else {
		ObjMgr->RemoveObject(this);
		Game::GetInst()->Count = 0;
	}
}

void Interaction1::Render()
{
	m_Interaction->Render();
}
