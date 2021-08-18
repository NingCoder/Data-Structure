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
    //直接为空
    LQ.front=LQ.rear=NULL;  
}
bool IsEmpty(LinkQueue&LQ)
{
    if(LQ.front==NULL) return true;
    else return false;
}
bool Enter_LinkQueue(LinkQueue&LQ,ElemType e)
{
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    if(!s) return false;
    s->next=NULL;
    s->data=e;
    if(LQ.rear==NULL)
    {
        LQ.rear=LQ.front=s;
    }
    else
    {
        s->next=LQ.rear->next;
        LQ.rear=s;
    }
    return true;
}
bool Delete_LinkQueue(LinkQueue&LQ,ElemType&e)
{
    if(LQ.front==NULL) return false;
    LinkNode*s=LQ.front;
    e=s->data;
    LQ.front=s->next;
    if(LQ.rear==s)
    {
         LQ.rear=LQ.front=NULL;
    }
    free(s);
    return true;
}
int main()
{
    LinkQueue LQ;
    Init_LinkQueue(LQ);
    Enter_LinkQueue(LQ,3);
    Enter_LinkQueue(LQ,4);
    // printf("%d\n",LQ.front->data);//存放过头结点
    // printf("%d\n",LQ.rear->data);
    ElemType e=0;
    Delete_LinkQueue(LQ,e);
    printf("删除的元素是: %d\n",e);

    // printf("%d\n",LQ.rear->data);//存放过头结点
}