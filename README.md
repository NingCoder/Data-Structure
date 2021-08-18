# 数据结构 Data Structure

## 链表



### 线性表

#### 创建

~~~c
#include<stdio.h>
#include<stdlib.h>

#define List_Init_Size 100
#define List_Increase 10

typedef struct
{
	int *data;
	int length;
	int listsize;
}SqList;
int InitList_Sq(SqList *sq)
{
	sq->data=(int*)malloc(sizeof(int)*List_Init_Size);
	if(!sq)
	{
		printf("创建空间失败!");
		return -1;
	}
	sq->listsize=List_Init_Size;
	sq->length=0;
	return 1;
}
int main()
{
	SqList sq;
	InitList_Sq(&sq);
	int i=0;
	for(i=0;i<10;i++)
	{
		sq.data[i]=i;
		sq.length++;
		printf("%d\t",sq.data[i]);
	}
	printf("\n");
}
~~~

#### 插入

~~~c
#include <stdio.h>
#include <stdlib.h>

#define List_Init_Size 10
#define List_Increase 10

typedef struct 
{
	int *data;
	int list_size;
	int length;
}SqList;

int InitList_Sq(SqList*sq)
{
	sq->data=(int *)malloc(sizeof(int)*List_Init_Size);
	if(!sq->data) return -1;
	sq->list_size=List_Init_Size;
	sq->length=0;
	return 0;
}
int InsertList_Sq(SqList*sq,int i,int e)//按照长度来查找-->从1开始的
{
	if(i<1||sq->length+1<i) return -1;	//如果长度小于1或者长度比线性表长度+1都大

	if(sq->length+1>sq->list_size)		//如果地址空间不够的话-->长度加1之后大于总长度
	{
		int *newdata=(int*)realloc(sq->data,sizeof(int)*(sq->list_size+List_Increase));
		if(!newdata) return -1;
		sq->data=newdata;
		sq->list_size+=List_Increase;
	}

	int *p=&sq->data[i];				//当前i的地址
	int *q=&(sq->data[sq->length]);		//当前长度的地址
	for(q;q>=p;--q)
	{
		*(q+1)=*q;
	}
	*p=e;
	++sq->length;
	return 0;
}
int main()
{
	SqList sq;
	InitList_Sq(&sq);
	int i=0;
	for(i=0;i<sq.list_size;i++)
	{
		sq.data[i]=i;
		sq.length++;
		printf("%d\t",sq.data[i]);
	}
	printf("\n");
	InsertList_Sq(&sq,2,3);
	// printf("%d\n",sq.list_size);
	for (i=0;i<sq.length;i++)
	{
		printf("%d\t",sq.data[i]);
	}
	printf("\n");
}
~~~

#### 删除

~~~c
#include <stdio.h>
#include <stdlib.h>

#define List_Init_Size 10 				//初始化数值
#define List_Increase 10 				//初始化增加的数值

typedef struct 							//定义Sqlist类型-->包含数据 当前长度 总长度
{
	int *data;
	int list_size;
	int length;
}SqList;

int InitList_Sq(SqList*sq)				//初识话数组
{
	sq->data=(int *)malloc(sizeof(int)*List_Init_Size);
	if(!sq->data) return -1;
	sq->list_size=List_Init_Size;
	sq->length=0;
	return 0;
}

int ListDelete_Sq(SqList*sq,int i)		//删除数组中i位置的元素
{
	if(i<0||i>sq->length) return -1;	//验证位置的合法性
	int res=sq->data[i];				//记录在i位置上那个元素的数值
	int *p=&(sq->data[i]);				//去取出那个元素的位置					
	int *q=&(sq->data[sq->length]);		//总长度的地址
	for(p;p<q;++p)
	{
		*(p-1)=*p;
	}
	sq->length--;
	return res;							//用作返回值
}
int main()
{
	SqList sq;
	InitList_Sq(&sq);
	int i=0;
	for(i=0;i<sq.list_size;i++)
	{
		sq.data[i]=i;
		sq.length++;
		printf("%d\t",sq.data[i]);
	}
	printf("\n");
	int Delete=ListDelete_Sq(&sq,0);
	printf("删除的元素是: %d\n",Delete);

	for (i=0;i<sq.length;i++)
	{
		printf("%d\t",sq.data[i]);
	}
	printf("\n");
}
~~~

#### 查找

~~~c
#include <stdio.h>
#include <stdlib.h>

#define List_Init_Size 10 				//初始化数值
#define List_Increase 10 				//初始化增加的数值

typedef struct 							//定义Sqlist类型-->包含数据 当前长度 总长度
{
	int *data;
	int list_size;
	int length;
}SqList;

int InitList_Sq(SqList*sq)				//初识话数组
{
	sq->data=(int *)malloc(sizeof(int)*List_Init_Size);
	if(!sq->data) return -1;
	sq->list_size=List_Init_Size;
	sq->length=0;
	return 0;
}

int SeachElement(SqList*sq,int e)
{
    int i=0;
    int target=sq->data[i];
    while((sq->length>=i)&&(target!=e))
    {
        ++i;
        target=sq->data[i];
    }
    if(i<sq->length) return i;
    else return -1;

}
int main()
{
	SqList sq;
	InitList_Sq(&sq);
	int i=0;
	for(i=0;i<sq.list_size;i++)
	{
		sq.data[i]=i;
		sq.length++;
		printf("%d\t",sq.data[i]);
	}
	printf("\n");
	int elem=2;
    int index=SeachElement(&sq,elem);
    printf("elem:%d-->index:%d\n",sq.data[index],index);
}
~~~

#### 算是完结

~~~c
#include<stdio.h>
#include <stdlib.h>

#define Init_List_Size 10
#define List_Increase 10

typedef struct
{
    int *data;
    int list_size;
    int length;
}SqList;

int Init_Sqlist(SqList*sq)
{
    sq->data=(int*)malloc(sizeof(int)*Init_List_Size);
    if(!sq->data) return -1;
    sq->length=0;
    sq->list_size=Init_List_Size;
}

int Insert_Sq(SqList*sq,int i ,int e)//index和element
{
    if(i<0||sq->length+1<i) return -1;//按照长度查找-->不能小于0
    if(sq->length>=sq->list_size)
    {
        int *newdata=(int*)realloc(sq->data,sizeof(int)*(sq->list_size+List_Increase));
        if(!newdata) return -1;

        sq->data=newdata;
        sq->list_size+=List_Increase;
    }
    int length=sq->length;
    // printf("%d\n",length);
    for(length;length>=i;length--)
    {
        // printf("%d\t",sq->data[length]);
        sq->data[length]=sq->data[length-1];
    }
    sq->data[i]=e;
    sq->length++;
    // printf("\n");
}

void List_Delete_Sq(SqList*sq,int i,int*e)
{
    if(i>sq->length) return ;
    // printf("index:%d \t elem:%d \n",i,sq->data[i-1]);
    int *p=&(sq->data[i-1]);
    *e=*p;
    for(i;sq->length>i;i++)
    {
        sq->data[i-1]=sq->data[i];
    }
    sq->length--;
    return ;
}

int  Search_Sq(SqList*sq,int e)
{
    // if(i>sq->length||i<0) return ;
    int tmp=0;
    int res=sq->data[tmp];
    // printf("%d\n",res);
    while((tmp<=sq->length)&&(res!=e))
    {
        ++tmp;
        res=sq->data[tmp]; 
        // printf("%d\n",res);  
    }
    // printf("%d\n",res);
    if (tmp<sq->length) return tmp+1;
    else return -1;
}

void Assignment(SqList*sq)
{
    int i=0;
    for(i;i<sq->list_size;i++)
    {
        sq->data[i]=i;
        sq->length++;
    }
}

void Print_Sq(SqList sq)
{
    int i=0;
    for(i;i<sq.length;i++)
    {
        printf("%d\t",sq.data[i]);
    }
    printf("\n");
}

int main()
{
    SqList sq;          //实例化链表
    Init_Sqlist(&sq);   //初始化链表
    Assignment(&sq);    //赋值
    // Print_Sq(sq);       //答应数据
    // // Insert_Sq(&sq,10,10);
    // // Print_Sq(sq);
    // int a=0;
    // // printf("被删除数值是: %d\n",sq.data[2]);
    // List_Delete_Sq(&sq,3,&a);
    // printf("被删除数值是: %d\n",a);
    Print_Sq(sq);
    printf("%d\n",Search_Sq(&sq,2));
}
~~~

### 链表



#### 创建C++

~~~c
#include <iostream>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode*next;
}LNode,*LinkList;
//使用头插法
LinkList List_HeadInsert01(LinkList &L)
{
	LNode *s;int x;
	L=(LNode*)malloc(sizeof(LNode));			//创建头结点
	L->next=NULL;
	for(x=0;x<=10;x++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
	}
	return L;
}
LinkList List_HeadInsert02(LinkList &L)
{
	LNode *s;int x;
	L=(LNode*)malloc(sizeof(LNode));			//创建头结点
	L=s=NULL;
	for(x=0;x<=10;x++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;

		if(L==NULL) L->next=NULL;
		else s->next=L->next;

		L->next=s;
	}
	return L;
}
LinkList List_TailInsert01(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));			//创建头结点
	LNode*r=L,*s;int x;
	for(x=0;x<=10;x++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->next=NULL;
		s->data=x;
		r->next=s;
		r=s;
	}
	return L;
}
LinkList List_TailInsert02(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));			//创建头结点
	LNode*r=L=NULL,*s;int x;
	for(x=0;x<=10;x++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=NULL;
		if(r==NULL) r=L=s;
		else r->next=s;
		r=s;
	}
	return L;
}

//打印输出节点
void Print_Head_List(LinkList L)
{
	LNode*p= L->next;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
	return ;
}
//打印输出节点
void Print_Tail_List(LinkList L)
{
	LNode*p= L->next;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
	return ;
}

int main()
{
	cout<<"使用头插法带头结点的方式: "<<endl;
	LinkList L1;
	List_HeadInsert01(L1);
	Print_Head_List(L1);

	cout<<"使用头插法不带头结点的方式: "<<endl;
	LinkList L2;
	List_HeadInsert01(L2);
	Print_Head_List(L2);

	cout<<"使用尾插法带头结的方式: "<<endl;
	LinkList L3;
	List_TailInsert01(L3);
	Print_Tail_List(L3);

	cout<<"使用尾插法不带头结的方式: "<<endl;
	LinkList L4;
	List_TailInsert01(L4);
	Print_Tail_List(L4);
}
~~~

#### 直接完结

~~~c
#include <iostream>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode*next;
}LNode,*LinkList;

//使用尾插法带头结点
LinkList List_TailInsert(LinkList &L)
{
	
	L=(LNode*)malloc(sizeof(LNode));			//创建头结点
	LNode *s,*l=L;int x;
	for(x=0;x<=10;x++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=NULL;
		l->next=s;
		l=s;
	}
	return L;
}
//获取到元素的个数
LNode* GetElem(LinkList&L,int i)
{
	int j=1;
	LNode*p=L->next->next;
	// L=L->next;
	if(i==0) return L;
	if(i<1) return NULL;
	while(p&&i>j)  //这个节点是从1开始的p是他的第一个节点
	{
		p=p->next;
		j++;
	}
	return p;
}
// 获取到元素的位置
LNode* LocateElem(LinkList L,int e)
{
	LNode*p=L->next;
	while(p!=NULL&&p->data!=e)		//进行查找-->找到的情况
	{
		p=p->next;
	}
	if(p==NULL)						//进行查找-->找不到的情况
	{
		return NULL;
	}
	return p;
}

//打印尾插法输出节点
void Print_Tail_List(LinkList L)
{
	LNode*p= L->next;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
	return ;
}
// 删除某个节点
void DeleteElem(LinkList &L,int i)
{
	LNode*p= GetElem(L,i-1);//要删除3-->需要先删除他的直接前驱
	LNode*q=p->next;
	p->next=q->next;
	delete q;
}
// 插入某个节点
void InsertElem(LinkList &L,int i,int e)
{
	LNode*p= GetElem(L,i-1);
	// cout<<p->data<<endl;		
	LNode *q=(LNode*)malloc(sizeof(LNode));			//调用一个函数需要在栈区开辟一个空间-->所以需要使用到malloc函数
	q->data=e;
	
	q->next=p->next;
	p->next=q;
}
// 获取链表的长度
void GetLen(LinkList L,int&i)
{
	LNode*p=L->next;
	i=1;
	while(p->next!=NULL)
	{
		i++;
		p=p->next;
	}	
}
int main()
{
	cout<<"使用头插法带头结点的方式: "<<endl;
	LinkList L1;
	List_TailInsert(L1);
	Print_Tail_List(L1);

	InsertElem(L1,2,10);			//在第二个坐标下插入10

	LNode *p=GetElem(L1,2);			//查找元素的数值
	cout<<p->data<<endl;

	LNode *q=LocateElem(L1,0);		//查找元素的位置 使用带头结点的存储，0输出的是头节点的数值-->所以必须对于带头结点的进行-->next操作
	cout<<q->data<<endl;
	
	DeleteElem(L1,2);				//删除操作

	Print_Tail_List(L1);

	int i;
	GetLen(L1,i);
	cout<<"链表的长度是: "<<i<<endl;
}
~~~



### 链表_简易版本__C 语言

#### 创建

~~~c
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
~~~

#### 插入节点

~~~c
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
~~~

#### 删除节点

~~~c
void LinkedList_Delete(LinkList L,int i )
{
    LNode*pre= GetELem(L,i-1);
    
    LNode*p;
    p=pre->next;
    pre->next=p->next;
    free(p);                                //释放节点
}
~~~

#### 查找

##### 按位置

~~~c
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
~~~

##### 按数据

~~~c
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
~~~



### 完整代码

~~~C
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
~~~

### 双链表 完结

#### 	创建

~~~c
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
~~~

#### 获取节点位置

~~~c
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
~~~

#### 插入节点

~~~c
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
~~~

#### 删除节点

~~~c
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
~~~

#### 完整代码

~~~c
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
~~~



## 附录

### 参考链接

1. [博客园](https://www.cnblogs.com/komean/p/10700047.html)
2. [一远阁](www.xisunyy.top)
3. [C语言站](https://www.dotcpp.com/course/99)
