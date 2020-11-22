#include<stdio.h>

int Drink(int m, int p) {

	int sum = 0;
	int ret = 0;
	int tem = 0;
	sum = m / p;
	ret = sum;
	while (ret /2!= 0) {
		tem = ret;
		ret = ret / 2;
		sum += ret;
		ret = tem % 2 + ret;

	}
	return sum;
}
	
int main() {
	printf("%d", Drink(20,1));
	return 0;
}