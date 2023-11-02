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

	static COORD DirToPos(eDirection _dir) {
		switch (_dir)
		{
		case E_UP:
			return COORD({ 0, -1 });
		case E_LEFT:
			return COORD({ -1, 0 });
		case E_RIGHT:
			return COORD({ 1, 0 });
		case E_DOWN:
			return COORD({ 0, 1 });
		case E_NULL:
		default:
			return COORD({ 0, 0 });
		}
	}
	static eDirection OppositeDir(eDirection _dir) {
		switch (_dir)
		{
		case E_UP:
			return eDirection::E_DOWN;
		case E_LEFT:
			return eDirection::E_RIGHT;
		case E_RIGHT:
			return eDirection::E_LEFT;
		case E_DOWN:
			return eDirection::E_UP;
		case E_NULL:
		default:
			return eDirection::E_NULL;
		}
	}
};

