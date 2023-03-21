#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

void initBord(char bord[ROW][COL], int row, int col);
void DisPaly(char bord[ROW][COL], int row, int col);
void PalyMove(char bord[ROW][COL], int row, int col);
void ComputerMove(char bord[ROW][COL], int row, int col);
char isWin(char bord[ROW][COL], int row, int col);