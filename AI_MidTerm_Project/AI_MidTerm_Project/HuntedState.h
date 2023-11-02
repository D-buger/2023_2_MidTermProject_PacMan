#pragma once
#include "State.h"

class HuntedState :  public State
{
private:
	float timer = 0;
	byte color;
public:
	HuntedState();
	~HuntedState();

	void Enter(Ghost* _g) override;
	void Execute(Ghost* _g) override;
	void Exit(Ghost* _g) override;

private:
	static HuntedState* instance;
public:
	static HuntedState* Instance();
};

