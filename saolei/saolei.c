#include "game.h"

void menu()
{
	printf("********************************\n");
	printf("********    1.paly   ***********\n");
	printf("********    0.exit   ***********\n");
	printf("********************************\n");
}

void game()
{
	// 真正的扫雷过程
	// 创建两个数组
	
	// 存放布置好的雷
	char mine[ROWS][COLS] = {0}; // '0'
	// 存放排查出来的雷
	char show[ROWS][COLS] = {0}; // '*'

	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	
	DisplayBoard(show, ROW, COL);

	// 1.布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL); // 布置好的雷的信息

	// 2.扫雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL)); // 设置随机数起点, 时间戳time(NULL)返回值是time_t整型

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("输入错误！\n");
			break;
		}


	} while (input);

	return 0;
}
