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
	_g->SetIsPacManEatsPill(false);
	timer = 0;
	_g->SetStateIcon(eScreenIcon::E_GHOST_HUNTED);

	color = _g->COLOR;
	_g->COLOR = FOREGROUND_BLUE;
}

#include "HunterState.h"
#include "EatenState.h"
void HuntedState::Execute(Ghost* _g)
{
	if (_g->GetIsCollisionPacMan()) {
		_g->SetIsCollisionPacMan(false);
		_g->ChangeState(EatenState::Instance());
	}

	else if (timer >= END_TIME_OF_HUNTED) {
		_g->ChangeState(HunterState::Instance());
	}
	else {
		timer++;
	}
}

void HuntedState::Exit(Ghost* _g)
{
	_g->COLOR = color;
}

HuntedState* HuntedState::Instance()
{
	if (nullptr == instance) {
		instance = new HuntedState();
	}

	return instance;
}
