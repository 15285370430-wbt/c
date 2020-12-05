#include<stdio.h>
#include<string.h>

int My_strcmp(char* s1, char*s2) {
	while ((*s1 != '\0') && (*s2 != '\0')) {
		if (*s1 < *s2) {
			return -1;
		}
		else if (*s1 > *s2) {
			return 1;
		}
		else {
			*s1++;
			*s2++;
		}
	}
}

int main() {
	char a[] = "abd";
	char b[] = "abc";
	int c=My_strcmp(a, b);
	if (c == 1) {
		printf("1");
	}
	else if (c == -1) {
		printf("-1");
	}
	else {
		printf("0");
	}
	return 0;
}
