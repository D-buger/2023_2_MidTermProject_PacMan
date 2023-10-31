#include "HuntedState.h"

HuntedState* HuntedState::instance = nullptr;

HuntedState::HuntedState()
{
}

HuntedState::~HuntedState()
{
	if (instance != nullptr)
		delete instance;
}

void HuntedState::Enter(Ghost*)
{
}

void HuntedState::Execute(Ghost*)
{
	//Change State
}

void HuntedState::Exit(Ghost*)
{
}

HuntedState* HuntedState::Instance()
{
	if (nullptr == instance) {
		instance = new HuntedState();
	}

	return instance;
}
