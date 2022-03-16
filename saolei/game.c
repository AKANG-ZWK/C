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
	// �кŵĴ�ӡ

	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		// �кŵĴ�ӡ
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
	// 1.��������겼����
	int count = EASY_COUNT;
	while (count)
	{
		// �ɹ�����һ����,count--
		// 1. �����������
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		// 2. ������
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

// ɨ����Ϸ����ô�����ģ�
// 1. ը����
// 2. �Ų����������

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
		printf("��ѡ����Ĳ�����1.���� 2.�����\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
		{
			printf("������Ҫ�Ų������:>");
			scanf("%d%d", &x, &y);

			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				// �ж�x,y���괦�Ƿ�����
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					DisplayBoard(mine, row, col);
					exit(0);
					break;
				}
				else
				{
					// ���x,y���겻���ף���ͳ����Χ�м�����
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
				printf("����Ƿ�\n");
			}

			if (win == ROW * COL - EASY_COUNT)
			{
				printf("��ϲ�㣬���׳ɹ�\n");
				DisplayBoard(mine, ROW, COL);
			}
		}
		break;
		case 2:
		{
			int p = 0;
			int q = 0;
			printf("������Ҫ��ǵ�����:>");
			scanf("%d%d", &p, &q);
			MarkShow(show, p, q, ROW, COL);
			DisplayBoard(show, ROW, COL);
		}
		break;

		default:
			printf("��������������ѡ��:>");
		}
	}
}