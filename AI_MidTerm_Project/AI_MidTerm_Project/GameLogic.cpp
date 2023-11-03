#include "GameLogic.h"
#include "ScreenLogic.h"

GameLogic::GameLogic()
{
	screen = new ScreenLogic(SCREEN_WIDTH, SCREEN_HEIGHT);
	map = new MapLogic();
	
	ghosts[0] = new Ghost(COORD({GHOSTBOX_X, GHOSTBOX_Y}),			FOREGROUND_LIGHT_PURPLE);
	ghosts[1] = new Ghost(COORD({GHOSTBOX_X + 1, GHOSTBOX_Y}),		FOREGROUND_YELLOW);
	ghosts[2] = new Ghost(COORD({GHOSTBOX_X - 1, GHOSTBOX_Y}),		FOREGROUND_LIGHT_SKYBLUE);
	ghosts[3] = new Ghost(COORD({GHOSTBOX_X, GHOSTBOX_Y - 1}),		FOREGROUND_RED);

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

		player.Update(map, input);

		for (int i = 0; i < GHOST_NUM; i++) {
			ghosts[i]->SetTarget(map, &player);
			ghosts[i]->Update(map, E_NULL);
		}

		Check();
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
			if (map->GetMap(drawPos) == E_MAP_FOOD || map->GetMap(drawPos) == E_MAP_PILL)
				screen->ScreenPrint(drawPos, map->GetMapIcon(drawPos), FOREGROUND_LIGHT_YELLOW);
			else
				screen->ScreenPrint(drawPos, map->GetMapIcon(drawPos), FOREGROUND_BLUE);
		}
	}

	screen->ScreenPrint(player.pos, (char*)SCREEN_ICONS[player.GetType()], player.COLOR);
	for (int i = 0; i < GHOST_NUM; i++) {
		screen->ScreenPrint(ghosts[i]->pos, (char*)SCREEN_ICONS[ghosts[i]->GetType()], ghosts[i]->COLOR);
	}

	char scoreToCh[256];
	sprintf_s(scoreToCh, "%d", score);
	screen->ScreenPrint(MakeCoord(0, drawPos.Y + 1), scoreToCh, FOREGROUND_WHITE);
}

void GameLogic::Check()
{
	if (map->GetMap(player.pos) == eMap::E_MAP_FOOD) {
		map->SetMap(player.pos, eMap::E_MAP_EMPTY);
		score++;
	}
	else if (map->GetMap(player.pos) == eMap::E_MAP_PILL) {
		map->SetMap(player.pos, eMap::E_MAP_EMPTY);
		for (int i = 0; i < GHOST_NUM; i++) {
			ghosts[i]->SetIsPacManEatsPill(true);
		}
	}

	for (int i = 0; i < GHOST_NUM; i++) {
		if (player.pos == ghosts[i]->pos) {
			ghosts[i]->SetIsCollisionPacMan(true);
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
}