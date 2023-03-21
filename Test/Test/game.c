#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void initBord(char bord[ROW][COL],int row,int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			bord[i][j] = ' ';
		}
	}
}
void DisPaly(char bord[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", bord[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void PalyMove(char bord[ROW][COL], int row, int col) {
	int x, y;
	printf("����Ϸ������ˡ�\n");
	while (1) {
		printf("��������Ҫ�µ�λ�á�\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL) {
			if (bord[x - 1][y - 1] == ' ') {
				bord[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("��λ���ѱ�ռ��,����������\n");
			}
		}
		else {
			printf("���벻���ϣ�����������\n");
		}
	}
}
void ComputerMove(char bord[ROW][COL], int row, int col) {
	int x = 0, y = 0;
	x = rand() % row;
	y = rand() % col;
	printf("�õ������ˡ�\n");
	while (1) {
		if (bord[x][y] == ' ') {
			bord[x][y] = '#';
			break;
		}
	}
}
int isFull(char bord[ROW][COL], int row, int col) {
	int i = 0, j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (bord[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
char isWin(char bord[ROW][COL], int row, int col) {
	int i = 0;
	//��
	for (i = 0; i < row; i++) {
		if (bord[i][0] == bord[i][1]&& bord[i][1]== bord[i][2] && bord[i][1] != ' ') {
			return bord[i][1];
		}
	}
	//��
	for (i = 0; i < col; i++) {
		if (bord[0][i] == bord[1][i]&& bord[1][i] == bord[2][i] && bord[1][i] != ' ') {
			return bord[1][i];
		}
	}
	//�����Խ���
	if (bord[1][1] == bord[2][2]&& bord[2][2] == bord[0][0] && bord[1][1] != ' ') {
		return bord[1][1];
	}
	if (bord[0][2] == bord[1][1]&& bord[1][1] == bord[2][0] && bord[1][1] != ' ') {
		return bord[1][1];
	}
	//�ж���û��
	
	if (1 == isFull(bord, row, col)) {
		return 'Q';
	}
	return 'C';
}