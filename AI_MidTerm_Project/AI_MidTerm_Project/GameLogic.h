#pragma once

#include "Util.h"

class ScreenLogic;

class GameLogic
{
public:
	GameLogic();
	~GameLogic();

private:
	void Update();

	void Input();

	void PlayerMove();

private:
	ScreenLogic* screen;
	ePlayerInput input = E_NULL;
	
	COORD playerPos = {PLAYER_INIT_X, PLAYER_INIT_Y};
	int playerState = E_PLAYER_RIGHT;
};

