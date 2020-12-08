#include<stdio.h>
#include<string.h>
#include<assert.h>

void *Memmove(void *dest,const void *src,int n) {
	char *pdest = (char*)dest;
	const char *psrc = (char*)src;
	assert(dest);
	if(pdest <= psrc && pdest >= psrc + n) {//��������£��������򿽱�
		while (n--) {
		*pdest = *psrc;
		}
	}
	else {
		while (n--) {// �쳣������������ڴ渲��ʱ�Ӻ���ǰ����
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

