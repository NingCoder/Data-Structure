#include <iostream>
using namespace std;

// 预先定义
#define MAX_SIZE 10
typedef int ElemType;

// 构建队列结构
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode*next;
}LinkNode;

typedef struct LinkQueue
{
    struct LinkNode *rear,*front;
}LinkQueue;

void Init_LinkQueue(LinkQueue&LQ)
{
    // 建立头结点
    LQ.front=LQ.rear=(LinkNode*)malloc(sizeof(LinkNode));
    LQ.front->next=NULL;
    
}
bool IsEmpty(LinkQueue&LQ)
{
    if(LQ.front==LQ.rear) return true;
    else return false;
}
bool Enter_LinkQueue(LinkQueue&LQ,ElemType e)
{
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    if(!s) return false;

    s->data=e;s->next=NULL;
    LQ.rear->next=s;
    LQ.rear=s;
    return true;
}
bool Delete_LinkQueue(LinkQueue&LQ,ElemType&e)
{
    if(LQ.front==LQ.rear) return false;
    LinkNode *p=LQ.front->next;
    e=p->data;//获取头结点的数据
    LQ.front->next=p->next;
    if(LQ.rear==p)
        LQ.front=LQ.rear;
    free(p);
    return true;
}
int main()
{
    LinkQueue LQ;
    Init_LinkQueue(LQ);
    Enter_LinkQueue(LQ,3);
    Enter_LinkQueue(LQ,4);
    printf("%d\n",LQ.front->next->data);//存放过头结点
    // printf("%d\n",LQ.rear->data);
    ElemType e=0;
    Delete_LinkQueue(LQ,e);
    printf("删除的元素是: %d\n",e);
    printf("%d\n",LQ.front->next->data);//存放过头结点
}