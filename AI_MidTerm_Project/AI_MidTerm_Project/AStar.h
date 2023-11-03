#pragma once

#include "Util.h"
#include <stack>
#include <list>
#include <queue>

class MapLogic;

class AStar
{
private:
	COORD target;

	stack<eDirection> path;
	list<COORD> visitNode;
	
	int distToTarget = -1;

	int pathOfMap[SCREEN_HEIGHT][SCREEN_WIDTH];
	COORD parent[SCREEN_HEIGHT][SCREEN_WIDTH];
	priority_queue<COORD> queue;

	void ResetPath();

	void AddToList(MapLogic* _map, COORD _choicePos);
public:

	bool FindPath(MapLogic* _map, COORD _startPos, COORD _targetPos);

	eDirection GetDirection();
	int GetDist();
};

