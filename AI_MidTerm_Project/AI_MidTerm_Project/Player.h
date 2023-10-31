#pragma once

#include "Util.h"
#include "GameObject.h"

class Player : public GameObject
{
private:
	int playerState = E_PLAYER_RIGHT;
	int playerAnimState = 0;
public:
	Player() : GameObject({ PLAYER_INIT_X, PLAYER_INIT_Y }) {}
	~Player() {}

	// GameObject을(를) 통해 상속됨
	eMap GetType() override;

	void Move(MapLogic* _map, eDirection _moveDir) override;
	void CheckInMap(MapLogic* _map) override;

	void StateUpdate() override;
	void SetState(eDirection _dir) override;
};

