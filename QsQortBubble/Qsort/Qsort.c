#include<stdio.h>
#include<stdlib.h>

// Cmp ָ��һ������, ָ��ĺ����Ĳ��������� int, ����ֵҲ�� int
// ���ָ��ĺ����ͱ�ʾ�ȽϹ���. 
// Լ��:
// a Ӧ���� b ֮ǰ, ���ú������� -1
// a Ӧ���� b ֮��, ���ú������� 1
// a �� b һ����, �ͷ��� 0
typedef int(*Cmp)(int a, int b);

void bubbleSort(int arr[], int size, Cmp cmp) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			// cur - 1 ��λ����ǰ
			// cur ��λ���ں�
			// ������� cmp �ĺ�������ֵ Ϊ 1
			if (cmp(arr[cur - 1], arr[cur]) == 1) {
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

// ���������������
// a Ӧ���� b ֮ǰ, ���ú������� -1
// a Ӧ���� b ֮��, ���ú������� 1
// a �� b һ����, �ͷ��� 0
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

