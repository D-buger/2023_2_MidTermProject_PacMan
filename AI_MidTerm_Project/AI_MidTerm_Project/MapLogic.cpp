#include "MapLogic.h"

MapLogic::MapLogic()
{
	LoadMap();
}

MapLogic::~MapLogic()
{
}

void MapLogic::LoadMap()
{
	std::ifstream readMap("PacMan.dat");
	int cnt = 0;
	char ch;
	if (!readMap) {
		cout << "[ERROR] Can't Open file" << endl;
	}
	while (readMap)
	{
		readMap.get(ch);
		if (ch == '\n')
			continue;
		map[cnt / SCREEN_WIDTH][cnt % SCREEN_WIDTH] = (eMap)(ch - '0');

		cnt++;
	}
	readMap.close();
}



eMap MapLogic::GetMap(COORD _pos)
{
	if (_pos.X < 0 || _pos.X >= SCREEN_WIDTH ||
		_pos.Y < 0 || _pos.Y >= SCREEN_HEIGHT)
		return E_MAP_OUT_OF_BOUNDS;
	return map[_pos.Y][_pos.X];
}

char* MapLogic::GetMapIcon(COORD _pos)
{
	eMap mapObj = (eMap)map[_pos.Y][_pos.X];

	switch (mapObj)
	{
	case E_MAP_EMPTY:
		return (char*)SCREEN_ICONS[E_NONE];
	case E_MAP_WALL:
		return (char*)SCREEN_ICONS[E_WALL];
	case E_MAP_PLAYER:
		return (char*)SCREEN_ICONS[player.GetType()];
	case E_MAP_FOOD:
		return (char*)SCREEN_ICONS[E_FOOD];
	case E_MAP_PILL:
		return (char*)SCREEN_ICONS[E_PILL];
	case E_MAP_GHOST:
		return (char*)SCREEN_ICONS[E_GHOST_HUNTER];
	default:
		return (char*)SCREEN_ICONS[E_NONE];
	}

	return nullptr;
}

void MapLogic::SetMap(COORD _pos, eMap _obj)
{
	map[_pos.Y][_pos.X] = _obj;
}

