#include <stdio.h>
#include <windows.h>

#include "lib.h"

void EnemyMissileDraw(void)
{
	SetColor(GREEN);
	gotoxy(0, 22);
	printf("                 ��                                   \n");
}

/* ========================================================================== */

/* �� ǥ�� */
void EnemyDraw(void)
{
	SetColor(WHITE);
	gotoxy(0, 10);
	printf("      ���� ���� ���� ���� ���� ���� ���� ���� ����    \n");
	printf("                                                      \n");
	printf("      �â� �â� �â� �â� �â� �â� �â� �â� �â�    \n");
	printf("                                                      \n");
	printf("      �â� �â� �â� �â� �â� �â� �â� �â� �â�    \n");
	printf("                                                      \n");
	printf("      ��� ��� ��� ��� ��� ��� ��� ��� ���    \n");
	printf("                                                      \n");
	printf("      ��� ��� ��� ��� ��� ��� ��� ��� ���    \n");
}

/* ========================================================================== */