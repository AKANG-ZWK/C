#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 4
#define COL 4

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