#include <stdio.h>
#include <Windows.h>
#include "Library.h"

int players_x;
int players_y;

int missile_flag;
int missile_x;
int missile_y;




void MissileDraw()
{
	SetColor(GREEN);
	gotoxy(missile_x, missile_y);
	printf("жн");
}

void MissileErase()
{
	gotoxy(missile_x, missile_y);
	printf(" ");
}

void MissileAct()
{
	if (missile_flag == 0)
		return;

	MissileErase();
	if (missile_y < 4)
	{
		missile_flag = 0;
		return;
	}

	missile_y--;
	MissileDraw();
}

void PlayErase()
{
	gotoxy(players_x, players_y);
	printf("");
	gotoxy(players_x, players_y + 1);
	printf(" ");
}

void PlayDraw()
{
	gotoxy(players_x, players_y);
	SetColor(GREEN);
	printf("бу");
	gotoxy(players_x - 1, players_y + 1);
	printf("бсбс");
}


void PlayAct()
{
	if ((GetAsyncKeyState(VK_LEFT)<0) && (players_x >1))
	{
		PlayErase();
		players_x--;
		PlayDraw();
	}

	if ((GetAsyncKeyState(VK_RIGHT) < 0) && (players_x < 46))
	{
		PlayErase();
		players_x++;
		PlayDraw();
	}

	if ((GetAsyncKeyState(VK_SPACE) < 0) && (missile_flag == 0))
	{
		missile_flag = 1;
		missile_x = players_x;
		missile_y = players_y - 1;
		MissileDraw();
	}
	Sleep(17);
}

void PlayInit()
{
	players_x = 25;
	players_y = 30;

	missile_flag = 0;
}