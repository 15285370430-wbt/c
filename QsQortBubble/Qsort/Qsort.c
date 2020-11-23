#include<stdio.h>
#include<stdlib.h>

// Cmp 指向一个函数, 指向的函数的参数是两个 int, 返回值也是 int
// 这个指向的函数就表示比较规则. 
// 约定:
// a 应该在 b 之前, 就让函数返回 -1
// a 应该在 b 之后, 就让函数返回 1
// a 和 b 一样大, 就返回 0
typedef int(*Cmp)(int a, int b);

void bubbleSort(int arr[], int size, Cmp cmp) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			// cur - 1 的位置在前
			// cur 的位置在后
			// 如果发现 cmp 的函数返回值 为 1
			if (cmp(arr[cur - 1], arr[cur]) == 1) {
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

// 如果按照升序排序
// a 应该在 b 之前, 就让函数返回 -1
// a 应该在 b 之后, 就让函数返回 1
// a 和 b 一样大, 就返回 0
int less(int a, int b) {
	if (a == b) {
		return 0;
	}
	if (a < b) {
		return -1;
	}
	return 1;
}

int main() {

	int arr[] = { 9, 5, 2, 7 };
	bubbleSort(arr, 4, less);
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr[i]);
	}
}

