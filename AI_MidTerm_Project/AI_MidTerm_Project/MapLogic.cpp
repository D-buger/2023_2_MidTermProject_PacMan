#include "MapLogic.h"

MapLogic::MapLogic()
{
}

MapLogic::~MapLogic()
{
}

void MapLogic::LoadMap()
{
	std::ifstream readMap;
	int cnt = 0;
	char ch;
	readMap.open("PacMan.dat");
	if (readMap.is_open()) {
		while (!readMap.eof())
		{
			readMap.get(ch);
			
			map[cnt / SCREEN_WIDTH][cnt % SCREEN_WIDTH] = ch - '0';
			cnt++;
			if (map[cnt / SCREEN_WIDTH][cnt % SCREEN_WIDTH] == E_MAP_PLAYER) {
				player.X = cnt % SCREEN_WIDTH;
				player.Y = cnt / SCREEN_WIDTH;
			}
		}
	}
	readMap.close();
}

char* MapLogic::GetMap(COORD _pos)
{
	int mapObj = map[_pos.Y][_pos.X];



	return nullptr;
}
