#pragma once
#ifndef _ALT_CONIO_H_
#define _ALT_CONIO_H_

#include "windows.h"
#include "conio.h"
#include "time.h"

#define WIN_32_LEAN_AND_MEAN

#define BLACK           0
#define DARK_BLUE       1
#define GREEN           2
#define TURQUOISE       3
#define DARK_RED        4
#define PURPLE          5
#define FOREST_GREEN    6
#define LIGHT_GRAY      7
#define GRAY            8
#define BLUE            9
#define LIGHT_GREEN    10
#define LIGHT_BLUE     11
#define RED            12
#define PINK           13
#define YELLOW         14
#define WHITE          15
#define STDALERT      140
#define STDHEADER     143
#define STDBACKGROUND 159

#define _NOCURSOR       0
#define _SOLIDCURSOR    1
#define _NORMALCURSOR   2

#define LEFT            0
#define CENTER          1
#define RIGHT           2

void gotoxy(int x, int y);
void setx(int x);
void sety(int y);
void setcolor(unsigned short color);
void delay(unsigned long milisec);
void setcursor(int ctype);
void clrscr(void);
int getx(void);
int gety(void);
int align(int align, char str[]);

void gotoxy(int x, int y)
{
	setx(x);
	sety(y);
}

void setx(int x)
{
	COORD pos;
	pos.X = x;
	pos.Y = gety();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void sety(int y)
{
	COORD pos;
	pos.X = getx();
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(unsigned short int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void delay(unsigned long int milisec)
{
	clock_t start, end, loop;

	start = clock();
	end = (start + milisec);

	do {
		loop = clock();
	} while (loop < end);
}

void setcursor(int ctype)
{
	CONSOLE_CURSOR_INFO type;
	switch (ctype)
	{
	case _NOCURSOR:
		type.bVisible = false;
		break;
	case _SOLIDCURSOR:
		type.dwSize = 100;
		type.bVisible = true;
		break;
	case _NORMALCURSOR:
		type.dwSize = 1;
		type.bVisible = true;
	default:
		type.dwSize = 1;
		type.bVisible = true;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &type);
}

void clrscr(void)
{
	CONSOLE_SCREEN_BUFFER_INFO window;
	setcolor(WHITE);
	for (int y = 0; y < window.dwSize.Y; y++)
	{
		for (int x = 0; x < window.dwSize.X; x++)
		{
			gotoxy(x, y); printf(" ");
		}
	}
}

int getx(void)
{
	CONSOLE_SCREEN_BUFFER_INFO window;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &window);
	return window.dwCursorPosition.X;
}

int gety(void)
{
	CONSOLE_SCREEN_BUFFER_INFO window;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &window);
	return window.dwCursorPosition.Y;
}

int align(int align, char str[])
{
	int x;
	switch (align)
	{
	case 0:
		x = (0);
		break;
	case 1:
		x = (40 - (strlen(str) / 2));
		break;
	case 2:
		x = (79 - (strlen(str)));
		break;
	default:
		printf("ERROR:\nalign(int align, char str[]) aborted.\nERROR CAUSE:\nnon-feasible parameter number in int align detected.");
		getche();
		exit(0);
		break;
	}
	if (strlen(str) > 79) {
		printf("ERROR:\nalign(int align, char str[]) aborted.\nERROR CAUSE:\nnon-feasible parameter number in int align detected.");
		exit(0);
	}
	else {
		gotoxy(x, gety()); printf("%s", str);
	}
}

#endif
