#pragma once
#include "State.h"

class HuntedState :  public State
{
public:
	HuntedState();
	~HuntedState();

	void Enter(Ghost*) override;
	void Execute(Ghost*) override;
	void Exit(Ghost*) override;

private:
	static HuntedState* instance;
public:
	static HuntedState* Instance();
};

