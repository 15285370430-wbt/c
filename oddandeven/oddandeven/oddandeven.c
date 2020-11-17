#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void select(int m) {
	int i = 31;
	printf("二进制：");
	while (i >= 0) {
		printf("%d", (m >> i) & 1);
		i--;
	}
	printf("\n奇数位：");
	for (int i = 0; i <= 30; i+=2) {
		printf("%d", (m >> i) & 1);
	}

	printf("\n偶数位：");
	for (int i = 1; i <= 31; i+=2) {
		printf("%d", (m >> i) & 1);
	}
}

int main() {
	int m = 199;
	select(m);
	return 0;
}

