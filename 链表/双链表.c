#include<stdio.h>
#include <stdlib.h>

typedef struct Line
{
    struct Line *pre; //存放头结点
    int data;
    struct Line *next;//存放下一个结点
}line,*a;

line * InitLine(line *head)
{
    int x=0;
    head=(line*)malloc(sizeof(line));
    head->data=x;
    head->next=head->next=NULL;

    line*l=head;
    for(x+=1;x<10;x++)
    {
        line*q=(line*)malloc(sizeof(line));
        q->next=q->pre=NULL;
        q->data=x;

        l->next=q;
        q->pre=l;
        l=l->next;
    }
    return head;
}

line* GetELem(line *head,int i)
{
    int j=0;
    line*l=head;
    while((l!=NULL)&&i>j)
    {
        l=l->next;
        j++;
    }
    return l;
}

line* InsertLine(line*head,int i,int e)
{
    line*l=head;
    l=GetELem(l,i-1);
    if(l)
    {
            line*tmp=(line*)malloc(sizeof(line));
            tmp->data=e;
            tmp->next=tmp->pre=NULL;

        if(i==0)
        {
            tmp->next=head;
            head->pre=tmp;
            head=tmp;
        }
        else 
        {
            if(l!=NULL)
            {
                // printf("%d\n",l->data);
                tmp->next=l->next;      //对于后面节点的继承
                l->next=tmp;
                tmp->pre=l;
            }       
        }
    }
    else printf("节点不在范围内!操作失败!返回原节点\n");

    return head;
}

line* DeleteLine(line*head,int i)
{
    line*l=head;
    l=GetELem(l,i);//如果超出位数之后直接无效
    if(l)
    {
        if((l->pre!=NULL)&&(l->next==NULL))
        {
            line*p=l->next;
            l->next=NULL;
            l->pre->next=NULL;
            free(l);
        }
        else
            {
            line*p=l->next;
            l->next=p->next;
            l->pre->next=p;
            free(l);
            } 
    }
    else printf("节点不在范围内!操作失败!返回原节点\n");
     
    return head;
}
void Display(line*q)
{
    while(q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->next;
    }
    printf("\n");
}
int main()
{
    line*l=NULL;

    l= InitLine(l);
    Display(l); 

    l=GetELem(l,1);
    if(l!=NULL)
    {
        printf("%d\n",l->data);
    }

    l=InsertLine(l,11,10); 
    Display(l); 

    l=DeleteLine(l,10);
    Display(l);
}
