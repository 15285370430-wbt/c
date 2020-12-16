#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

// 先创建结构体, 表示一个联系人
typedef struct Person {
	char name[1024];
	char sex[1024];
	int age;
	char tel[1024];
	char address[1024];

} Person;

#define MAX_PERSON 1024

// 表示整个通讯录, 管理着所有的联系人
typedef struct AddressBook {
	Person persons[MAX_PERSON];
	// 创建出的数组里有 1024 个空间. 但是出事情况下, 
	// 通讯录应该是空着的. 每次新增联系人, 里面才会多出一个元素
	// size 用来控制当前通讯录中有多少个人. 
	// [0, size) 就是有效区间
	int size;
} AddressBook;

// 实现后续的代码
int menu() {
	printf("=====================\n");
	printf(" 1. 新增联系人\n");
	printf(" 2. 查找联系人\n");
	printf(" 3. 删除联系人\n");
	printf(" 4. 修改联系人\n");
	printf(" 5. 查看所有联系人\n");
	printf(" 6. 清空所有联系人\n");
	printf(" 0. 退出\n");
	printf("=====================\n");
	printf(" 请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人



void init(AddressBook* addressBook) {
	// 针对整个通讯录进行初始化. 
	// 只要把 size 设成 0 即可. 
	addressBook->size = 0;

	// memset(addressBook, 0, sizeof(AddressBook));
}

void addPerson(AddressBook* addressBook) {
	// 新增联系人
	printf("新增联系人\n");
	// 需要先判定一下是不是已经通讯录满了. 
	int currentSize = addressBook->size;
	if (currentSize >= MAX_PERSON) {
		printf("通讯录已经满了, 新增失败!\n");
		return;
	}

	// 让用户输入新的联系人的电话和姓名
	// 创建好一个专门的变量把要修改的 Person 结构体变量给保存好. 
	// 此处不能直接使用结构体变量 Person p 这种形式, 
	// 必须使用结构体指针. 
	// 我们是希望修改全局变量中的 Person 结构体. 
	// 而使用结构体变量的话, 相当于创建了一个局部变量的结构体. 
	// 此时的修改只是针对该局部变量生效, 随着函数结束, 局部变量就被释放了. 
	Person* p = &addressBook->persons[currentSize];
	printf("请输入新联系人的姓名: ");
	scanf("%s", p->name);
	printf("请输入新增联系人的性别：");
	scanf("%s", p->sex);
	printf("请输入新联系人的年龄：");
	scanf("%d", &p->age);
	printf("请输入新联系人的电话: ");
	scanf("%s", p->tel);
	printf("请输入新增联系人的地址：");
	scanf("%s", p->address);
	printf("新增联系人成功!\n");
	addressBook->size++;
}

void findPerson(AddressBook* addressBook) {
	// 查找联系人
	// 按照姓名查找电话号码
	printf("按照姓名查找联系人\n");
	printf("请输入要查找的姓名: ");
	char name[1024] = { 0 };
	scanf("%s", name);

	for (int i = 0; i < addressBook->size; i++) {
		Person* p = &addressBook->persons[i];
		if (strcmp(name, p->name) == 0) {
			printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->tel);
		}
	}
	printf("查找联系人完成!\n");
}

void delPerson(AddressBook* addressBook) {
	// 删除联系人
	// 用户输入联系人的编号来进行删除(数组下标). 
	printf("删除联系人\n");
	printf("请输入要删除的联系人的编号: ");
	int id = 0;
	scanf("%d", &id); 
	if (id < 0 || id >= addressBook->size) {
		printf("您输入的编号有误!\n");
		return;
	}
	// 删除下标为 id 的元素
	// 如果 id 对应的元素就是最后一个, 直接 size--
	if (id == addressBook->size - 1) {
		addressBook->size--;
		printf("删除成功!\n");
		return;
	}
	// 如果 id 对应的元素是中间元素, 把最后一个元素给bia过来
	addressBook->persons[id]
		= addressBook->persons[addressBook->size - 1];
	// 再删除最后一个元素
	addressBook->size--;
	printf("删除成功!\n");
}

void updatePerson(AddressBook* addressbook) {
	//printf("4\n");
	//由于会出现同名同姓的人，因此让用户先输入想要修改的人的姓名
	//将叫这个姓名的全部联系人打印出来，然后让用户选择前面的序号进行修改
	int flag[MAX_PERSON] = { -1 };
	int j = 0;
	while (1) {
		system("cls");
		printf("请输入要修改联系人的姓名：");
		char name[1024] = { 0 };
		scanf("%s", name);
		for (int i = 0; i < addressbook->size; i++) {
			if (strcmp(addressbook->persons[i].name, name) == 0) {
				printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t%s\n", i,
					addressbook->persons[i].name,
					addressbook->persons[i].sex,
					addressbook->persons[i].age,
					addressbook->persons[i].tel,
					addressbook->persons[i].address);
				flag[j] = i;
				j++;
			}
		}
		if (flag[0] == -1) {
			printf("未找到要修改的人！\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	while (1) {
		printf("请输入要修改联系人的序号：");
		int num = 0;
		scanf("%d", &num);
		for (int i = 0; i < j; i++) {
			if (flag[i] == num) {
				//让用户输入修改信息
				printf("修改后姓名：");
				scanf("%s", &addressbook->persons[flag[i]].name);
				printf("修改后性别：");
				scanf("%s", &addressbook->persons[flag[i]].sex);
				printf("修改后年龄：");
				scanf("%d", &addressbook->persons[flag[i]].age);
				printf("修改后电话：");
				scanf("%s", &addressbook->persons[flag[i]].tel);
				printf("修改后住址：");
				scanf("%s", &addressbook->persons[flag[i]].address);
				int k = i;
				for (int i = flag[k]; i > 0 && i < addressbook->size - 1; ) {
					if (strcmp(addressbook->persons[i - 1].name, addressbook->persons[i].name) > 0) {
						Person p;
						p = addressbook->persons[i];
						addressbook->persons[i] = addressbook->persons[i - 1];
						addressbook->persons[i - 1] = p;
						i--;
					}
					else if (strcmp(addressbook->persons[i].name, addressbook->persons[i + 1].name) > 0) {
						Person p;
						p = addressbook->persons[i];
						addressbook->persons[i] = addressbook->persons[i + 1];
						addressbook->persons[i + 1] = p;
						i++;
					}
					else {
						break;
					}
				}
				printf("修改联系人成功！\n");
				Sleep(1000);
				return;
			}
		}
		printf("输入的序号有误！\n");
	}
}

void printPerson(AddressBook* addressBook) {
	printf("打印所有联系人\n");
	for (int i = 0; i < addressBook->size; i++) {
		Person* p = &addressBook->persons[i];
		printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->tel);
	}
	printf("共计 [%d] 条记录\n", addressBook->size);
}

void clearPerson(AddressBook* addressBook) {
	system("cls");
	printf("您真的要删除所有联系人？\n1--返回\t2--确定\n");
	while (1) {
		printf("请选择：");
		int choose = 0;
		scanf("%d", &choose);
		if (choose == 1) {
			return;
		}
		else if (choose == 2) {
			addressBook->size = 0;
			printf("删除成功！");
			Sleep(1000);
			return;
		}
		else {
			printf("输入有误！\n");
		}
	}
}



typedef void(*Func)(AddressBook*);

AddressBook addressBook;

int main() {

	// 转移表
	Func funcs[] = {
		NULL,
		addPerson,
		findPerson,
		delPerson,
		updatePerson,
		printPerson,
		clearPerson
	};

	// 初始化通讯录
	init(&addressBook);

	// 进入主循环
	while (1) {
		int choice = menu();
		if (choice < 0
			|| choice >= sizeof(funcs) / sizeof(funcs[0])) {
			printf("您的输入无效!\n");
			continue;
		}
		if (choice == 0) {
			printf("goodbye!\n");
			break;
		}
		funcs[choice](&addressBook);
	}
	system("pause");
	return 0;
}