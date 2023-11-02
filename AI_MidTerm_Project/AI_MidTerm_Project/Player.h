#pragma once

#include "Util.h"
#include "GameObject.h"

class Player : public GameObject
{
private:
	int playerAnimState = 0;
public:
	Player() : GameObject({ PLAYER_INIT_X, PLAYER_INIT_Y }, FOREGROUND_YELLOW) { stateIcon = E_PLAYER_RIGHT; }
	~Player() {}

	// GameObject을(를) 통해 상속됨
	eMap GetType() override;

	void Update(MapLogic* _map, eDirection _moveDir) override;

	void Move(MapLogic* _map, eDirection _moveDir) override;

	void StateUpdate() override;
	void SetState(eDirection _dir) override;
};

