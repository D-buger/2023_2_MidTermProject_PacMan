#include "GameLogic.h"
#include "ScreenLogic.h"

GameLogic::GameLogic()
{
	screen = new ScreenLogic(SCREEN_WIDTH, SCREEN_HEIGHT);
	map = new MapLogic();
	Update();
}

GameLogic::~GameLogic()
{
	delete screen;
	delete map;
}

void GameLogic::Update()
{
	while (true) {
		Sleep(SCREEN_DELAY);
		screen->ScreenClear();
		Input();

		player.Move(map, input);


		Draw();
		screen->ScreenFlipping();
	}
}

void GameLogic::Draw()
{
	COORD drawPos;
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			drawPos.X = j;
			drawPos.Y = i;
			if (player.pos == drawPos) {
				screen->ScreenPrint(drawPos, (char*)SCREEN_ICONS[player.GetType()]);
			}
			else {

				if (map->GetMap(drawPos) == E_MAP_PLAYER)
					screen->ScreenPrint(drawPos, map->GetMapIcon(drawPos), FOREGROUND_YELLOW);
				else if (map->GetMap(drawPos) == E_MAP_FOOD || map->GetMap(drawPos) == E_MAP_PILL)
					screen->ScreenPrint(drawPos, map->GetMapIcon(drawPos), FOREGROUND_LIGHT_YELLOW);
				else
					screen->ScreenPrint(drawPos, map->GetMapIcon(drawPos), FOREGROUND_BLUE);
			}
		}
	}
}

void GameLogic::Input()
{
	if (_kbhit()) {
		int in = _getch();
		if (in == ARROW_KEY) {
			in = _getch();
			switch (in)
			{
			case E_LEFT:
			case E_RIGHT:
			case E_UP:
			case E_DOWN:
				input = (eDirection)in;
				break;
			default:
				input = (eDirection)E_NULL;
				break;
			}
		}
	}
	//else input = (ePlayerInput)E_NULL;
}