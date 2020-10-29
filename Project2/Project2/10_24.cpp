#include<stdio.h>
int isPrime(int num);
int main() {
	/*int num;
	printf("输入一个数:");
	scanf_s("%d", &num);
	if (isPrime(num)) {
		printf("%d是不素数\n", num);
	}
	else {
		printf("%d是素数\n", num);
	}
	return 0;*/
	int i;
	for (i = 100; i <= 200; i++) {
		if (isPrime(i)) {
		printf("%d是不素数\n",i);
		}
		else {
			printf("%d是素数\n",i);
		}
	}
}
int isPrime(int num) {
	int x = 2;
	for (; x < num; x++) {
		if (num%x == 0) {
			return 1;
		}
	}
	return 0;
}