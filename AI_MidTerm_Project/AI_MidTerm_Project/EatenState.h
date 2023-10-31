#pragma once
#include "State.h"

class EatenState : public State
{
public:
	EatenState();
	~EatenState();

	void Enter(Ghost*) override;
	void Execute(Ghost*) override;
	void Exit(Ghost*) override;

private:
	static EatenState* instance;
public:
	static EatenState* Instance();
};

