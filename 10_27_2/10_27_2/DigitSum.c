#include<stdio.h>
int DigitSum(int n){
	int m, sum=0;
	if(n!=0){
		
		m=n%10;
		n = n / 10;
		sum=m+DigitSum(n);
			
	}
	return sum;
}
int main() {
	int a = 0;
	printf("请输入一个数：");
	scanf_s("%d", &a);
	printf("sum=%d", DigitSum(a));
	return 0;
}
