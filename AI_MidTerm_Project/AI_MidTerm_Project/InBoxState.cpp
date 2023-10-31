#include "InBoxState.h"

InBoxState* InBoxState::instance = nullptr;

InBoxState::InBoxState()
{
}

InBoxState::~InBoxState()
{
	if (instance != nullptr)
		delete instance;
}

void InBoxState::Enter(Ghost*)
{
}

void InBoxState::Execute(Ghost*)
{
}

void InBoxState::Exit(Ghost*)
{
}

InBoxState* InBoxState::Instance()
{
	if (nullptr == instance) {
		instance = new InBoxState();
	}

	return instance;
}
