#include <stdio.h>
#include <windows.h>

#include "lib.h"
#include "player.h"
#include "enemy.h"
#include "cosmic.h"


/* 오른쪽 줄 표시 */
void RightLineDraw(void)
{
	int loop;

	SetColor(WHITE);
	for (loop = 0; loop < 39; ++loop) {
		gotoxy(54, loop);
		printf("┃");
	}
}

/* ========================================================================== */

/* 바리케이드 표시 */
void BarricadeDraw(void)
{
	SetColor(GREEN);
	gotoxy(0, 29);
	printf("     ▨▦▦▧    ▨▦▦▧    ▨▦▦▧    ▨▦▦▧    \n");
	printf("     ▦▦▦▦    ▦▦▦▦    ▦▦▦▦    ▦▦▦▦    \n");
	printf("     ▦    ▦    ▦    ▦    ▦    ▦    ▦    ▦    \n");
}

/* ========================================================================== */

/* 화면 위와 아래에 상태줄 표시 */
void StatusDraw(void)
{
	SetColor(WHITE);
	gotoxy(0, 0);
	printf("  ＳＣＯＲＥ＜１＞ ＨＩ―ＳＣＯＲＥ ＳＣＯＲＥ＜２＞  \n");
	gotoxy(0, 2);
	printf("      ００００       ００００           ００００      \n");

	SetColor(GREEN);
	gotoxy(0, 37);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("３▲▲                           ＣＲＥＤＩＴ  ００   \n");
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
		/* Esc를 누르면 종료합니다. */
		if (GetAsyncKeyState(VK_ESCAPE) < 0)	break;
		
		PlayerMissileAct();
		PlayerAct();
		CosmicAct();

		//약 1/60초씩 기다린다.
		Sleep(17);
	}

	CursorView(SHOW);

	return 0;
}

/* ========================================================================== */