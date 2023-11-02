#pragma once

#include "Util.h"
#include <stack>
#include <list>

class MapLogic;

class AStar
{
private:
	COORD target;

	stack<eDirection> path;
	list<COORD> visitNode;
	
	int distToTarget = -1;

	int pathOfMap[SCREEN_HEIGHT][SCREEN_WIDTH];


	void ResetPath();

	void ExtractMin(MapLogic* _map, COORD _choicePos, COORD _direction);
public:

	bool FindPath(MapLogic* _map, COORD _startPos, COORD _targetPos);

	eDirection GetDirection();
	int GetDist();
};

