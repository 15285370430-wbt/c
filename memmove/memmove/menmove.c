#include<stdio.h>
#include<string.h>
#include<assert.h>

void *Memmove(void *dest,const void *src,int n) {
	char *pdest = (char*)dest;
	const char *psrc = (char*)src;
	assert(dest);
	if(pdest <= psrc && pdest >= psrc + n) {//正常情况下，正常正向拷贝
		while (n--) {
		*pdest = *psrc;
		}
	}
	else {
		while (n--) {// 异常情况，当出现内存覆盖时从后向前拷贝
			*(pdest + n) = *(psrc + n);
		}
	}
	return dest;
}

int main() {
	char arr0[] = "abcdef";
	char arr1[] = "abcdef";
	char arr2[] = "0";
	printf("%s\n", Memmove(arr0 + 2, arr1, 4));
	printf("%s", Memmove(arr1, arr0, 4));
	return 0;
}

