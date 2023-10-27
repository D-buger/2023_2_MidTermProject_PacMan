#pragma once

#include <Windows.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

#define ARROW_KEY 224

#define SCREEN_WIDTH 28
#define SCREEN_HEIGHT 31

#define SCREEN_DELAY 100

#define PLAYER_INIT_X 0
#define PLAYER_INIT_Y 0

#define PLAYER_ANIM_END 3

enum ePlayerInput : int {
	E_NULL = 0,
	E_UP = 72,
	E_LEFT = 75,
	E_RIGHT = 77,
	E_DOWN = 80
};

enum eScreenIcon : int {
	E_NONE			= 0,

	E_PLAYER_RIGHT	= 1,									//�� < ��	// 1
	E_PLAYER_LEFT	= E_PLAYER_RIGHT + PLAYER_ANIM_END,		//�� > ��	// 4
	E_PLAYER_UP		= E_PLAYER_LEFT + PLAYER_ANIM_END,		//������	// 7
	E_PLAYER_DOWN	= E_PLAYER_UP + PLAYER_ANIM_END,		//���ˤ�	// 10

	E_GHOST_HUNTER	,		//��
	E_GHOST_HUNTED	,		//��
	E_GHOST_EATEN	,		//��
	E_FOOD			,		//��
	E_COOKIE		,		//��
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