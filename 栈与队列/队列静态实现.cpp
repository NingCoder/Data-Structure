#include <iostream>
using namespace std;

// 预先定义
#define MAX_SIZE 10
typedef int ElemType;

// 构建队列
typedef struct
{
    ElemType data[MAX_SIZE];
    int front,rear;
}SqQueue;

// 初始化
void Init_Queue(SqQueue &SQ)
{
    SQ.front=SQ.rear=0;
}
//插入操作
bool Enter_Queue(SqQueue&SQ,ElemType e)
{
    if((SQ.rear+1)%MAX_SIZE==SQ.front) return false;

    SQ.data[SQ.rear]=e;
    SQ.rear=(SQ.rear+1)%MAX_SIZE;
    return true;
}
//去除操作
bool Delete_Queue(SqQueue&SQ,ElemType&e)
{
    if(SQ.front==SQ.rear) return false;
    e=SQ.data[SQ.front];
    SQ.front=(SQ.front+1)%MAX_SIZE;
    return true;
}
// 查看操作
bool IsEmpty(SqQueue&SQ)
{
    if(SQ.front==SQ.rear) return false;
    else return true;
}
int main()
{
    SqQueue SQ;
    Init_Queue(SQ);
    ElemType e=3;
    Enter_Queue(SQ,e);
    printf("插入之后的队列首元素: %d\n",SQ.data[SQ.front]);
    Delete_Queue(SQ,e);
    printf("删除的队列元素是: %d\n",e);
    printf("删除之后的队列首元素: %d\n",SQ.data[SQ.front]);
}