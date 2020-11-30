#include<stdio.h>
#include<string.h>
#include<assert.h>

char*Strstr(const char*str, const char*sub)
{
	assert(str);
	assert(sub);
	const char*str_p = str;
	const char*start = str;
	const char*sub_p = sub;
	while (*start != '\0')
	{
		str_p = start;
		sub_p = sub;
		while (*str_p != '\0'&&*sub_p != '\0')
		{
			if (*str_p == *sub_p)
			{
				str_p++;
				sub_p++;
			}
			else
			{
				break;
			}
		}
		if (*sub_p == '\0')
		{
			return start;
		}
		start++;
	}
	return NULL;
}

int main() {

	char str[] = "abbbbcdef";
	char *p;
	p = strstr(str, "bbc");
	printf("%s", p);
	system("pause");
	return 0;
}