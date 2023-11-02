#pragma once
#include "State.h"

class InBoxState :public State
{
private:
	float timer = 0;

public:
	InBoxState();
	~InBoxState();

	void Enter(Ghost* _g) override;
	void Execute(Ghost* _g) override;
	void Exit(Ghost* _g) override;

private:
	static InBoxState* instance;
public:
	static InBoxState* Instance();
};

