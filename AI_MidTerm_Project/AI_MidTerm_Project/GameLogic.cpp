#include "GameLogic.h"
#include "ScreenLogic.h"

GameLogic::GameLogic()
{
	screen = new ScreenLogic(SCREEN_WIDTH, SCREEN_HEIGHT);
	Update();
}

GameLogic::~GameLogic()
{
	delete screen;
}

void GameLogic::Update()
{
	while (true) {
		screen->ScreenClear();
		Input();
		PlayerMove();
		Sleep(SCREEN_DELAY);
		screen->ScreenFlipping();
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
				input = (ePlayerInput)in;
				break;
			default:
				input = (ePlayerInput)E_NULL;
				break;
			}
		}
	}
	else
		input = (ePlayerInput)E_NULL;
}

//플레이어 애니메이션은 나중에 처리할 것
void GameLogic::PlayerMove()
{
	switch (input)
	{
	case E_UP:
		--playerPos.Y;
		playerState = (eScreenIcon)E_PLAYER_UP;
		break;
	case E_LEFT:
		--playerPos.X;
		playerState = (eScreenIcon)E_PLAYER_LEFT;
		break;
	case E_RIGHT:
		++playerPos.X;
		playerState = (eScreenIcon)E_PLAYER_RIGHT;
		break;
	case E_DOWN:
		++playerPos.Y;
		playerState = (eScreenIcon)E_PLAYER_DOWN;
		break;
	case E_NULL:
		playerState = playerState % PLAYER_ANIM_END == 0 ? playerState - (PLAYER_ANIM_END - 1) : playerState + 1;
		break;
	}
	screen->ScreenPrint(playerPos, (char*)SCREEN_ICONS[playerState]);
}