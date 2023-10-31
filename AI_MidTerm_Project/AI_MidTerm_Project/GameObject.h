#pragma once

#include "Util.h"

class MapLogic;

class GameObject
{
protected:
	eDirection moveDir = E_NULL;

	virtual eMap GetType() = 0;						//�ڽ��� eMap Ÿ�� ����
public:
	GameObject(COORD _pos) : pos(_pos) {}
	~GameObject() {}

	COORD pos;

	void Update(MapLogic* _map, eDirection _moveDir);

	virtual void Move(MapLogic* _map, eDirection _moveDir);
	virtual void CheckInMap(MapLogic* _map);

	virtual void StateUpdate();
	virtual void SetState(eDirection _dir);
};

