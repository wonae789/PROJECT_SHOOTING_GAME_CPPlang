#include <stdio.h>
#include <Windows.h>
#include "Library.h"
#include "players.h"

int ufo_x;
int ufo_y;
int ufo_flag;
int ufo_delay;
int ufo_move;

void UfoErase()
{
	gotoxy(ufo_x, ufo_y);
	printf("    ");
	gotoxy(ufo_x + 1, ufo_y + 1);
	printf("  ");
}

void UfoDraw()
{
	SetColor(RED);
	gotoxy(ufo_x, ufo_y);
	printf("¡å¡å");
	gotoxy(ufo_x + 1, ufo_y+1);
	printf("¡å");
}



void UfoAct()
{
	switch (ufo_flag)
	{
	case 0:
		if (++ufo_delay > 2 * SEC)
		{
			ufo_delay = 0;
			++ufo_flag;
		}
		break;
	case 1:
		if (players_x < 23)
		{
			ufo_x = 0;
			ufo_move = 1;
		}
		else
		{
			ufo_x = 46;
			ufo_move = -1;
		}
		ufo_y = 3;
		UfoDraw();
		++ufo_flag;
		break;
	case 2:
		if (++ufo_delay >= 2)
		{
			ufo_delay = 0;
			UfoErase();
			ufo_x += ufo_move;
			UfoDraw();
			if ((ufo_x == 0) || ufo_x == 46)
			{
				++ufo_flag;
			}
		}
		break;
	case 3:
		UfoErase();
		ufo_flag = 0;
		break;

	}
}

void ufoInit()
{
	ufo_delay = 0;
	ufo_flag = 0;
}