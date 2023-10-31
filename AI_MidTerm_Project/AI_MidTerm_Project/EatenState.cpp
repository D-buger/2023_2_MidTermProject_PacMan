#include "EatenState.h"

EatenState* EatenState::instance = nullptr;

EatenState::EatenState()
{
}

EatenState::~EatenState()
{
	if (instance != nullptr)
		delete instance;
}

void EatenState::Enter(Ghost*)
{
}

void EatenState::Execute(Ghost*)
{
}

void EatenState::Exit(Ghost*)
{
}

EatenState* EatenState::Instance()
{
	if (nullptr == instance) {
		instance = new EatenState();
	}

	return instance;
}
