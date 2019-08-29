#include <stdio.h>
#include <Windows.h>
#include "lib.h"
#include "player.h"

/* ========================================================================== */

int cosmic_flag;	/* ���ּ��� ������� */
int cosmic_x;
int cosmic_y;
int cosmic_delay;
int cosmic_dx;

/* ========================================================================== */

/* ���ּ� ����� */
void CosmicErase(void)
{
	gotoxy(cosmic_x, cosmic_y);
	printf("      ");
	gotoxy(cosmic_x, cosmic_y + 1);
	printf("      ");
}

/* ========================================================================== */

/* ���ּ� ǥ�� */
void CosmicDraw(void)
{
	SetColor(RED);
	gotoxy(cosmic_x, cosmic_y);
	printf("���ᡬ");
	gotoxy(cosmic_x, cosmic_y + 1);
	printf("����");
}

/* ========================================================================== */
/* ���ּ��� �������� ó���Ѵ�. */
/* 0 : 5�ʸ� ��ٸ� ������ */
/* 1 : �÷��̾ ���ʿ� ������ �����ʿ��� ��Ÿ���� �������� �����̰� */
/*     �÷��̾ �����ʿ� ������ ���ʿ��� ��Ÿ���� ���������� �����δ�. */
/* 2 : ȭ�鿡 ���� ���������� �ٽ� ó������ ����. */
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
		if (player_x > 25) {	/* �÷��̾ �����ʿ� ������ */
			cosmic_x = 0;		/* ���ʿ��� ��Ÿ���� */
			cosmic_dx = 1;		/* ���������� �����̰� */
		}
		else {					/* �÷��̾ ���ʿ� ������ */
			cosmic_x = 48;		/* �����ʿ��� ��Ÿ���� */
			cosmic_dx = -1;		/* �������� �����δ�. */
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
			if ((cosmic_x == 0) || (cosmic_x == 48)) {	/* ȭ���� ���� ���������� */
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
/*���ּ��� �ʱ�ȭ ���ش�.*/
void CosmicInit(void)
{
	cosmic_flag = 0;
	cosmic_delay = 0;
}