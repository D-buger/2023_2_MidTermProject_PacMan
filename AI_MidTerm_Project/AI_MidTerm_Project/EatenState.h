#pragma once
#include "State.h"

class EatenState : public State
{
public:
	EatenState();
	~EatenState();

	void Enter(Ghost* _g) override;
	void Execute(Ghost* _g) override;
	void Exit(Ghost* _g) override;

private:
	static EatenState* instance;
public:
	static EatenState* Instance();
};

