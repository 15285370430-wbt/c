#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 9
#define MAX_COL 9
#define DEFAULT_MINE_COUNT 10

int menu() {
	printf("======================\n");
	printf(" 1. 开始游戏\n");
	printf(" 0. 结束游戏\n");
	printf("======================\n");
	printf(" 请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void init(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL]) {
	// 1. 初始化 showMap, 全都设为 * 即可
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			showMap[row][col] = '*';
		}
	}
	// 2. 初始化 mineMap, 先全设为 '0', 然后随机生成 N 个 '1' 
	//    N 的值就是 DEFAULT_MINE_COUNT
	//    复制粘贴虽然爽, 但是一定要小心~~~ 
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			mineMap[row][col] = '0';
		}
	}
	int n = DEFAULT_MINE_COUNT;
	while (n > 0) {
		// 生成雷的随机位置. 
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] == '1') {
			// 如果当前位置已经有雷了, 就直接进入下次循环, 重新
			// 产生随机位置. 
			continue;
		}
		mineMap[row][col] = '1';
		n--;
	}
}


void printMap(char theMap[MAX_ROW][MAX_COL]) {
	/*for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", theMap[row][col]);
		}
		printf("\n");
	}*/
	// 先打印出第一行, 第一行就是包含所有的列号
	// 然后在打印下面的每一行的时候再打印行号
	printf("  |");
	for (int col = 0; col < MAX_COL; col++) {
		printf("%d ", col);
	}
	printf("\n");
	printf("--+------------------\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf(" %d|", row);
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", theMap[row][col]);
		}
		printf("\n");
	}
}

// 根据当前 row, col 的位置, 计算出当前位置周围有几个雷
// 并且更新显示到 showMap 中. 
void updateShowMap(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL], int row, int col) {
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r < 0 || r >= MAX_ROW
				|| c < 0 || c >= MAX_COL) {
				// r, c 下标越界, 就直接跳过
				continue;
			}
			if (mineMap[r][c] == '1') {
				count++;
			}
		}
	}
	showMap[row][col] = count + '0';
}

void game() {
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openedBlockCount = 0;
	while (1) {
		printMap(mineMap);
		printf("=================================\n");

		printMap(showMap);
		int row = 0;
		int col = 0;
		printf("请输入要翻开的坐标(row col): ");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("您输入的坐标有误!\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("当前位置已经翻开了!\n");
			continue;
		}
		if (mineMap[row][col] == '1') {
			printf("GameOver!\n");
			printMap(mineMap);
			break;
		} 
		updateShowMap(showMap, mineMap, row, col);
		openedBlockCount++;
		if (openedBlockCount == MAX_ROW * MAX_COL - DEFAULT_MINE_COUNT) {
			printf("游戏胜利!\n");
			printMap(mineMap);
			break;
		}
	}
}

int main() {
	srand((unsigned int)time(0));
	while (1) {
		int choice = menu();
		if (choice == 1) {
			game();
		}
		else if (choice == 0) {
			printf("goodbye!\n");
			break;
		}
		else {
			printf("您的输入有误!\n");
		}
	}
	system("pause");
	return 0;
}