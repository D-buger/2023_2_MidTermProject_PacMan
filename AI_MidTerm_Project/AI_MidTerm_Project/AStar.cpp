#include "AStar.h"
#include "MapLogic.h"

void AStar::ResetPath()
{
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			pathOfMap[i][j] = -1;
			parent[i][j] = {0, 0};
		}
	}
	while (!path.empty()) path.pop();
	while (!visitNode.empty()) visitNode.pop_back();
	distToTarget = -1;
}

void AStar::AddToList(MapLogic* _map, COORD _choicePos)
{
	for (int ty = -1; ty <= 1; ty++) {
		for (int tx = -1; tx <= 1; tx++) {
			int x = _choicePos.X + tx;
			int y = _choicePos.Y + ty;

			if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
				continue;
			}

			if (_map->GetMap(MakeCoord(x, y)) == E_MAP_WALL) {
				continue;
			}

			int cost = pathOfMap[_choicePos.Y][_choicePos.X] + 1;

			if (pathOfMap[y][x] == -1 || cost < pathOfMap[y][x]) {
				pathOfMap[y][x] = cost;
				queue.push(MakeCoord(x, y));
				parent[y][x] = _choicePos;
			}
		}
	}
}

bool AStar::FindPath(MapLogic* _map, COORD _startPos, COORD _targetPos)
{
	ResetPath();

	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;

	queue.push({_startPos.X, _startPos.Y});
	parent[_startPos.Y][_startPos.X] = {_startPos.X, _startPos.Y};
	pathOfMap[_startPos.Y][_startPos.X] = 0;
	
	while (!queue.empty()) {
		COORD top = queue.top();
		queue.pop();

		if (pathOfMap[top.Y][top.X] != -1) {
			continue;
		}

		if (top.X == _targetPos.X && top.Y == _targetPos.Y) {
			distToTarget = pathOfMap[top.Y][top.X];
			break;
		}

		COORD topParent = parent[top.Y][top.X];
		pathOfMap[top.Y][top.X] = pathOfMap[topParent.Y][topParent.X] + 1;

		AddToList(_map, _startPos);
	}

	if (distToTarget != -1) {
		COORD c = {_targetPos.X, _targetPos.Y};
		COORD p = parent[c.Y][c.X];
		while (p.X != _startPos.X || p.Y != _startPos.Y) {
			path.push(MapLogic::PosToDir(c - p));
			c = p;
			p = parent[c.Y][c.X];
		}
		return true;
	}
	return false;
}

eDirection AStar::GetDirection()
{
	if (distToTarget != -1) {
		eDirection top = path.top();
		path.pop();
		return top;
	}
	return eDirection::E_NULL;
}

int AStar::GetDist()
{
	return distToTarget;
}
