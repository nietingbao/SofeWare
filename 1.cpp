// 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
struct Snake
{
	int x;
	int y;
	struct Snake *previous;
	struct Snake *next;
}*head, *tail;
struct Snake b[400];
char a[20][20], play;
int m, n, N = 2, i, j, T, score;
int main()
{
	void control();
	void print();
	void seed();
	void map();
	void find();
	void judge_1();
	void follow();
	void food();
	void go_on();
	void add();
loop1:
	tail = NULL;
	head = &b[0];
	for (i = 0; i <= N; i++)
	{
		b[i].next = &b[i + 1];
		b[i + 1].previous = &b[i];
	}
	b[N].next = tail;
	b[0].x = 10;
	b[0].y = 11;
	b[1].x = 10;
	b[1].y = 10;
	b[2].x = 10;
	b[2].y = 9;
	for (i = 0; i <= N; i++)
		a[b[i].x][b[i].y] = 'O';
loop2: seed();
	while (1)
	{
		map();
		food();
		find();
		system("cls");
		print();
		Sleep(300);
		if (_kbhit())
		{
			control();
			follow();
		}
		else go_on();
		judge_1();
	}
	return 0;
}
void control()
{
	play = _getch();
	switch (play)
	{
	case 'w': head->x--; break;
	case 's': head->x++; break;
	case 'a': head->y--; break;
	case 'd': head->y++; break;
	}
}
void follow()
{
	struct Snake *_tail;
	_tail = tail;
	for (i = 0; i < N; i++)
	{
		_tail->x = _tail->previous->x;
		_tail->y = _tail->previous->x;
	}
}
void food()
{
	int i, j;
	srand(T);
	i = rand() % 18 + 1;
	j = rand() % 18 + 1;
	a[i][j] = '@';
}
void judge_1()
{
	void seed();
	void add();
	if (head->x == m&&head->y == n)
	{
		score++;
		seed();
		add();
	}
}
void find()
{
	for (i = 0; i <= 19; i++)
	for (j = 0; j <= 19; j++)
	if (a[i][j] == '*')
	{
		m = i;
		n = j;
	}
}
void seed()
{
	srand(time(0));
	T = rand();
}

void add()
{
	N++;
	tail = &b[N];
	tail->x = 2 * tail->previous->x - tail->previous->previous->x;
	tail->y = 2 * tail->previous->y - tail->previous->previous->y;
	a[b[N].x][b[N].y] = 'O';
}
void map()
{
	for (i = 0; i <= 19; i++)
	for (j = 0; j <= 19; j++)
	if (i == 0 || i == 19 || j == 0 || j == 19)
		a[i][j] = '#';
}
void go_on()
{}
void print()
{
	for (i = 0; i <= 19; i++)
	{
		for (j = 0; j <= 19; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
}
