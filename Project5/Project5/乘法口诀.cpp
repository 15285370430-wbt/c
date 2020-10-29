#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
void line(int x)
{
	int z = 0;
	for (int y = 1; y <= x; y++)
	{
		z = x * y;
		printf("%d*%d=%-2d   ", x, y, z);
	}
	
}
void output(int m)
{
	for (int i = 1; i <= m; i++)
	{
		line(i);
		printf("\n");
	}
}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	output(n);
//	system("pause");
//	return 0;
//
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//int line(int m)
//{
//	static int x = 1;
//	if (x == m+1)
//		return 0;
//	else
//	{
//	int z = 0;
//	for (int y = 1; y <= x; y++)
//	{
//		z = x * y;
//		printf("%d*%d=%-2d   ", x, y, z);
//	}
//	printf("\n");
//	x++;
//	return(line(m));
//	}
//}
//void output(int m)
//{
//	for (int i = 1; i <= m; i++)
//	{
//		line(i);
//		printf("\n");
//	}
//}
int main()
{
	int n = 0;
	scanf("%d", &n);
	output(n);
	system("pause");
	return 0;

}
