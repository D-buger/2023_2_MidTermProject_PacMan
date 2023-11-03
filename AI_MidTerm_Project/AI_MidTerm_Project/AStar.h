#pragma once

#include "Util.h"
#include <stack>
#include <list>
#include <queue>

class MapLogic;

class Point {
public:
	COORD pos;
	int cost;
	bool operator<(const Point& p) const
	{
		return cost > p.cost;
	}
};

class AStar
{
private:
	stack<eDirection> path;
	list<COORD> visitNode;
	
	bool isFound = false;

	bool visitInfo[SCREEN_HEIGHT][SCREEN_WIDTH];
	int pathOfMap[SCREEN_HEIGHT][SCREEN_WIDTH];
	Point parent[SCREEN_HEIGHT][SCREEN_WIDTH];
	priority_queue<Point> queue;

	void ResetPath();

	void AddToList(MapLogic* _map, Point _choice, COORD _targetPos);

public:

	bool FindPath(MapLogic* _map, COORD _startPos, COORD _targetPos);

	eDirection GetDirection(COORD _oriPos);
	int GetDist();
};

