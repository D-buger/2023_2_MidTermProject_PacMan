#pragma once

#include "Util.h"

#include "ScreenLogic.h"
#include "MapLogic.h"

#include "Player.h"
#include "Ghost.h"

class GameLogic
{
public:
	GameLogic();
	~GameLogic();

private:
	void Update();
	void Draw();

	void Input();
	//void PlayerMove();

private:
	MapLogic* map;
	ScreenLogic* screen;

	Player player;
	//Ghost ghosts[GHOST_NUM];

	eDirection input = E_NULL;

	float time = 0;
	int score = 0;
	bool playerEatsPowerPill = false;
};

