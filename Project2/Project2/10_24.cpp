#include<stdio.h>
int isPrime(int num);
int main() {
	/*int num;
	printf("����һ����:");
	scanf_s("%d", &num);
	if (isPrime(num)) {
		printf("%d�ǲ�����\n", num);
	}
	else {
		printf("%d������\n", num);
	}
	return 0;*/
	int i;
	for (i = 100; i <= 200; i++) {
		if (isPrime(i)) {
		printf("%d�ǲ�����\n",i);
		}
		else {
			printf("%d������\n",i);
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