## 数组

### 二维数组

```c
// 二维数组
// 二维数组存储行可以省略但列不能省略

int main()
{
	int arr1[3][4] = {1,2,3,4,5};
	int arr2[3][4] = { {1,2},{3,4},5 };
	int* p = arr1;
    // 指针访问二维数组
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ",*(p+i*4+j));
		}
		printf("\n");
	}
	return 0;
}
```

```c
// sizeof(数组名)   数组名表示整个数组
// &数组名          数组名表示整个数组，取出的是整个数组的地址
```

### 多文件实现三子棋

```c
// game.h     头文件和函数声明

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

// 声明函数
// 初始化棋盘的
void InitBoard(char board[ROW][COL], int row, int col);
// 打印棋盘的
void DisplayBoard(char board[ROW][COL], int row, int col);
// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

int CheckWin(char board[ROW][COL], int row, int col);
```

```c
// game.c    函数实现

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
	int i = 0;

	// 判断行是否有三个相等
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	// 判断列是否有三个相等
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[i][0];
		}
	}

	// 判断对角线是否有三个相等
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	// 判断是否为平局

	// 判断棋盘是否满了 - 判断棋盘是否有空格

	if (IsFull(board, ROW, COL) == 1)
	{
		return 'Q';
	}

	// 不是平局，游戏继续
	return 'C';
}

/////////////////////////////////////////////////////////////////////////////////////////
// 可以判断多行的CheckWin
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
```

```c
// sanziqi.c    用于写游戏框架

#include "game.h"
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
```

