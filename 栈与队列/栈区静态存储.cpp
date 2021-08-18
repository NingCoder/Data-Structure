#include <iostream>
using namespace std;

// 预先定义
#define MAX_SIZE 10
typedef int ElemType;

// 构建栈
typedef struct
{
    ElemType data[MAX_SIZE];
    int top;
}SqStack;

// 初始化-->将栈顶top设置为-1
void Init_SqStack(SqStack &Sq)
{
    Sq.top=-1;
}

// 插入元素
bool Insert_SqStack(SqStack &Sq,ElemType e)
{
    if(Sq.top==MAX_SIZE-1) return false;
    Sq.top++;
    Sq.data[Sq.top]=e;
    return true;
}
// 删除元素
bool Delete_SqStack(SqStack&Sq,ElemType&e)
{
    if(Sq.top==-1) return false;
    e=Sq.data[Sq.top];
    Sq.top--;
    return true;
}
// 获取栈顶元素
bool Get_SqStack(SqStack&Sq,ElemType&e)
{
    if(Sq.top==-1) return false;
    e=Sq.data[Sq.top];
    return true;
}
int main()
{
    SqStack Sq;
    Init_SqStack(Sq);
    Insert_SqStack(Sq,12);
    ElemType e=0;
    ElemType i=0;
    Delete_SqStack(Sq,i);
    Get_SqStack(Sq,e);
    printf("%d\t",Sq.top);
}