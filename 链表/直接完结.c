#include<stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode*next;
}LNode,*LinkList;


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

LNode* GetELem(LinkList L,int i)//按位置查找
{
    int tmp=1;
    if(i==0) return L->next;
    if(i<1) return NULL;
    LNode *p=L->next->next; //带节点的需要进行两次
    while((p!=NULL)&&(i>tmp))
    {
        p=p->next;
        tmp++;
    }
    return p;
}

int LocateElem (LinkList L,int e)
{
    int i=0;
    LNode *p=L->next;
    while((p!=NULL)&&(p->data!=e))
    {
        i++;
        p=p->next;
    }
    if(p==NULL)
    {
        return -1;
    }
    return i;
}
LinkList LinkedList_Insert(LinkList L,int i ,int e)
{
    LNode*pre= GetELem(L,i-1);
    // printf("%d\n",pre->data);
    LNode*p= (LNode*)malloc(sizeof(LNode));
    p->data=e;
    p->next=pre->next;
    pre->next=p;
    return L;
}
void LinkedList_Delete(LinkList L,int i )
{
    LNode*pre= GetELem(L,i-1);
    
    LNode*p;
    p=pre->next;
    pre->next=p->next;
    free(p);                                //释放节点
}
int main()
{
	LinkList L0=Insert_Tail_LinkList_01();
	Print_linkList_Head(L0);


    LNode*p= GetELem(L0,0);
    printf("%d\n",p->data); 

    int i=LocateElem(L0,10);
    printf("%d\n",i); //如果过在返回地址数-->如果不在返回-1

    LinkedList_Insert(L0,9,2);
    Print_linkList_Head(L0);

    LinkedList_Delete(L0,9);
    Print_linkList_Head(L0);
}
