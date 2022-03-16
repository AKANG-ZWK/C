#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define EASY_COUNT 10

#define ROW 9 
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

// AutoFind()��GetMineCount()����Ҫÿ��������֪����д��game.c������
// AutoFind���Զ�չ��������GetMineCount�Ǽ�����Χ�׺���

// ��ʼ��
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

// ��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

// ������
void SetMine(char board[ROWS][COLS], int row, int col);

// ɨ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

// �����
void MarkShow(char show[ROWS][COLS], int x, int y, int row, int col);