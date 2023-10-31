#include "ScreenLogic.h"

ScreenLogic::ScreenLogic(int _screenWidth, int _screenHeight) : screenWidth(_screenWidth), screenHeight(_screenHeight), screenIndex(0) {
	InitScreen();
}

ScreenLogic::~ScreenLogic()
{
	ScreenRelease();
}

void ScreenLogic::InitScreen()
{
	SetConsoleTitle(TEXT("202213037_MidtermProject_PacMan"));
	system(" mode  con lines=35   cols=60 ");


	CONSOLE_CURSOR_INFO cci;

	hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	cci.dwSize = 1;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hScreen[0], &cci);
	SetConsoleCursorInfo(hScreen[1], &cci);
}

void ScreenLogic::ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(hScreen[screenIndex]);
	screenIndex = !screenIndex;
}

void ScreenLogic::ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(hScreen[screenIndex], ' ', screenWidth * 10 * screenHeight * 10, Coor, &dw);
}

void ScreenLogic::ScreenRelease()
{
	CloseHandle(hScreen[0]);
	CloseHandle(hScreen[1]);
}

void ScreenLogic::ScreenPrint(COORD _playerPos, char* _c, byte _color)
{
	DWORD dw;
	COORD cursorPos = { _playerPos.X * 2, _playerPos.Y }; 
	
	SetConsoleTextAttribute(hScreen[screenIndex], _color);
	
	SetConsoleCursorPosition(hScreen[screenIndex], cursorPos);
	WriteFile(hScreen[screenIndex], _c, strlen(_c), &dw, NULL);
}
