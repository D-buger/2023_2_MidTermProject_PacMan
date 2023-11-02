#include "HunterState.h"

HunterState* HunterState::instance = nullptr;

HunterState::HunterState()
{
}

HunterState::~HunterState()
{
	//if (instance != nullptr)
	//	delete instance;
}

void HunterState::Enter(Ghost* _g)
{
	_g->SetStateIcon(eScreenIcon::E_GHOST_HUNTER);
}

#include "HuntedState.h"
void HunterState::Execute(Ghost* _g)
{
	if (_g->GetIsPacManEatsPill()) {
		_g->ChangeState(HuntedState::Instance());
	}
}

void HunterState::Exit(Ghost* _g)
{
}

HunterState* HunterState::Instance()
{
	if (nullptr == instance) {
		instance = new HunterState();
	}

	return instance;
}