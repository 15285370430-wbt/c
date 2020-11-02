#include<stdio.h>
void bubblesort(int arry[5]) {
	for (int n = 4; n > 0; n--) {
		for (int m = 0; m < n ; m++) {
			//升序排列
			int temp = 0;
			if (arry[m] > arry[m + 1]) {
				temp = arry[m];
				arry[m] = arry[m + 1];
				arry[m + 1] = temp;
			}
		}
	}
}
int main() {
	int arry[5];
	printf("请输入数组：\n");
	for (int i = 0; i <5; i++) {
	scanf_s("%d", &arry[i]);
	}
	bubblesort(arry);
	for (int i = 0; i < 5; i++) {
		printf("%d ", arry[i]);
	}
	return 0;
}