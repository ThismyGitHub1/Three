#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void meun() {
	printf("******************************\n");
	printf("****1.paly     0.exit  *******\n");
	printf("******************************\n");
}
void game() {
	char bord[ROW][COL] = { 0 };
	initBord(bord,ROW,COL);
	DisPaly(bord, ROW, COL);
	char ret=0;
	while (1) {
		//�������
		PalyMove(bord, ROW, COL);
		DisPaly(bord, ROW, COL);
		//�ж�����Ƿ�Ӯ��
		 ret=isWin(bord, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//��������
		ComputerMove(bord, ROW, COL);
		DisPaly(bord, ROW, COL);
		//�жϵ����Ƿ�Ӯ��
		ret=isWin(bord, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("���Ӯ�ˡ�\n");
	}
	else if (ret == '#') {
		printf("����Ӯ�ˡ�\n");
	}
	else {
		printf("ƽ�֡�\n");
	}
}
void Test() {

	int input;	
	srand((unsigned int)time(NULL));
	do {
	
		meun();
		printf("����������ѡ��\n");
		scanf("%d", &input);
		switch (input) {
		case 1: {
			game();
			break;
		}
		case 0: {
			printf("�˳���Ϸ\n");
			break;
		}
		default: {
			printf("�����������������\n");
			break;
		}
		}
	} while (input);
}
int main() {
	Test();
	return 0;
}