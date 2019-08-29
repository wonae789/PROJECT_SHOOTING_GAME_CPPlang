#include <stdio.h>
#include <Windows.h>
#include "Library.h"
#include "players.h"
#include "ufo.h"

void BarricadeDraw(void)
{
	SetColor(GREEN);
	gotoxy(0, 24);
	printf("         �ɢˢˢ�    �ɢˢˢ�    �ɢˢˢ�  \n");
	printf("         �ˢˢˢ�    �ˢˢˢ�    �ˢˢˢ�  \n");
	printf("         ��    ��    ��    ��    ��    ��  \n"); 
}

void main()
{
	CursorView(HIDDEN);
	system("mode con: lines=35 cols=50");
	PlayInit();	
	ufoInit();
	BarricadeDraw();
	PlayDraw();
	
	for (;;)
	{
		if (GetAsyncKeyState(VK_ESCAPE) < 0)	
			break;
		MissileAct();
		PlayAct();
		UfoAct();
	
	}

}