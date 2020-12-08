#include<stdio.h>
#include<string.h>
#include<assert.h>

int Strlen(char *s1) {
	assert(s1);
	int count = 0;
	while (*s1) {
		++count;
		++s1;
	}
	return count;
	 
}

int main() {
	char *str= "hehe";
	int r = Strlen(str);
	printf("%d", r);
	return 0;

}