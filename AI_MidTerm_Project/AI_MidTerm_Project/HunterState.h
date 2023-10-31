#pragma once
#include "State.h"

class HunterState : public State
{
public:
	HunterState();
	~HunterState();

	void Enter(Ghost*) override;
	void Execute(Ghost*) override;
	void Exit(Ghost*) override;

private:
	static HunterState* instance;
public:
	static HunterState* Instance();
};

