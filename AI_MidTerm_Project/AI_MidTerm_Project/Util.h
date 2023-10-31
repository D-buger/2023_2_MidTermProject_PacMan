#pragma once

#include <Windows.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

#define ARROW_KEY 224

#define SCREEN_WIDTH 25
#define SCREEN_HEIGHT 29

#define SCREEN_DELAY 100

#define PLAYER_INIT_X 12
#define PLAYER_INIT_Y 21

#define PLAYER_ANIM_END 3

#define GHOST_NUM 4

enum eDirection : int {
	E_NULL = 0,
	E_UP = 72,
	E_LEFT = 75,
	E_RIGHT = 77,
	E_DOWN = 80
};

enum eMap {
	E_MAP_EMPTY = 0,
	E_MAP_WALL = 1,
	E_MAP_PLAYER = 2,
	E_MAP_FOOD = 3,
	E_MAP_PILL = 4,
	E_MAP_GHOST = 5,
	E_MAP_GHOST_BOX = 6,

	E_MAP_OUT_OF_BOUNDS = 99
};

enum eScreenIcon : int {
	E_NONE			= 0,

	E_PLAYER_RIGHT	= 1,									//�� < ��	// 1
	E_PLAYER_LEFT	= E_PLAYER_RIGHT + PLAYER_ANIM_END,		//�� > ��	// 4
	E_PLAYER_UP		= E_PLAYER_LEFT + PLAYER_ANIM_END,		//������	// 7
	E_PLAYER_DOWN	= E_PLAYER_UP + PLAYER_ANIM_END,		//���ˤ�	// 10

	E_GHOST_HUNTER	= E_PLAYER_DOWN + PLAYER_ANIM_END,		//��
	E_GHOST_HUNTED	,		//��
	E_GHOST_EATEN	,		//��
	E_FOOD			,		//��
	E_PILL			,		//��
	E_WALL			,		//��
	E_WALL_GHOSTBOX	,		//��
};

const static char* SCREEN_ICONS[]
{
	" ",
	"��", "<", "��",
	"��", ">", "��",
	"��", "��", "��",
	"��", "��", "��",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��"
};

COORD MakeCoord(int x, int y);

const COORD operator+(const COORD& ca, const COORD& cb);

const bool operator==(const COORD& ca, const COORD& cb);


#pragma region Colors

#define FOREGROUND_BLACK			NULL
#define FOREGROUND_PURPLE			(FOREGROUND_RED		| FOREGROUND_BLUE)
#define FOREGROUND_SKYBLUE			(FOREGROUND_GREEN	| FOREGROUND_BLUE)
#define FOREGROUND_YELLOW			(FOREGROUND_RED		| FOREGROUND_GREEN)
#define FOREGROUND_GRAY				(FOREGROUND_RED		| FOREGROUND_GREEN	| FOREGROUND_BLUE)
#define FOREGROUND_DARKGRAY			(FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_GREEN		(FOREGROUND_GREEN	| FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_RED		(FOREGROUND_RED		| FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_BLUE		(FOREGROUND_BLUE	| FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_SKYBLUE	(FOREGROUND_SKYBLUE	| FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_PURPLE		(FOREGROUND_PURPLE	| FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_YELLOW		(FOREGROUND_YELLOW	| FOREGROUND_INTENSITY)
#define FOREGROUND_WHITE			(FOREGROUND_GRAY	| FOREGROUND_DARKGRAY)

#pragma endregion

/*
	��Ʈ�� �Ѹǿ��� ������ �������ȴ�.
	�������� ��Ʈ�� In-Box���� �ٽ� �����Ѵ�.
	��Ʈ�� Hunter������ �� �Ѹ��� ��ó�� ������ �Ѹ��� �Ѿư���
	�Ѹ��� �Ѿư� ������ �ִܰ��ã�� �˰����� �����Ѵ� (A* �˰���)
	��Ʈ�� Hunter ������ �� �Ѹ��� ��ó�� ���� ��� ��ȸ�Ѵ�.
	�Ѹ��� �Ŀ� ��Ű�� ������ ��Ʈ�� Hunted ���·� �ٲ�� �Ѹ����� ���� ��������.
	Hunted ������ ��Ʈ�� ���� �ð��� ������ Hunter ���·� �ٲ��.
	��Ʈ�� Hunted ������ �� �Ѹǿ��� ������ ������ ��ҷ� �ǵ��ư���.
	��Ʈ�� FSM�� state pattern ���� �����Ѵ�.
*/