#include<stdio.h>
 int leapyear(int x) {
	if ((x % 4== 0) &&(x % 100 != 0) || (x % 400 == 0)) {
	return 1;
	}
	else {
		return 0;
	}
}
int main() {
	int a=0;
	printf("请输入年份：");
	scanf_s("%d", &a);
	if (leapyear(a) == 1) {
	printf("%d是闰年", a);
	}
	else {
		printf("%d不是闰年", a);
	}
		
		return 0;
}