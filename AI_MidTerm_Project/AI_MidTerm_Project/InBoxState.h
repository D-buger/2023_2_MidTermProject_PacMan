#pragma once
#include "State.h"

class InBoxState :public State
{
public:
	InBoxState();
	~InBoxState();

	void Enter(Ghost*) override;
	void Execute(Ghost*) override;
	void Exit(Ghost*) override;

private:
	static InBoxState* instance;
public:
	static InBoxState* Instance();
};

