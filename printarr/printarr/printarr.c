#include<stdio.h>
#include<stdlib.h>
void print(int arr,int n) {
	int* p = arr;
	for (int i = 0; i < n; i++) {
	printf("%d ", *(p+i));
	}
	
}
int main() { 
	int n =8;
	printf("����Ԫ�ظ�����%d\n", n);
	int  arr[] = {1,2,3,4,5,6,7,8};
	print(arr,n);

	return 0;
}