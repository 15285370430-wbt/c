#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Dif_bits(int n, int m) {
	int count = 0;
	int v = n ^ m;
	while (v != 0) {
		if ((v & 1) == 1) {
			count++;	
		}
		v = v >> 1;
	}
	return count;
}
int main() {
	int num1 = 0;
	int num2 = 0;
	printf("请输入比较的两个数：\n");
	scanf("%d %d", &num1, &num2);
	
	printf("count=%d\n", Dif_bits(num1, num2));
	system("pause");
	return 0;
	}