#include <iostream>
using namespace std;

const int initSize=5;
const int maxSize=10;
struct Sqlist{
    int arr[maxSize];
    int length;
};
void initSqList(Sqlist&sq){
    //直接初始化
    //sq.length=0
    //稍微修改一下
    for(int i=0;i<initSize;++i){
        sq.arr[i]=i;
    }
    sq.length=initSize;
}
//按照长度进行进行插入
bool insertSqList(Sqlist&sq,int length,int val){
    if(length>sq.length+1||length<=0||sq.length>=maxSize){
        return false;
    }
    for(int i=sq.length;i>=length;--i){
        sq.arr[i]=sq.arr[i-1];
    }
    sq.arr[length-1]=val;
    ++sq.length;
    return true;
}
//删除 依照长度进行删除
int deleteSqList(Sqlist&sq,int length){
    if(length<=0||length>sq.length){
        return -1;
    }
    int val=sq.arr[length-1];
    for(int i=length-1;i<sq.length;++i){
        sq.arr[i]=sq.arr[i+1];
    }
    --sq.length;
    return val;
}
//清除操作
void clearSqList(Sqlist&sq){
    sq.length=0;
}
//按照长度访问
void printSqList(const Sqlist&sq){
    for(int i=0;i<sq.length;++i){
        cout<<sq.arr[i]<<" ";
    }cout<<endl;
}
//进行简单测试
void testSqList(){
    Sqlist sq;
    //初始化
    initSqList(sq);
    printSqList(sq);

//    //头部插入
//    insertSqList(sq,1,12);
//    printSqList(sq);
//    //尾部插入
//    insertSqList(sq,7,12);
//    printSqList(sq);

    //删除
    int val=deleteSqList(sq,1);
    cout<<val<<endl;
    printSqList(sq);
    //删除
    val=deleteSqList(sq,4);
    cout<<val<<endl;
    printSqList(sq);
}
int main(){
    testSqList();
    return 0;
}