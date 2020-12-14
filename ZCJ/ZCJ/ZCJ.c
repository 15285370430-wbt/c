#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>


typedef struct Polyomial
{
	float coef;
	int expn;
	struct Polyomial *next;
}*Poly, Polyomial;               //PolyΪ���ָ������
void Insert(Poly p, Poly h) {
	if (p->coef == 0) free(p);       //ϵ��Ϊ0ʱ�ͷŽ��
	else {
		Poly q1, q2;
		q1 = h; q2 = h->next;
		while (q2&&p->expn < q2->expn) {   //���Ҳ���λ��
			q1 = q2;
			q2 = q2->next;
		}
		if (q2&&p->expn == q2->expn) {     //��ָ����ͬ��ϲ�
			q2->coef += p->coef;
			free(p);
			if (!q2->coef) {             //ϵ��Ϊ0�Ļ��ͷŽ��
				q1->next = q2->next;
				free(q2);
			}
		}
		else {                          //ָ��Ϊ��ʱ��������
			p->next = q2;
			q1->next = p;
		}
	}
}//Insert
Poly CreatePoly(Poly head, int m) {//����һ��ͷָ��Ϊhead������Ϊm��һԪ����ʽ
	int i;
	Poly p;
	p = head = (Poly)malloc(sizeof(struct Polyomial));
	head->next = NULL;
	for (i = 0; i < m; i++) {
		p = (Poly)malloc(sizeof(struct Polyomial));//�����½���Խ�������
		printf("�����%d���ϵ����ָ��:", i + 1);
		scanf("%f %d", &p->coef, &p->expn);
		Insert(p, head);   //����Insert����������
	}
	return head;
}//CreatePoly
void DestroyPoly(Poly p) {//���ٶ���ʽp
	Poly q1, q2;
	q1 = p->next;
	q2 = q1->next;
	while (q1->next) {
		free(q1);
		q1 = q2;//ָ�����
		q2 = q2->next;
	}
}
void PrintPoly(Poly P) {
	Poly q = P->next;
	int flag = 1;//����������
	if (!q) { //������ʽΪ�գ����0
		putchar('0');
		printf("\n");
		return;
	}
	while (q) {
		if (q->coef > 0 && flag != 1) putchar('+'); //ϵ������0�Ҳ��ǵ�һ��
		if (q->coef != 1 && q->coef != -1) {//ϵ����1��-1����ͨ���
			printf("%g", q->coef);
			if (q->expn == 1) putchar('X');
			else if (q->expn) printf("X^%d", q->expn);
		}
		else {
			if (q->coef == 1) {
				if (!q->expn) putchar('1');
				else if (q->expn == 1) putchar('X');
				else printf("X^%d", q->expn);
			}
			if (q->coef == -1) {
				if (!q->expn) printf("-1");
				else if (q->expn == 1) printf("-X");
				else printf("-X^%d", q->expn);
			}
		}
		q = q->next;
		flag++;
	}//while
	printf("\n");
}//PrintPoly
int compare(Poly a, Poly b) {
	if (a&&b) {
		if (!b || a->expn > b->expn) return 1;
		else if (!a || a->expn < b->expn) return -1;
		else return 0;
	}
	else if (!a&&b) return -1;//a����ʽ�ѿգ���b����ʽ�ǿ�
	else return 1;//b����ʽ�ѿգ���a����ʽ�ǿ�
}//compare
Poly AddPoly(Poly pa, Poly pb) {//��Ⲣ��������ʽa+b��������ͷָ��
	Poly qa = pa->next;
	Poly qb = pb->next;
	Poly headc, hc, qc;
	hc = (Poly)malloc(sizeof(struct Polyomial));//����ͷ���
	hc->next = NULL;
	headc = hc;
	while (qa || qb) {
		qc = (Poly)malloc(sizeof(struct Polyomial));
		switch (compare(qa, qb)) {
		case 1:
		{
			qc->coef = qa->coef;
			qc->expn = qa->expn;
			qa = qa->next;
			break;
		}
		case 0:
		{
			qc->coef = qa->coef + qb->coef;
			qc->expn = qa->expn;
			qa = qa->next;
			qb = qb->next;
			break;
		}
		case -1:
		{
			qc->coef = qb->coef;
			qc->expn = qb->expn;
			qb = qb->next;
			break;
		}
		}//switch
		if (qc->coef != 0) {
			qc->next = hc->next;
			hc->next = qc;
			hc = qc;
		}
		else free(qc);//�����ϵ��Ϊ0ʱ���ͷŸý��
	}//while
	return headc;
}//AddPoly
Poly SubtractPoly(Poly pa, Poly pb)
{                           //��Ⲣ��������ʽa+b��������ͷָ��
	Poly h = pb;
	Poly p = pb->next;
	Poly pd;
	while (p) {           //��pb��ϵ��ȡ��
		p->coef *= -1;
		p = p->next;
	}
	pd = AddPoly(pa, h);
	for (p = h->next; p; p = p->next)    //�ָ�pb��ϵ��
		p->coef *= -1;
	return pd;
}//SubtractPoly
int main() {
	int m, n, flag = 0;
	float x;
	Poly pa = 0, pb = 0, pc, pd, pe, pf;//�����ʽ��ͷָ�룬pa��pb��ʹ��ǰ��ֵNULL
	printf("����a������:");
	scanf("%d", &m);
	pa = CreatePoly(pa, m);//��������ʽa
	printf("����b������:");
	scanf("%d", &n);
	pb = CreatePoly(pb, n);//��������ʽb
	for (;; flag = 0) {
		printf("-->��ѡ��flag(1��2��3��4)��ִ�ж�Ӧ�Ĳ���");
		scanf("%d", &flag);
		if (flag == 1) {
			printf("����ʽa��"); PrintPoly(pa);
			printf("����ʽb��"); PrintPoly(pb);
			continue;
		}
		if (flag == 2) {
			pc = AddPoly(pa, pb);
			printf("����ʽa+b��"); PrintPoly(pc);
			DestroyPoly(pc);
			continue;
		}
		if (flag == 3) {
			pd = SubtractPoly(pa, pb);
			printf("����ʽa-b��"); PrintPoly(pd);
			DestroyPoly(pd);
			continue;
		}
		if (flag == 4) break;
		if (flag < 1 || flag>4) printf("Error!!!\n"); continue;
	}//for
	DestroyPoly(pa);
	DestroyPoly(pb);
	return 0;
}
