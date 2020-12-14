#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t n)
{
	//参数第一种判断
	//if (dest == NULL || src == NULL || n > 0)
	//{
	//    fprintf(stderr, "error\n");
	//    return NULL;
	//}
	//参数第二种判断
	assert(dest != NULL);//断言判断该指针是否是空指针
	assert(src != NULL);//因为空指针不能解引用
	void* result = dest;//这个也可以不写
	//循环拷贝直到第n个值
	while (--n)
	{
		*(char*)dest = *(char*)src;//强制类型转换，n为字节个数
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return result;//返回result指向目标空间的起始地址
}

int main()
{
	//memcpy从源内存地址的起始位置开始拷贝若干个字节到目标内存地址
	char arr1[20] = "hello world";
	char arr2[20];
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	my_memcpy(arr2, arr1, sz);
	printf("%s", arr2);
	/*char arr1[11] = { 1,2,3,4,5,6,7,8,9,10};
	char arr2[11] = { 0 };
	char sz = sizeof(arr1) / sizeof(arr1[0]);
	my_memcpy(arr2, arr1, sz);
	for (int i = 0; i < sz-1; ++i)
	{
		printf("%d ", arr2[i]);
	}*/
	printf("\n");

	system("pause");
	return 0;
}
