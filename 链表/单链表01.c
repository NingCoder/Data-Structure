#include<stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode*next;
}LNode,*LinkList;

//头插法-->有头结点
LinkList Insert_Head_LinkList()
{
	LNode *L=(LNode*)malloc(sizeof(LNode));//开辟头指针空间
	L->next=NULL;
	int x;
	for(x=0;x<10;x++)
	{
		LNode *l=(LNode*)malloc(sizeof(LNode));
		l->data=x;

		l->next=L->next;
		L->next=l;
	}
	return L;
}

//这种方式最好理解-->也是最简单的理解方式
LinkList Insert_Nonhead_LinkList()
{
	LNode *L=(LNode*)malloc(sizeof(LNode));//开辟头指针空间
	int x =0;
	L->data=x;
	L->next=NULL;

	for(x+=1;x<10;x++)
	{
		LNode *l=(LNode*)malloc(sizeof(LNode));
		l->data=x;

		l->next=L;
		L=l;
	}
	return L;
}

LinkList Insert_Tail_LinkList_01()
{
	LNode *L=(LNode*)malloc(sizeof(LNode));//开辟头指针空间
	L->next=NULL;

	LNode *p=L;
	int x;
	for(x=0;x<10;x++)
	{
		LNode *l=(LNode*)malloc(sizeof(LNode));
		l->data=x;

		p->next=l;
		l->next=NULL;
		p=l;
	}
	return L;
}
LinkList Insert_Tail_LinkList_02()
{
	LNode *L=(LNode*)malloc(sizeof(LNode));//开辟头指针空间
	L->next=NULL;

	LNode *p=L;
	int x=0;
	p->data=x;
	for(x+=1;x<10;x++)
	{
		LNode *l=(LNode*)malloc(sizeof(LNode));
		l->data=x;

		p->next=l;
		l->next=NULL;
		p=l;
	}
	return L;
}
void Print_linkList_Head(LinkList L)
{
	LNode *p=L->next;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}

void Print_linkList_Nonhead(LinkList L)
{
	LNode *p=L;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	LinkList L0=Insert_Head_LinkList();
	Print_linkList_Head(L0);
	LinkList L1=Insert_Nonhead_LinkList();
	Print_linkList_Nonhead(L1);
	LinkList L2=Insert_Tail_LinkList_01();
	Print_linkList_Head(L2);
	LinkList L3=Insert_Tail_LinkList_02();
	Print_linkList_Nonhead(L3);
}

