#include "GameObject.h"
#include "MapLogic.h"

void GameObject::Update(MapLogic* _map, eDirection _moveDir)
{
	Move(_map, _moveDir);
}

void GameObject::Move(MapLogic* _map, eDirection _moveDir)
{
	switch (_moveDir)
	{
	case E_UP:
		if (_map->GetMap(pos + MakeCoord(0, -1)) == E_MAP_OUT_OF_BOUNDS) {
			pos.Y = SCREEN_HEIGHT - 1;
		}
		else if (_map->GetMap(pos + MakeCoord(0, -1)) != E_MAP_WALL) {
			pos.Y -= 1;
			moveDir = _moveDir;
			SetState(_moveDir);
			StateUpdate();
		}
		else if(moveDir != _moveDir){
			Move(_map, moveDir);
		}
		break;
	case E_LEFT:
		if (_map->GetMap(pos + MakeCoord(-1, 0)) == E_MAP_OUT_OF_BOUNDS) {
			pos.X = SCREEN_WIDTH - 1;
		}
		else if (_map->GetMap(pos + MakeCoord(-1, 0)) != E_MAP_WALL) {
			pos.X -= 1;
			moveDir = _moveDir;
			SetState(_moveDir);
			StateUpdate();
		}
		else if (moveDir != _moveDir) {
			Move(_map, moveDir);
		}
		break;
	case E_RIGHT:
		if (_map->GetMap(pos + MakeCoord(1, 0)) == E_MAP_OUT_OF_BOUNDS) {
			pos.X = 0;
		}
		else if (_map->GetMap(pos + MakeCoord(1, 0)) != E_MAP_WALL) {
			pos.X += 1;
			moveDir = _moveDir;
			SetState(_moveDir);
			StateUpdate();
		}
		else if (moveDir != _moveDir) {
			Move(_map, moveDir);
		}
		break;
	case E_DOWN:
		if (_map->GetMap(pos + MakeCoord(0, 1)) == E_MAP_OUT_OF_BOUNDS) {
			pos.Y = 0;
		}
		else if (_map->GetMap(pos + MakeCoord(0, 1)) != E_MAP_WALL) {
			pos.Y += 1;
			moveDir = _moveDir;
			SetState(_moveDir);
			StateUpdate();
		}
		else if (moveDir != _moveDir) {
			Move(_map, moveDir);
		}
		break;
	case E_NULL:
		break;
	}
}

void GameObject::StateUpdate()
{
}

void GameObject::SetState(eDirection _dir)
{

}
