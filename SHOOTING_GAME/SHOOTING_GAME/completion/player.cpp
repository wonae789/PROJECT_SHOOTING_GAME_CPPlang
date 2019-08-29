#include <stdio.h>
#include <windows.h>

#include "lib.h"

int player_x;
int player_y;

int player_missile_flag;
int player_missile_x;
int player_missile_y;


/* ========================================================================== */
/* �÷��̾� �̻��� ����� */
void PlayerMissileErase(void)
{
	gotoxy(player_missile_x, player_missile_y);
	printf("  ");
}

/* ========================================================================== */
/* �÷��̾� �̻��� ǥ�� */
void PlayerMissileDraw(void)
{
	SetColor(GREEN);
	gotoxy(player_missile_x,player_missile_y);
	printf("��");
}
/* ========================================================================== */
/* �÷��̾� �̻����� ó���Ѵ�. */
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
/* �÷��̾� ����� */
void PlayerErase(void)
{
	gotoxy(player_x, player_y);
	printf("  ");
	gotoxy(player_x -1, player_y + 1);
	printf("    ");
}
/* �÷��̾� ǥ�� */
void PlayerDraw(void)
{
	SetColor(GREEN);
	gotoxy(player_x, player_y);
	printf("��");
	gotoxy(player_x - 1, player_y + 1);
	printf("���");
}
/* �÷��̾��� �������� ó���Ѵ�. */
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
/* �÷��̾ �ʱ�ȭ ���ش�. */
void PlayerInit(void)
{
	player_x = 1;
	player_y = 34;

	player_missile_flag = 0;
}

/* ========================================================================== */