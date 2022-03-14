#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		// 打印数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		// 打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");


	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;	
			}
			else
			{
				printf("该坐标被占用，请重新输入！\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走:>\n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static	int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0; // 有空格
			}
		}
	}
	return 1; // 没空格
}

int CheckWin(char board[ROW][COL], int row, int col)
{

	// int i = 0;
	
	// 判断行是否有ROW个相等
	for (int i = 0; i < row; i++)
	{
		int flag = 1;
		for (int j = 1; j < col; j++)
		{
			if (board[i][0] != board[i][j])
			{
				flag = 0;
			}
		}
		if (board[i][0] != ' ' && flag != 0)
		{
			return board[i][0];
		}
		/*if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}*/
	}

	// 判断列是否有三个相等
	for (int i = 0; i < col; i++)
	{
		int flag = 1;
		for (int j = 1; j < col; j++)
		{
			if (board[0][i] != board[j][i])
			{
				flag = 0;
			}
		}
		if (board[0][i] != ' ' && flag != 0)
		{
			return board[0][i];
		}
		/*if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[i][0];
		}*/
	}

	// 判断对角线是否有ROW个相等
	{
		int flag = 1;
		for (int i = 1; i < row; i++)
		{
			if (board[0][0] != board[i][i])
				flag = 0;
		}
		if (board[0][0] != ' ' && flag != 0)
			return board[0][0];
	}

	{
		int flag = 1;
		for (int i = 1; i < row; i++)
		{
			for (int j = col; j > 1; j--)
			{
				if (board[0][j] != board[i][j - 1])
					flag = 0;
			}
		}
		if (board[0][col] != ' ' && flag != 0)
			return board[0][0];
	}

	/*if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}*/

    /*if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}*/


	// 判断是否为平局
	// 判断棋盘是否满了 - 判断棋盘是否有空格
	if (IsFull(board, ROW, COL) == 1)
	{
		return 'Q';
	}

	// 不是平局，游戏继续
	return 'C';
}
