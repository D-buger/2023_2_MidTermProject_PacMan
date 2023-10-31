#pragma once

#include "Util.h"

class ScreenLogic
{
private:
	const int screenWidth, screenHeight;
	int screenIndex;
	HANDLE hScreen[2];
public:
	ScreenLogic(int _screenWidth, int _screenHeight);
	~ScreenLogic();

	void InitScreen();
	void ScreenFlipping();
	void ScreenClear();
	void ScreenRelease();
	void ScreenPrint(COORD _playerPos, char* _c, byte _color = FOREGROUND_WHITE);

};

