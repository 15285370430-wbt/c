#include<stdio.h>
int power(int n,int k) {
	if (k == 1) {
		return n;
	}
	else if (k == 0) {
		return 1;
	}
	else {
		return n *power(n,k-1);
	}

}
int main() {
	int n = 0, k = 0,result=0;
	printf("请输入底数:\n");
	scanf_s("%d",&n);
	printf("指数：\n");
	scanf_s("%d", &k);
	result=power(n, k);
	printf("\n%d", result);
	return 0;
}