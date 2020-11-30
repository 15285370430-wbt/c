#include<stdio.h>
#include<string.h>
#include<assert.h>

char* Strcat(char* dest, char* src) {
	char* start = dest;
	assert(dest != NULL && src != NULL);
	while (*dest != '\0') {
		*dest++;
	}
	while (*src != '\0') {
		*dest = *src;
		*dest++;
		*src++;
	}
	*dest = '\0';
	return start;
}

int main()
{
	char a[20] = "hellow";
	char b[10] = " word !";
	char* c;
	c = Strcat(a, b);
	printf("%s\n", a);
	system("pause");
	return 0;
}