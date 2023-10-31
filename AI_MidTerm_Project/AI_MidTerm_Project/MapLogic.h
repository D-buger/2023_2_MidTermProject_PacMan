#pragma once

#include "Util.h"
#include "Player.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include<cstdlib>

class MapLogic
{
private:
	eMap map[SCREEN_HEIGHT][SCREEN_WIDTH];

	Player player;

public:
	MapLogic();
	~MapLogic();

	void LoadMap();

	eMap GetMap(COORD _pos);
	char* GetMapIcon(COORD _pos);
	void SetMap(COORD _pos, eMap _obj);

	Player* GetPlayer() { return &player; }
};

