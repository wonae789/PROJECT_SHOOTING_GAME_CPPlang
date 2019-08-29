#include <stdio.h>
#include <windows.h>

#include "lib.h"

int player_x;
int player_y;

int player_missile_flag;
int player_missile_x;
int player_missile_y;


/* ========================================================================== */
/* 플레이어 미사일 지우기 */
void PlayerMissileErase(void)
{
	gotoxy(player_missile_x, player_missile_y);
	printf("  ");
}

/* ========================================================================== */
/* 플레이어 미사일 표시 */
void PlayerMissileDraw(void)
{
	SetColor(GREEN);
	gotoxy(player_missile_x,player_missile_y);
	printf("┃");
}
/* ========================================================================== */
/* 플레이어 미사일을 처리한다. */
void PlayerMissileAct()
{
	if (player_missile_flag == 0)
		return;

	PlayerMissileErase();

	if (player_missile_y < 4)
	{
		player_missile_flag = 0;
		return;
	}

	player_missile_y--;
	PlayerMissileDraw();
}

/* ========================================================================== */
/* 플레이어 지우기 */
void PlayerErase(void)
{
	gotoxy(player_x, player_y);
	printf("  ");
	gotoxy(player_x -1, player_y + 1);
	printf("    ");
}
/* 플레이어 표시 */
void PlayerDraw(void)
{
	SetColor(GREEN);
	gotoxy(player_x, player_y);
	printf("▲");
	gotoxy(player_x - 1, player_y + 1);
	printf("■■");
}
/* 플레이어의 움직임을 처리한다. */
void PlayerAct(void)
{
	if ((GetAsyncKeyState(VK_LEFT)<0) && (player_x >1))
	{
		PlayerErase();
		player_x--;
		PlayerDraw();
	}
	if ((GetAsyncKeyState(VK_RIGHT) < 0) && (player_x < 51))
	{
		PlayerErase();
		player_x++;
		PlayerDraw();
	}
	if ((GetAsyncKeyState(VK_SPACE) < 0) && (player_missile_flag == 0))
	{
		player_missile_flag = 1;
		player_missile_x = player_x;
		player_missile_y = player_y - 1;
		PlayerMissileDraw();
	}

}
/* 플레이어를 초기화 해준다. */
void PlayerInit(void)
{
	player_x = 1;
	player_y = 34;

	player_missile_flag = 0;
}

/* ========================================================================== */