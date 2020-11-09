#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 3
#define MAX_COL 3
// 一局游戏的基本流程
// 1. 创建棋盘并初始化
// 2. 打印棋盘
// 3. 玩家落子(玩家输入行列坐标的方式来落子)
// 4. 判定胜负关系
// 5. 电脑落子(随机位置落子) 
// 6. 判定胜负关系
// 回到 2 继续执行
void init(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chessBoard[row][col] = ' ';
		}
	}
}
void printChessBoard(char chessBoard[MAX_ROW][MAX_COL]) {
	/*for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {

		}
	}*/
		printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("|%c|%c|%c|\n", chessBoard[row][0], 
			chessBoard[row][1], chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}

void playerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1) {
		printf("请玩家输入坐标（row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row<0 || row>MAX_ROW || col<0 || col>MAX_COL) {
			printf("您输入的坐标不在合法范围内[0 2]\n");
			continue;
		}
		if (chessBoard[row][col] != ' ') {
			printf("您的坐标位置已经有子了!\n");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;
	}
}

void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col]!=' ' ){
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
}
Isfull(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL;col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char iswin(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '
			&&chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] ==chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' '
		&&chessBoard[0][0]==chessBoard[1][1]
		&& chessBoard[0][0]==chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[2][2] != ' '
		&&chessBoard[2][2] == chessBoard[1][1]
		&& chessBoard[2][2] == chessBoard[0][0]) {
		return chessBoard[2][2];
	}
	if (Isfull(chessBoard)) {
		return 2;
	}
	return ' ';
}
void game() {
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	init(chessBoard);
	char winner = ' ';
	while (1) {
		printChessBoard(chessBoard);
		playerMove(chessBoard);
		winner = iswin(chessBoard);
		if (winner != ' ') {
			break;
		}
		computerMove(chessBoard);
		winner = iswin(chessBoard);
		if (winner != ' ') {
			break;
		}
	}
	printChessBoard(chessBoard);
	if (winner == 'x') {
		printf("恭喜您，您赢了！\n");
	}
	else if (winner == 'o') {
		printf("很遗憾，您连人工智障都下不过都！\n");

	}
	else {
		printf("很遗憾，您和人工五五开！");
	}
}
int menu() {
	printf("========================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("========================\n");
	printf("请输入你的选择：");
		int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int main() {
	srand((unsigned int)time(0));
	while (1) {
		int choice = menu();
		if (choice == 1) {
			game();
		}
		else if(choice==0){
			printf("goodbye!\n");
			break;
		}
	}
	system("pause");
	return 0;
}