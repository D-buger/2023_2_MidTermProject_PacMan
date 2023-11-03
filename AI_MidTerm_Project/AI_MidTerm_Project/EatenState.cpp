#include "EatenState.h"

EatenState* EatenState::instance = nullptr;

EatenState::EatenState()
{
}

EatenState::~EatenState()
{
	//if (instance != nullptr)
	//	delete instance;
}

void EatenState::Enter(Ghost* _g)
{
	_g->SetStateIcon(eScreenIcon::E_GHOST_EATEN);
}

#include "InBoxState.h"
void EatenState::Execute(Ghost* _g)
{
	_g->SetTargetToNULL();

	if (_g->GetIsCollisionGhostBox()) {
		_g->SetIsCollisionGhostBox(false);
		_g->ChangeState(InBoxState::Instance());
	}
}

void EatenState::Exit(Ghost* _g)
{
}

EatenState* EatenState::Instance()
{
	if (nullptr == instance) {
		instance = new EatenState();
	}

	return instance;
}
