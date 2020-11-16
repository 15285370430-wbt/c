#include<stdio.h>


int main() {
	int a = 0;
	int s = 0;
	int c = 0;
	int t = 0;
	scanf_s("%d %d", &a,&c);
	for (int i = 1; i <= c; i++) {
		t = t * 10+a;
		s = t+s;
	}
	printf("%d",s);
	return 0;
}