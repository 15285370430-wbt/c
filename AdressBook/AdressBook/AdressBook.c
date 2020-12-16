#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

// �ȴ����ṹ��, ��ʾһ����ϵ��
typedef struct Person {
	char name[1024];
	char sex[1024];
	int age;
	char tel[1024];
	char address[1024];

} Person;

#define MAX_PERSON 1024

// ��ʾ����ͨѶ¼, ���������е���ϵ��
typedef struct AddressBook {
	Person persons[MAX_PERSON];
	// ���������������� 1024 ���ռ�. ���ǳ��������, 
	// ͨѶ¼Ӧ���ǿ��ŵ�. ÿ��������ϵ��, ����Ż���һ��Ԫ��
	// size �������Ƶ�ǰͨѶ¼���ж��ٸ���. 
	// [0, size) ������Ч����
	int size;
} AddressBook;

// ʵ�ֺ����Ĵ���
int menu() {
	printf("=====================\n");
	printf(" 1. ������ϵ��\n");
	printf(" 2. ������ϵ��\n");
	printf(" 3. ɾ����ϵ��\n");
	printf(" 4. �޸���ϵ��\n");
	printf(" 5. �鿴������ϵ��\n");
	printf(" 6. ���������ϵ��\n");
	printf(" 0. �˳�\n");
	printf("=====================\n");
	printf(" ����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��



void init(AddressBook* addressBook) {
	// �������ͨѶ¼���г�ʼ��. 
	// ֻҪ�� size ��� 0 ����. 
	addressBook->size = 0;

	// memset(addressBook, 0, sizeof(AddressBook));
}

void addPerson(AddressBook* addressBook) {
	// ������ϵ��
	printf("������ϵ��\n");
	// ��Ҫ���ж�һ���ǲ����Ѿ�ͨѶ¼����. 
	int currentSize = addressBook->size;
	if (currentSize >= MAX_PERSON) {
		printf("ͨѶ¼�Ѿ�����, ����ʧ��!\n");
		return;
	}

	// ���û������µ���ϵ�˵ĵ绰������
	// ������һ��ר�ŵı�����Ҫ�޸ĵ� Person �ṹ������������. 
	// �˴�����ֱ��ʹ�ýṹ����� Person p ������ʽ, 
	// ����ʹ�ýṹ��ָ��. 
	// ������ϣ���޸�ȫ�ֱ����е� Person �ṹ��. 
	// ��ʹ�ýṹ������Ļ�, �൱�ڴ�����һ���ֲ������Ľṹ��. 
	// ��ʱ���޸�ֻ����Ըþֲ�������Ч, ���ź�������, �ֲ������ͱ��ͷ���. 
	Person* p = &addressBook->persons[currentSize];
	printf("����������ϵ�˵�����: ");
	scanf("%s", p->name);
	printf("������������ϵ�˵��Ա�");
	scanf("%s", p->sex);
	printf("����������ϵ�˵����䣺");
	scanf("%d", &p->age);
	printf("����������ϵ�˵ĵ绰: ");
	scanf("%s", p->tel);
	printf("������������ϵ�˵ĵ�ַ��");
	scanf("%s", p->address);
	printf("������ϵ�˳ɹ�!\n");
	addressBook->size++;
}

void findPerson(AddressBook* addressBook) {
	// ������ϵ��
	// �����������ҵ绰����
	printf("��������������ϵ��\n");
	printf("������Ҫ���ҵ�����: ");
	char name[1024] = { 0 };
	scanf("%s", name);

	for (int i = 0; i < addressBook->size; i++) {
		Person* p = &addressBook->persons[i];
		if (strcmp(name, p->name) == 0) {
			printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->tel);
		}
	}
	printf("������ϵ�����!\n");
}

void delPerson(AddressBook* addressBook) {
	// ɾ����ϵ��
	// �û�������ϵ�˵ı��������ɾ��(�����±�). 
	printf("ɾ����ϵ��\n");
	printf("������Ҫɾ������ϵ�˵ı��: ");
	int id = 0;
	scanf("%d", &id); 
	if (id < 0 || id >= addressBook->size) {
		printf("������ı������!\n");
		return;
	}
	// ɾ���±�Ϊ id ��Ԫ��
	// ��� id ��Ӧ��Ԫ�ؾ������һ��, ֱ�� size--
	if (id == addressBook->size - 1) {
		addressBook->size--;
		printf("ɾ���ɹ�!\n");
		return;
	}
	// ��� id ��Ӧ��Ԫ�����м�Ԫ��, �����һ��Ԫ�ظ�bia����
	addressBook->persons[id]
		= addressBook->persons[addressBook->size - 1];
	// ��ɾ�����һ��Ԫ��
	addressBook->size--;
	printf("ɾ���ɹ�!\n");
}

void updatePerson(AddressBook* addressbook) {
	//printf("4\n");
	//���ڻ����ͬ��ͬ�յ��ˣ�������û���������Ҫ�޸ĵ��˵�����
	//�������������ȫ����ϵ�˴�ӡ������Ȼ�����û�ѡ��ǰ�����Ž����޸�
	int flag[MAX_PERSON] = { -1 };
	int j = 0;
	while (1) {
		system("cls");
		printf("������Ҫ�޸���ϵ�˵�������");
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
			printf("δ�ҵ�Ҫ�޸ĵ��ˣ�\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	while (1) {
		printf("������Ҫ�޸���ϵ�˵���ţ�");
		int num = 0;
		scanf("%d", &num);
		for (int i = 0; i < j; i++) {
			if (flag[i] == num) {
				//���û������޸���Ϣ
				printf("�޸ĺ�������");
				scanf("%s", &addressbook->persons[flag[i]].name);
				printf("�޸ĺ��Ա�");
				scanf("%s", &addressbook->persons[flag[i]].sex);
				printf("�޸ĺ����䣺");
				scanf("%d", &addressbook->persons[flag[i]].age);
				printf("�޸ĺ�绰��");
				scanf("%s", &addressbook->persons[flag[i]].tel);
				printf("�޸ĺ�סַ��");
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
				printf("�޸���ϵ�˳ɹ���\n");
				Sleep(1000);
				return;
			}
		}
		printf("������������\n");
	}
}

void printPerson(AddressBook* addressBook) {
	printf("��ӡ������ϵ��\n");
	for (int i = 0; i < addressBook->size; i++) {
		Person* p = &addressBook->persons[i];
		printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->tel);
	}
	printf("���� [%d] ����¼\n", addressBook->size);
}

void clearPerson(AddressBook* addressBook) {
	system("cls");
	printf("�����Ҫɾ��������ϵ�ˣ�\n1--����\t2--ȷ��\n");
	while (1) {
		printf("��ѡ��");
		int choose = 0;
		scanf("%d", &choose);
		if (choose == 1) {
			return;
		}
		else if (choose == 2) {
			addressBook->size = 0;
			printf("ɾ���ɹ���");
			Sleep(1000);
			return;
		}
		else {
			printf("��������\n");
		}
	}
}



typedef void(*Func)(AddressBook*);

AddressBook addressBook;

int main() {

	// ת�Ʊ�
	Func funcs[] = {
		NULL,
		addPerson,
		findPerson,
		delPerson,
		updatePerson,
		printPerson,
		clearPerson
	};

	// ��ʼ��ͨѶ¼
	init(&addressBook);

	// ������ѭ��
	while (1) {
		int choice = menu();
		if (choice < 0
			|| choice >= sizeof(funcs) / sizeof(funcs[0])) {
			printf("����������Ч!\n");
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