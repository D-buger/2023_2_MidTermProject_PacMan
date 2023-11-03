#include "AStar.h"
#include "MapLogic.h"

void AStar::ResetPath()
{
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			pathOfMap[i][j] = -1;
			visitInfo[i][j] = false;
		}
	}
	while (!queue.empty()) queue.pop();
	while (!path.empty()) path.pop();
	while (!visitNode.empty()) visitNode.pop_back();
}

void AStar::AddToList(MapLogic* _map, Point _choice, COORD _targetPos)
{
	int yy[] = {0, 0, 1, -1};
	int xx[] = {1, -1, 0, 0};

	for (int i = 0; i < 4; i++) {
			int x = _choice.pos.X + xx[i];
			int y = _choice.pos.Y + yy[i];

			if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
				continue;
			}

			if (_map->GetMap(MakeCoord(x, y)) == E_MAP_WALL) {
				continue;
			}

			int cost = _choice.cost + abs(_targetPos.X - x) + abs(_targetPos.Y - y);

			if (!visitInfo[y][x] && (cost < pathOfMap[y][x] || pathOfMap[y][x] == -1)) {
				pathOfMap[y][x] = cost;
				queue.push({MakeCoord(x, y), cost});
				parent[y][x] = _choice;
			}
	}
}

bool AStar::FindPath(MapLogic* _map, COORD _startPos, COORD _targetPos)
{
	ResetPath();

	queue.push({_startPos.X, _startPos.Y, 0});
	parent[_startPos.Y][_startPos.X] = {_startPos.X, _startPos.Y};
	pathOfMap[_startPos.Y][_startPos.X] = 0;
	
	while (!queue.empty()) {
		Point top = queue.top();
		queue.pop();

		if (visitInfo[top.pos.Y][top.pos.X]) {
			continue;
		}
		else {
			visitInfo[top.pos.Y][top.pos.X] = true;
		}

		if (top.pos.X == _targetPos.X && top.pos.Y == _targetPos.Y) {
			isFound = true;
			break;
		}

		AddToList(_map, top, _targetPos);
	}

	if (isFound) {
		COORD c = {_targetPos.X, _targetPos.Y};
		COORD p = parent[c.Y][c.X].pos;
		while (c.X != _startPos.X || c.Y != _startPos.Y) {
			if (c.Y < p.Y) {
				path.push(eDirection::E_UP);
			}
			else if (c.Y > p.Y) {
				path.push(eDirection::E_DOWN);
			}

			if (c.X < p.X) {
				path.push(eDirection::E_LEFT);
			}
			else if (c.X > p.X) {
				path.push(eDirection::E_RIGHT);
			}

			c = p;
			p = parent[c.Y][c.X].pos;
		}
		return true;
	}
	return false;
}

eDirection AStar::GetDirection(COORD _oriPos)
{
	if (isFound && !path.empty()) {
		eDirection top = path.top();
		path.pop();
		return top;
	}
	return eDirection::E_NULL;
}

int AStar::GetDist()
{
	return path.size();
}
