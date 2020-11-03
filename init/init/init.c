#include<stdio.h> 

int   init(int a[5]) {
	for (int i = 0; i < 5; i++) {
		a[i] = 0 ;
	}
	return 0;
}
int  print(int a[5]) {
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
int reverse(int a[5]) {
	for (int i = 0; i < 5-i; i++) {
		int temp;
		temp = a[i];
		a[i] = a[4- i];

		a[4 - i] = temp;
	}
	return 0;
}
int main() {
int a[5] = {1,2,3,4,5};
	print(a);
	
	printf("\n");
	/*init(a);
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}*/
	reverse(a);
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	return 0;

}
