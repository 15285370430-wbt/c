#include<stdio.h>
void  change(int *x, int *y) {
	int t=0;
	t = *x;
	*x =*y;
	 *y= t;
	
}
int main() {
	int a, b;
	printf("请输入两个整数：");
		scanf_s("%d %d", &a, &b);
	change(&a, &b);
	printf("%d %d", a, b);
	return 0;
}

