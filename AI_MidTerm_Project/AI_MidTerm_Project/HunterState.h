#pragma once
#include "State.h"
#include "AStar.h"

class HunterState : public State
{
private:
	//AStar shortestPath();

public:
	HunterState();
	~HunterState();

	void Enter(Ghost* _g) override;
	void Execute(Ghost* _g) override;
	void Exit(Ghost* _g) override;

private:
	static HunterState* instance;
public:
	static HunterState* Instance();
};

