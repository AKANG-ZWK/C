#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define EASY_COUNT 10

#define ROW 9 
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

// AutoFind()和GetMineCount()不需要每个函数都知道，写在game.c里面了
// AutoFind是自动展开函数，GetMineCount是计算周围雷函数

// 初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

// 打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

// 布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

// 扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

// 标记雷
void MarkShow(char show[ROWS][COLS], int x, int y, int row, int col);