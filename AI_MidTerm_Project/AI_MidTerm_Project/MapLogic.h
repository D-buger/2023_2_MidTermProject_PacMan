#pragma once

#include "Util.h"

#include <filesystem>
#include <fstream>

enum eMap {
	E_MAP_EMPTY			= 0,
	E_MAP_WALL			= 1,
	E_MAP_PLAYER		= 2,
	E_MAP_FOOD			= 3,
	E_MAP_POWERCOOKIE	= 4,
	E_MAP_GHOST			= 5,

	E_MAP_TELEPORT_R	= 6,
	E_MAP_TELEPORT_L	= 7,
};

class MapLogic
{
private:
	int** map;

	COORD player;

public:
	MapLogic();
	~MapLogic();

	void LoadMap();

	char* GetMap(COORD _pos);
};

