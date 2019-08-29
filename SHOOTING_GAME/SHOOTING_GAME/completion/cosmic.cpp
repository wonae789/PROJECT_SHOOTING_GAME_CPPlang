#include <stdio.h>
#include <Windows.h>
#include "lib.h"
#include "player.h"

/* ========================================================================== */

int cosmic_flag;	/* 우주선의 진행순서 */
int cosmic_x;
int cosmic_y;
int cosmic_delay;
int cosmic_dx;

/* ========================================================================== */

/* 우주선 지우기 */
void CosmicErase(void)
{
	gotoxy(cosmic_x, cosmic_y);
	printf("      ");
	gotoxy(cosmic_x, cosmic_y + 1);
	printf("      ");
}

/* ========================================================================== */

/* 우주선 표시 */
void CosmicDraw(void)
{
	SetColor(RED);
	gotoxy(cosmic_x, cosmic_y);
	printf("／■＼");
	gotoxy(cosmic_x, cosmic_y + 1);
	printf("▼〓▼");
}

/* ========================================================================== */
/* 우주선의 움직임을 처리한다. */
/* 0 : 5초를 기다린 다음에 */
/* 1 : 플레이어가 왼쪽에 있으면 오른쪽에서 나타나서 왼쪽으로 움직이고 */
/*     플레이어가 오른쪽에 있으면 왼쪽에서 나타나서 오른쪽으로 움직인다. */
/* 2 : 화면에 끝에 도달했으면 다시 처음으로 간다. */
void CosmicAct(void)
{
	switch (cosmic_flag) {
	case	0:
		if (++cosmic_delay >= 5 * ONE_SEC) {
			cosmic_delay = 0;
			cosmic_flag++;
		}
		break;

	case	1:
		if (player_x > 25) {	/* 플레이어가 오른쪽에 있으면 */
			cosmic_x = 0;		/* 왼쪽에서 나타나서 */
			cosmic_dx = 1;		/* 오른쪽으로 움직이고 */
		}
		else {					/* 플레이어가 왼쪽에 있으면 */
			cosmic_x = 48;		/* 오른쪽에서 나타나서 */
			cosmic_dx = -1;		/* 왼쪽으로 움직인다. */
		}
		cosmic_y = 4;
		CosmicDraw();
		cosmic_flag++;
		break;

	case	2:
		if (++cosmic_delay >= 2) {
			cosmic_delay = 0;
			CosmicErase();
			cosmic_x += cosmic_dx;
			CosmicDraw();
			if ((cosmic_x == 0) || (cosmic_x == 48)) {	/* 화면의 끝에 도달했으면 */
				cosmic_flag++;
			}
		}
		break;

	case	3:
		CosmicErase();
		cosmic_flag = 0;
		break;
	}
}

/* ========================================================================== */
/* ========================================================================== */
/*우주선을 초기화 해준다.*/
void CosmicInit(void)
{
	cosmic_flag = 0;
	cosmic_delay = 0;
}