#include "Ghost.h"
#include "State.h"
#include "Player.h"
#include "MapLogic.h"

#include "HunterState.h"
Ghost::Ghost(COORD _pos, byte _color, int _startTime) : GameObject(_pos, _color), oriColor(_color)
{
	stateIcon = E_GHOST_HUNTER;
	currentState = HunterState().Instance();
}

Ghost::~Ghost()
{

}

void Ghost::SetTargetToNULL()
{
	target = nullptr;
}

void Ghost::SetTarget(MapLogic* _map, Player* _player)
{
	target = _player;
}

eMap Ghost::GetType()
{
    return (eMap)stateIcon;
}

void Ghost::CheckState(MapLogic* _map, Player* _player) {

}

//Hunter (NULL) : random move
//Hunter (player) : A* to player
//Hunted (player) : A* to opposite player
//Eaten (any) : A* to GhostBox 
void Ghost::Update(MapLogic* _map, eDirection _moveDir)
{
	currentState->Execute(this);

	if (canMove) {
		if (target != nullptr) {
			path.FindPath(_map, this->pos, target->pos);

			if (isPacManEatsPill) {											//플레이어가 알약을 먹었을 때
				COORD playerDir = target->pos - this->pos;

				eDirection eDir[4] = { E_NULL, E_NULL , E_NULL , E_NULL };
				int num = 0;
				if (_map->GetMap(this->pos + MakeCoord(1, 0)) != E_MAP_WALL
					&& playerDir.X <= 0) {
					eDir[num++] = eDirection::E_RIGHT;
				}
				if (_map->GetMap(this->pos + MakeCoord(-1, 0)) != E_MAP_WALL
					&& playerDir.X >= 0) {
					eDir[num++] = eDirection::E_LEFT;
				}
				if (_map->GetMap(this->pos + MakeCoord(0, 1)) != E_MAP_WALL
					&& playerDir.Y <= 0) {
					eDir[num++] = eDirection::E_DOWN;
				}
				if (_map->GetMap(this->pos + MakeCoord(0, -1)) != E_MAP_WALL
					&& playerDir.Y >= 0) {
					eDir[num++] = eDirection::E_UP;
				}

				if (num > 0) {
					moveDir = eDir[rand() % num];
				}

			}
			else if (path.GetDist() <= RECOGNIZE_PLAYER) {					//플레이어가 탐지 범위 안에 들어왔을 때
				moveDir = path.GetDirection(this->pos);
			}
			else {										//가야할 방향이 정해져있지 않을 때
				eDirection eRandDir[4] = { E_NULL, E_NULL , E_NULL , E_NULL };
				int num = 0;
				if (_map->GetMap(this->pos + MakeCoord(1, 0)) != E_MAP_WALL) {
					eRandDir[num++] = eDirection::E_RIGHT;
				}
				if (_map->GetMap(this->pos + MakeCoord(-1, 0)) != E_MAP_WALL) {
					eRandDir[num++] = eDirection::E_LEFT;
				}
				if (_map->GetMap(this->pos + MakeCoord(0, 1)) != E_MAP_WALL) {
					eRandDir[num++] = eDirection::E_DOWN;
				}
				if (_map->GetMap(this->pos + MakeCoord(0, -1)) != E_MAP_WALL) {
					eRandDir[num++] = eDirection::E_UP;
				}
				moveDir = eRandDir[rand() % num];
			}
		}
		else {
			path.FindPath(_map, this->pos, COORD({ GHOSTBOX_X, GHOSTBOX_Y }));
			moveDir = path.GetDirection(this->pos);
		}

		GameObject::Update(_map, moveDir);
	}
}

void Ghost::Move(MapLogic* _map, eDirection _moveDir)
{
    GameObject::Move(_map, _moveDir);
}

void Ghost::StateUpdate()
{
}

void Ghost::SetState(eDirection _dir)
{

}

void Ghost::ChangeState(State* _pNewState)
{
	currentState->Exit(this);
	currentState = _pNewState;
	currentState->Enter(this);
	currentState->Execute(this);
}
