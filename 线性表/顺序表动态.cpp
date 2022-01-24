//
// Created by 宁一远 on 2022/1/23.
//

#include <iostream>
using namespace std;

const int initSize=9;
const int maxSize=10;
struct Sqlist{
    int *data;
    int length,maxSize;
};
void initSqList(Sqlist&sq){
    sq.maxSize=maxSize;
    sq.data=new int[sq.maxSize];
    for(int i=0;i<initSize;++i){
        sq.data[i]=i;
    };
    sq.length=initSize;
}
//按照长度进行进行插入
bool insertSqList(Sqlist&sq,int length,int val){
    if(length>sq.length+1||length<=0){
        return false;
    }
    if(length>sq.maxSize){
        //开辟空间
        int *ptr=new int [maxSize+maxSize];
        //手动复制一下
        for(int i=0;i<sq.length;++i){
            ptr[i]=sq.data[i];
        }
        delete sq.data;
        sq.data=ptr;
        sq.maxSize+=maxSize;
    }
    for(int i=sq.length;i>=length;--i){
        sq.data[i]=sq.data[i-1];
    }
    sq.data[length-1]=val;
    ++sq.length;
    return true;
}
//删除 依照长度进行删除
int deleteSqList(Sqlist&sq,int length){
    if(length<=0||length>sq.length){
        return -1;
    }
    int val=sq.data[length-1];
    for(int i=length-1;i<sq.length;++i){
        sq.data[i]=sq.data[i+1];
    }
    --sq.length;
    return val;
}
//清除操作
void clearSqList(Sqlist&sq){
    delete sq.data;
    sq.length=0;
}
//进行访问
void printSqList(const Sqlist&sq){
    for(int i=0;i<sq.length;++i){
        cout<<sq.data[i]<<" ";
    }cout<<endl;
}
//进行简单测试
void testSqList(){
    Sqlist sq;
    //初始化
    initSqList(sq);
    printSqList(sq);

    insertSqList(sq,10,9);
    printSqList(sq);

    insertSqList(sq,11,10);
    printSqList(sq);
    insertSqList(sq,12,11);
    printSqList(sq);
//    cout<<sq.maxSize<<" "<<sq.length<<endl;

//    deleteSqList(sq,11);
//    printSqList(sq);
    deleteSqList(sq,1);
    printSqList(sq);

    clearSqList(sq);
    printSqList(sq);
    cout<<sq.length<<endl;
}
int main(){
    testSqList();
    return 0;
}