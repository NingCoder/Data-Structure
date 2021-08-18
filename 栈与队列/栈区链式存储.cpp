// 没有实现


#include <iostream>
using namespace std;

// 预先定义
typedef int ElemType;

// 构建栈区结构
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LiStack;

bool Insert_LiStack(LiStack &LS,ElemType e)
{
    if(LS==NULL) return false;

    LinkNode* s=(LinkNode*)malloc(sizeof(LinkNode));
    s->next=NULL;
    if(!s) return false;

    s->data=e;
    s->next=LS->next;
    LS->next=s;
    return true;

}
int main()
{
    LiStack *LS;
    
}