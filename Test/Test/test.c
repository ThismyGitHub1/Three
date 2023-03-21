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
		//玩家下棋
		PalyMove(bord, ROW, COL);
		DisPaly(bord, ROW, COL);
		//判断玩家是否赢了
		 ret=isWin(bord, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//电脑下棋
		ComputerMove(bord, ROW, COL);
		DisPaly(bord, ROW, COL);
		//判断电脑是否赢了
		ret=isWin(bord, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("玩家赢了。\n");
	}
	else if (ret == '#') {
		printf("电脑赢了。\n");
	}
	else {
		printf("平局。\n");
	}
}
void Test() {

	int input;	
	srand((unsigned int)time(NULL));
	do {
	
		meun();
		printf("请输入您的选择：\n");
		scanf("%d", &input);
		switch (input) {
		case 1: {
			game();
			break;
		}
		case 0: {
			printf("退出游戏\n");
			break;
		}
		default: {
			printf("输入错误，请重新输入\n");
			break;
		}
		}
	} while (input);
}
int main() {
	Test();
	return 0;
}