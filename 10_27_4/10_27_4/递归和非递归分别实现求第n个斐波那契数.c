//�ݹ�ʵ��
#include<stdio.h>
int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}
int main() {
	int n=0;
	printf("������n:");
	scanf_s("%d", &n);
	printf("%d", fib(n));
}
//�ǵݹ�ʵ��
int fib(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	// ��������ֱ��ʹ��ѭ��������
	// ���������ֱ��ʾ�� i - 1 ��͵� i - 2 ��
	int last1 = 1;
	int last2 = 1;
	// �˴� cur ��ʾ��ǰ����� i ��
	int cur = 0;
	for (int i = 3; i <= n; i++) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}