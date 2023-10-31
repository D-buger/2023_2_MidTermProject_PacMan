#include "HunterState.h"

HunterState* HunterState::instance = nullptr;

HunterState::HunterState()
{
}

HunterState::~HunterState()
{
	if (instance != nullptr)
		delete instance;
}

void HunterState::Enter(Ghost*)
{
}

void HunterState::Execute(Ghost*)
{
}

void HunterState::Exit(Ghost*)
{
}

HunterState* HunterState::Instance()
{
	if (nullptr == instance) {
		instance = new HunterState();
	}

	return instance;
}