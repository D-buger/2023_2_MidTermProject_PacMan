#include "InBoxState.h"

InBoxState* InBoxState::instance = nullptr;

InBoxState::InBoxState()
{
}

InBoxState::~InBoxState()
{
	//if (instance != nullptr)
	//	delete instance;
}

void InBoxState::Enter(Ghost* _g)
{
	_g->SetStateIcon(eScreenIcon::E_GHOST_HUNTER);
	timer = 0;
}

#include "HunterState.h"
void InBoxState::Execute(Ghost* _g)
{
	_g->SetTargetToNULL();

	if (timer >= END_TIME_OF_INBOX) {
		_g->ChangeState(HunterState::Instance());
	}
	else {
		timer++;
	}
}

void InBoxState::Exit(Ghost* _g)
{
}

InBoxState* InBoxState::Instance()
{
	if (nullptr == instance) {
		instance = new InBoxState();
	}

	return instance;
}
