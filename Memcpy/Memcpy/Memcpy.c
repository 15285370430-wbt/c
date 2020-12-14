#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t n)
{
	//������һ���ж�
	//if (dest == NULL || src == NULL || n > 0)
	//{
	//    fprintf(stderr, "error\n");
	//    return NULL;
	//}
	//�����ڶ����ж�
	assert(dest != NULL);//�����жϸ�ָ���Ƿ��ǿ�ָ��
	assert(src != NULL);//��Ϊ��ָ�벻�ܽ�����
	void* result = dest;//���Ҳ���Բ�д
	//ѭ������ֱ����n��ֵ
	while (--n)
	{
		*(char*)dest = *(char*)src;//ǿ������ת����nΪ�ֽڸ���
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return result;//����resultָ��Ŀ��ռ����ʼ��ַ
}

int main()
{
	//memcpy��Դ�ڴ��ַ����ʼλ�ÿ�ʼ�������ɸ��ֽڵ�Ŀ���ڴ��ַ
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
