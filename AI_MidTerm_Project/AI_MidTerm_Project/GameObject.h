#pragma once

#include "Util.h"

class MapLogic;

class GameObject
{
protected:
	eDirection moveDir = E_NULL;
	eScreenIcon stateIcon = E_NONE;

	virtual eMap GetType() = 0;						//자신의 eMap 타입 리턴
public:
	byte COLOR;

	GameObject(COORD _pos, byte _color) : pos(_pos), COLOR(_color) {}
	~GameObject() {}

	COORD pos;

	virtual void Update(MapLogic* _map, eDirection _moveDir);

	virtual void Move(MapLogic* _map, eDirection _moveDir);

	virtual void StateUpdate();
	virtual void SetState(eDirection _dir);
	
	void SetStateIcon(eScreenIcon _icon) { stateIcon = _icon; }

	void SetMoveDirection(eDirection _dir) { moveDir = _dir; }
};

