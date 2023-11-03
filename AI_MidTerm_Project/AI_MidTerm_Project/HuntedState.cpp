#include "HuntedState.h"

HuntedState* HuntedState::instance = nullptr;

HuntedState::HuntedState()
{
}

HuntedState::~HuntedState()
{
	//if (instance != nullptr)
	//	delete instance;
}

void HuntedState::Enter(Ghost* _g)
{
	timer = 0;
	_g->SetStateIcon(eScreenIcon::E_GHOST_HUNTED);

	_g->COLOR = FOREGROUND_BLUE;
}

#include "HunterState.h"
#include "EatenState.h"
void HuntedState::Execute(Ghost* _g)
{
	timer++;
	if (_g->GetIsCollisionPacMan()) {
		_g->SetIsPacManEatsPill(false);
		_g->SetIsCollisionPacMan(false);
		_g->ChangeState(EatenState::Instance());
	}
	else if (timer >= END_TIME_OF_HUNTED) {
		_g->SetIsPacManEatsPill(false);
		_g->ChangeState(HunterState::Instance());
	}
	else {
		_g->SetCanMove(!_g->GetCanMove());
	}
}

void HuntedState::Exit(Ghost* _g)
{
	_g->SetCanMove(true);
	_g->COLOR = _g->oriColor;
}

HuntedState* HuntedState::Instance()
{
	if (nullptr == instance) {
		instance = new HuntedState();
	}

	return instance;
}
