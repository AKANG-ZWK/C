#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-------------------------------------\n");
	// 列号的打印

	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		// 行号的打印
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	// 1.随机找坐标布置雷
	int count = EASY_COUNT;
	while (count)
	{
		// 成功布置一个雷,count--
		// 1. 生成随机坐标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		// 2. 布置雷
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

// 扫雷游戏是怎么结束的？
// 1. 炸死了
// 2. 排查出来所有雷

int AutoFind(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col)
{
	int win = 0;
	if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y]=='*')
	{
		int count = GetMineCount(mine, x, y);

		if (0 == count)
		{
			win++;
			show[x][y] = '0';
			win += AutoFind(mine, show, x, y - 1, ROW, COL);
			win += AutoFind(mine, show, x, y + 1, ROW, COL);
			win += AutoFind(mine, show, x - 1, y, ROW, COL);
			win += AutoFind(mine, show, x + 1, y, ROW, COL);
			win += AutoFind(mine, show, x - 1, y - 1, ROW, COL);
			win += AutoFind(mine, show, x + 1, y - 1, ROW, COL);
			win += AutoFind(mine, show, x - 1, y + 1, ROW, COL);
			win += AutoFind(mine, show, x + 1, y + 1, ROW, COL);
		}

	}
	return win;
}

void MarkShow(char show[ROWS][COLS], int x, int y, int row, int col)
{
	if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '*')
	{
		show[x][y] = '#';
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (win < ROW * COL - EASY_COUNT)
	{
		int input = 0;
		printf("请选择你的操作：1.排雷 2.标记雷\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
		{
			printf("请输入要排查的坐标:>");
			scanf("%d%d", &x, &y);

			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				// 判断x,y坐标处是否是雷
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					DisplayBoard(mine, row, col);
					exit(0);
					break;
				}
				else
				{
					// 如果x,y坐标不是雷，就统计周围有几个雷
					int count = GetMineCount(mine, x, y);
					if (0 == count)
					{
						win = AutoFind(mine, show, x, y, ROW, COL);

						DisplayBoard(show, ROW, COL);
					}
					else
					{
						show[x][y] = count + '0';
						DisplayBoard(show, ROW, COL);
						win++;
					}

				}
			}
			else
			{
				printf("坐标非法\n");
			}

			if (win == ROW * COL - EASY_COUNT)
			{
				printf("恭喜你，排雷成功\n");
				DisplayBoard(mine, ROW, COL);
			}
		}
		break;
		case 2:
		{
			int p = 0;
			int q = 0;
			printf("请输入要标记的坐标:>");
			scanf("%d%d", &p, &q);
			MarkShow(show, p, q, ROW, COL);
			DisplayBoard(show, ROW, COL);
		}
		break;

		default:
			printf("输入有误，请重新选择:>");
		}
	}
}