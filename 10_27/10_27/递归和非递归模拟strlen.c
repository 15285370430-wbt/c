//非递归实现
#include<stdio.h>
int strLen(char str[]) {
		int count = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			count++;
		}
		return count;
}
int main() {
	int ret = 0;
	char arry[] = "abcdef";
	ret=strLen(arry);
	printf("%d", ret);
	return 0;
}

//递归实现
//#include<stdio.h>
//int strLen(char arry[]) {
//	if (arry[0] == '\0') {
//		return 0;
//	}
//	return 1 + strLen(arry + 1);
//}
//int main() {
//	int ret = 0;
//	char arry[] = "abcdef";
//	ret = strLen(arry);
//	printf("%d" ,ret);
//	return 0;
//}