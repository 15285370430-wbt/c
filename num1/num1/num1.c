#include<stdio.h>

int num1(int n) {
	int i = 8;
	int count = 0;
	
	
		for (int i = 7; i >= 0; i--) {
			if ((n >> i) & 1) {
				count++;
			}

		}
		printf("\n");
		return count;
}

int main() {
	int n = 15;
	printf("%d\n", n);
	printf("�����ƣ�");
	for (int i = 7; i >= 0; i--) {

		printf("%d", (n >> i) & 1);
	}
	printf("1�ĸ���Ϊ��%d",num1(n));
	return 0;
}