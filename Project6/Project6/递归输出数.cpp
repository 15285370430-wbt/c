#include<stdio.h>
#include<math.h>
void output(int x)
{
	if (x < 10)
		printf("%d ", x);
	else
	{
		int y = 0;
		y = x % 10;
		output(x / 10);
		printf("%d ", y);
		
	}
	
}
int main()
{
	int a = 0;
	scanf_s("%d", &a);
	output(a);
	return 0;
}