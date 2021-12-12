#include <iostream>
using namespace std;

const int maxium=10;

typedef struct sq
{
    int sequence[maxium];
    int length;
}sq;

class SequenceList
{
    public:
        void InitList(sq&s);                                //初始化线性表  -->感觉这个很没有必要
        void DestroyList(sq&s);                             //销毁 线性表和 清除 线性表 -->这个实现 下来是一样的
        // void ClearList(sq&s);
        bool ListEmpty(sq&s);                               //判断 线性表 是否为空
        int ListLength(sq&s);                               //求取线性表的长度
        bool GetElem(sq&s,int target);                     //是否存在这个元素
        int Located(sq&s,int target);                   //对于这个元素进行定位 
        void PriorElem(sq&s);                            //前驱节点
        void NextElem(sq&s);                            //后继节点
        bool ListInsert(sq&s,int index,int target);     //插入
        bool ListDelete(sq&s,int target);              //删除
        void ListDisplay(sq&s);                         //展示
};
void SequenceList::InitList(sq&s)
{
    //初始化一个线性表 
    
    //在刚开始的时候就可以直接初始化好 
    // for(int i=0;i<5;++i)s.sequence[i]=i; s.length=5;

    //1. 长度设置为 0
    s.length = 0;
}
void SequenceList::DestroyList(sq&s)
{
    //销毁数组 
    //1. 将元素设置为 0
    //2. 长度设置为 0
    for(int i=0;i<s.length;++i)
    {
        s.sequence[i]=0;
    }
    s.length = 0;
}
bool SequenceList::ListEmpty(sq&s)
{
    cout<<s.length<<endl;
    return s.length == 0;
}
int SequenceList::ListLength(sq&s)
{
    return s.length;
}
bool SequenceList::GetElem(sq&s,int target)
{
    for(int i=0;i<s.length;++i)
    {
        if(s.sequence[i]==target) return true;
    }
    return false;
} 
int SequenceList::Located(sq&s,int target)
{
    for(int i=0;i<s.length;++i)
    {
        if(s.sequence[i]==target) return i;
    }
    return -1;
} 
bool SequenceList::ListInsert(sq&s,int index,int target)
{
    if(s.length+1>maxium||s.length<0||index>=s.length+1) return false;
    ++s.length;
    for(int i=s.length;i>index;--i)
    {
        s.sequence[i]=s.sequence[i-1];
    }
    s.sequence[index]=target;
    return true;
}       
bool SequenceList::ListDelete(sq&s,int target)
{
    int index=Located(s,target);
    if(index==-1) return false;
    for(int i=index;i<s.length;++i)
    {
        s.sequence[i]=s.sequence[i+1];
    }
    --s.length;
    return true;
}     
void SequenceList::ListDisplay(sq&s)
{
    for(int i=0;i<s.length;++i)
    {
        cout<<s.sequence[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    sq s;
    SequenceList sequence;
    sequence.InitList(s);
    cout<<sequence.ListEmpty(s)<<endl;
    return 0;
}