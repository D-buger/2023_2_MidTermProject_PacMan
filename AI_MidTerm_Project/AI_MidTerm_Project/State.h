#pragma once
#include "Ghost.h"

class State {
public:
	virtual void Enter(Ghost*) {}
	virtual void Execute(Ghost*) {}
	virtual void Exit(Ghost*) {}
};