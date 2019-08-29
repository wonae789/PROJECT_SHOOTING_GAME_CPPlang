#include <stdio.h>
#include <windows.h>

#include "lib.h"
#include "player.h"
#include "enemy.h"
#include "cosmic.h"


/* ������ �� ǥ�� */
void RightLineDraw(void)
{
	int loop;

	SetColor(WHITE);
	for (loop = 0; loop < 39; ++loop) {
		gotoxy(54, loop);
		printf("��");
	}
}

/* ========================================================================== */

/* �ٸ����̵� ǥ�� */
void BarricadeDraw(void)
{
	SetColor(GREEN);
	gotoxy(0, 29);
	printf("     �ɢˢˢ�    �ɢˢˢ�    �ɢˢˢ�    �ɢˢˢ�    \n");
	printf("     �ˢˢˢ�    �ˢˢˢ�    �ˢˢˢ�    �ˢˢˢ�    \n");
	printf("     ��    ��    ��    ��    ��    ��    ��    ��    \n");
}

/* ========================================================================== */

/* ȭ�� ���� �Ʒ��� ������ ǥ�� */
void StatusDraw(void)
{
	SetColor(WHITE);
	gotoxy(0, 0);
	printf("  �ӣãϣңţ����� �ȣɡ��ӣãϣң� �ӣãϣңţ�����  \n");
	gotoxy(0, 2);
	printf("      ��������       ��������           ��������      \n");

	SetColor(GREEN);
	gotoxy(0, 37);
	printf("������������������������������������������������������\n");
	printf("�����                           �ãңţģɣ�  ����   \n");
}

/* ========================================================================== */

void GameDraw(void)
{
	StatusDraw();
	EnemyDraw();
	EnemyMissileDraw();
	BarricadeDraw();
	PlayerDraw();
	RightLineDraw();
}

/* ========================================================================== */

void MainInit(void)
{
	system("mode con: lines=40");
	system("cls");

	PlayerInit();
	//CosmicInit();
}

/* ========================================================================== */

int main(void)
{
	CursorView(HIDDEN);

	MainInit();
	GameDraw();

	for (;;) {
		/* Esc�� ������ �����մϴ�. */
		if (GetAsyncKeyState(VK_ESCAPE) < 0)	break;
		
		PlayerMissileAct();
		PlayerAct();
		CosmicAct();

		//�� 1/60�ʾ� ��ٸ���.
		Sleep(17);
	}

	CursorView(SHOW);

	return 0;
}

/* ========================================================================== */