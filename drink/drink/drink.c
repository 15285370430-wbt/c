#include<stdio.h>

int Drink(int m) {
	int b = m;
	if (m < 2) {
		b = m;
	}
	if (m >= 2) {
		b += b / 2;
	}
	return b;
}
int main() {
	printf("%d", Drink(20));
	return 0;
}