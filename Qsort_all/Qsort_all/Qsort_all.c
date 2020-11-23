#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
#define MAX_C 4


	//整型
	int cmp_int(int* a, int* b) {
		return *a - *b;//默认升序，若想降序，则返回*b-*a
	}
	//浮点型
	int cmp_double(double* a, double* b) {
		//在对浮点或者double型的一定要用三目运算符，因为要是使用像整型那样相减的话
		//如果是两个很接近的数则可能返回一个很小的小数（大于-1，小于1），而cmp的返回值是int型
		//因此会将这个小数返回0，系统认为是相等，失去了本来存在的大小关系
		return *a > * b ? 1 : -1;
	}
	//字符型
	int cmp_char(char* a, char* b) {
		return *a - *b;
	}

	//字符串型
	int cmp_str(char(*a), char(*b)) {
		return strcmp(a, b);
	}

	int main() {
		//整型
		int arr_int[MAX] = { 1,8,6,9,7,3,2,10,4,5 };
		qsort(arr_int, MAX, sizeof(arr_int[0]), cmp_int);
		for (int i = 0; i < MAX; i++) {
			printf("%d ", arr_int[i]);
		}printf("\n");

		//浮点型
		double arr_double[MAX] = { 1.0,8.0,6.0,9.0,7.0,3.0,2.0,10.0,4.0,5.0 };
		qsort(arr_double, MAX, sizeof(arr_double[0]), cmp_double);
		for (int i = 0; i < MAX; i++) {
			printf("%f ", arr_double[i]);
		}printf("\n");

		//字符型
		char arr_char[MAX] = { 'c','d','g','y','u','i','e','z','h','l' };
		qsort(arr_char, MAX, sizeof(arr_char[0]), cmp_char);
		for (int i = 0; i < MAX; i++) {
			printf("%c ", arr_char[i]);
		}printf("\n");

		//字符串型
		char arr_str[MAX_C][MAX_C] = { "asd","abf","bde","mny" };
		qsort(arr_str, MAX_C, sizeof(arr_str[0]), cmp_str);
		for (int i = 0; i < MAX_C; i++) {
			printf("%s ", arr_str[i]);
		}printf("\n");
		return 0;
	}