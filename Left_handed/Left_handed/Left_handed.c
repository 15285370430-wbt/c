#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>

void Left_handed(int n) {
	char a[100] = {0};
	int i = 0;
	printf("�������ַ�����\n");
	scanf("%s", a);
	int len = strlen(a) - 1;
	while (n) {
		char temp = a[0];
		for (int i = 0; i < len; i++) {
			a[i] = a[i + 1];
			if(i == len - 1)
				a[i+1] = temp;
		}
		n--;
	}
	printf("��������ַ���Ϊ��%s", a);
}

int main() {
	int m;
	printf("������Ҫ�����Ĵ�����");
	scanf("%d", &m);
	Left_handed(m);
	return 0;
	system("psuse");
}
