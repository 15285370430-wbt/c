#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
int Result_Reverse(char* s1,char* s2) {
	char temp[256] = { 0 };
	strcpy(temp, s1);
	strcat(temp, s1);
	return strstr(temp, s2) != NULL;
}

int main() {
	char s1[] = "ABCD";
	char s2[] = "BCDA";	
	printf("%d", Result_Reverse(s1, s2));
	return 0;
	system("pause");
}