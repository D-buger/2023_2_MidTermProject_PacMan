#include "AStar.h"
#include "MapLogic.h"

void AStar::ResetPath()
{
	for (int i = 0; i < SCREEN_HEIGHT; i++)
		for (int j = 0; j < SCREEN_WIDTH; j++)
			pathOfMap[i][j] = -1;
	while (!path.empty()) path.pop();
	while (!visitNode.empty()) visitNode.pop_back();
	distToTarget = -1;
}

void AStar::ExtractMin(MapLogic* _map, COORD _choicePos, COORD _direction)
{
	int min = INT_MAX;
	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;

	short curX, curY;
	list<COORD>::reverse_iterator curPos;
	int hx, hy, hdist;

	for (curPos = visitNode.rbegin(); curPos != visitNode.rend(); curPos++) {
		for (int ty = -1; ty <= 1; ty++) {
			for (int tx = -1; tx <= 1; tx++) {
				curX = curPos->X + tx;
				curY = curPos->Y + ty;

				if (curX < 0 || curX > width - 1 || curY < 0 || curY > height - 1
					|| (tx == 0 && ty == 0)) {
					continue;
				}

				hx = _direction.X - curX;
				hy = _direction.X - curY;
				hdist = hx + hy;

				if (pathOfMap[curY][curX] + hdist < min ||
					pathOfMap[curY][curX] == -1) {
					min = pathOfMap[curY][curX] + hdist;
					_choicePos = { curX, curY };
				}
			}
		}
	}
}

bool AStar::FindPath(MapLogic* _map, COORD _startPos, COORD _targetPos)
{
	ResetPath();

	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;

	COORD parent[SCREEN_HEIGHT][SCREEN_WIDTH] = {0};

	COORD choicePos = { _startPos.X, _startPos.Y };
	parent[_startPos.X][_startPos.Y] = choicePos;

	for (int i = 0; i < width * height; i++) {
		visitNode.push_back(choicePos);

		if (choicePos.X == _targetPos.X && choicePos.Y == _targetPos.Y) {
			distToTarget = pathOfMap[choicePos.Y][choicePos.X];
			break;
		}

		for (int ty = -1; ty <= 1; ty++) {
			for (int tx = -1; tx <= 1; tx++) {
				int nx = choicePos.X + tx;
				int ny = choicePos.Y + ty;
				int dist;

				if (nx < 0 || nx > width - 1 || ny < 0 || ny > height - 1)
					continue;

				if (_map->GetMap(MakeCoord(nx, ny)) == E_MAP_WALL) {
					pathOfMap[ny][nx] = INT_MAX;
				}
				else if (pathOfMap[ny][nx] == -1 && pathOfMap[ny][nx] != INT_MAX) {
					dist = 1;

					if (pathOfMap[ny][nx] > pathOfMap[choicePos.Y][choicePos.X] + dist) {
						int tcost = pathOfMap[ny][nx] + dist;
						pathOfMap[ny][nx] = tcost;
						parent[ny][nx] = choicePos;
					}
				}
			}
		}
		ExtractMin(_map ,choicePos, _targetPos);
	}

	if (distToTarget != -1) {
		COORD p = { _targetPos.X, _targetPos.Y };
		while (p.X != _startPos.X || p.Y != _startPos.Y) {
			p = parent[p.Y][p.X];

			if (p.Y < _targetPos.Y) {
				path.push(eDirection::E_UP);
			}
			else {
				path.push(eDirection::E_DOWN);
			}

			if (p.X < _targetPos.X) {
				path.push(eDirection::E_LEFT);
			}
			else {
				path.push(eDirection::E_RIGHT);
			}
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
