#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list*next;
}list;

list * InitList()
{
    list*head=(list*)malloc(sizeof(list));
    if(!head)
    {
        printf("创建失败!");
        exit(0);
    }
    else
    {
        head->next=NULL;
        return head;
    }
}
int InsertList(list* l)
{
    list *p=InitList();//进行初始化操作
    int x=0;
    p->data=x;
    if(l!=NULL)
    {
        list*s=l;
        while(s->next!=l)
        {
            s=s->next;
        }
        s->next=p;
        p->next=l;
    }


}
int main()
{
    list *l=InitList();
    l->next=l;
}