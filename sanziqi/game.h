#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 4
#define COL 4

// ��������
// ��ʼ�����̵�
void InitBoard(char board[ROW][COL], int row, int col);
// ��ӡ���̵�
void DisplayBoard(char board[ROW][COL], int row, int col);
// �������
void PlayerMove(char board[ROW][COL], int row, int col);
// ��������
void ComputerMove(char board[ROW][COL], int row, int col);

int CheckWin(char board[ROW][COL], int row, int col);