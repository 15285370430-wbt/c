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
	printf("��������ݣ�");
	scanf_s("%d", &a);
	if (leapyear(a) == 1) {
	printf("%d������", a);
	}
	else {
		printf("%d��������", a);
	}
		
		return 0;
}