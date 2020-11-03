#include<stdio.h>
int main() {
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 6,7,8,9,0 };
	printf("原数组为：\n");
	for (int i = 0; i < 5; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("%d", b[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		int temp = 0;
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	printf("交换后数组为：\n");
	for (int i = 0; i < 5; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("%d", b[i]);
	}
	return 0;
}