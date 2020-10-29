#include<stdio.h>
int factor(int x) {
	if (x == 1) {
		return 1;
}
	else {
		return x * factor(x - 1);
	}
}
int main() {
	int n = 0;
	printf("ÇëÊäÈë½×³ËÊı£º");
	scanf_s("%d", &n);
	factor(n);  
	return 0;
}
//int main() {
	/*int sum = 1,n = 0;
	printf("ÇëÊäÈë½×³ËÊı£º");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		sum = sum * i;
		
	}
	printf("%d", sum);

	return 0;*/
	
//}
