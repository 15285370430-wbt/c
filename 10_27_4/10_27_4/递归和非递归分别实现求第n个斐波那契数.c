//递归实现
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
	printf("请输入n:");
	scanf_s("%d", &n);
	printf("%d", fib(n));
}
//非递归实现
int fib(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	// 接下来就直接使用循环来计算
	// 这俩变量分别表示第 i - 1 项和第 i - 2 项
	int last1 = 1;
	int last2 = 1;
	// 此处 cur 表示当前这个第 i 项
	int cur = 0;
	for (int i = 3; i <= n; i++) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}