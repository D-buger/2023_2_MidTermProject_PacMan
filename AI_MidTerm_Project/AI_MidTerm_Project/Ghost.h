#pragma once

#include "Util.h"
#include "GameObject.h"

class State;

class Ghost : public GameObject
{
private:
	State* currentState;

public:
	Ghost(COORD _pos);
	~Ghost();

	// GameObject��(��) ���� ��ӵ�
	eMap GetType() override;

	void Move(MapLogic* _map, eDirection _moveDir) override;

	void StateUpdate() override;
	void SetState(eDirection _dir) override;

	void ChangeState(State* _pNewState);
};

