#include<stdio.h>
#include<string.h>
#include<assert.h>
char Strcpy(char* s1, char* s2) {
	assert((s1 != NULL) && (s2 != NULL));
	char* ret = s1;
	while ((*ret++ = *s2) != '\0') {
		return ret;
	}
}

int main() {
	char str1[] = "asdf";
	char str2[] = "zxc";
	printf("%s", Strcpy(str1, str2));
	return 0;
}