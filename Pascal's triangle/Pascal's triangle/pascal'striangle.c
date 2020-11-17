#include<stdio.h>
#define N 10
int main() {
	int a[N][N];
	for (int i = 0; i < N; i++) {
		a[i][i] = 1;
		a[i][0] = 1;
	}
	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= i - 1; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j ];
		}		
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <=i; j++) {
			printf("%-4d ", a[i][j]);
			
		}
		printf("\n");
		
	}
	printf("\n");
	return 0;
}