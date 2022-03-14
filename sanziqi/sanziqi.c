﻿#include "game.h"
// 三子棋

void menu()
{
	printf("********************************\n");
	printf("********    1.paly   ***********\n");
	printf("********    0.exit   ***********\n");
	printf("********************************\n");
}

void game()
{
	// 设计三子棋游戏
	char ret = 0;
	// 存储数据的
	char board[ROW][COL] = { 0 };
	// 初始化棋盘 - 空格
	InitBoard(board,ROW,COL); 
	// 打印棋盘
	DisplayBoard(board, ROW, COL);

	// 玩游戏时
	// 1.玩家赢 - '*'
	// 2.电脑赢 - '#'
	// 3.平局了 - 'Q'
	// 4.继续   - 'C'

	while (1)
	{
		PlayerMove(board,ROW, COL);
		// 判断输赢
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);

		ComputerMove(board,ROW,COL);
		// 判断输赢
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局了\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game(); // 三子棋游戏
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default :
			printf("输入错误！\n");
			break;
		}
	} while (input);

	return 0;
}