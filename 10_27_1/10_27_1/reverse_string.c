#include "stdio.h"
#include "string.h"
char *reverse(char *str)
{
	if (!str)                     //�ж������ַ����Ƿ�Ϊ�մ�
	{
		return NULL;                  //��Ϊ�մ��򷵻�NULL
	}

	int len = strlen(str);
	if (len > 1)
	{
		char ctemp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = '\0';      // ���һ���ַ����´εݹ�ʱ���ٴ���   
		reverse(str + 1);         // �ݹ����   
		str[len - 1] = ctemp;
	}

	return str;
}
int main()
{
	char str[100];
	gets(str);
	reverse(str);
	puts(str);
	return 0;
}
//#include<stdio.h>
//#include<windows.h>
//void reverse_string(int n)
//{
//	int s;
//	if (n <= 1)
//	{
//		s = getchar();
//		putchar(s);
//	}
//	else
//	{
//		s = getchar();
//		reverse_string(n - 1);
//		putchar(s);
//	}
//}
//int main()
//{
//	get(5);
//	system("pause");
//	return 0;
//}