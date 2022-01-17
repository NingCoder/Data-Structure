#include <iostream>
using namespace std;

const int MAXSIZE=10;

class sqList{
private:
    int arr[MAXSIZE];
    int length;
public:
    //不使用 使用这个方法
    void InitSq(sqList&sq);
    bool insertSq(int index,int val,sqList&sq);
    int  getLength(const sqList&sq);
    bool deleteSq(int index,sqList&sq);
    bool isInSq(const sqList&sq,int val);   
    int  getIndex(const sqList&sq,int val);
    bool isEmpty(const sqList&sq);
    void printSq(const sqList&sq);
};
void sqList::InitSq(sqList&sq){
    int size=MAXSIZE>>1;
    for(int i=0;i<size;++i){
        sq.arr[i]=i;
    }
    sq.length=size;
}
bool sqList::insertSq(int index,int val,sqList&sq){
    if(index>sq.length||index<0||index>=MAXSIZE){
        return false;
    }
    for(int i=sq.length;i>index;--i){
        sq.arr[i]=sq.arr[i-1];
    }
    sq.arr[index]=val;
    ++sq.length;
    return true;
}
bool sqList::deleteSq(int index,sqList&sq){
    if(index<0||index>=sq.length){
        return false;
    }
    for(int i=index;i<sq.length;++i){
        sq.arr[i]=sq.arr[i+1];
    }
    --sq.length;
    return true;
}
int  sqList::getLength(const sqList&sq){
    return sq.length;
}
bool sqList::isInSq(const sqList&sq,int val){
    for(int i=0;i<sq.length;++i){
        if(sq.arr[i]==val){
            return true;
        }
    }
    return false;
}
int sqList::getIndex(const sqList&sq,int val){
    for(int i=0;i<sq.length;++i){
        if(sq.arr[i]==val){
            return i;
        }
    }
    return -1;
}
bool sqList::isEmpty(const sqList&sq){
    return sq.length == 0;
}
void sqList::printSq(const sqList&sq){
    for(int i=0;i<sq.length;++i){
        cout<<sq.arr[i]<<" ";
    }
    cout<<endl;
}
void testSq(){
    sqList sq;
    sq.InitSq(sq);
    sq.printSq(sq);

    // sq.insertSq(0,12,sq);
    // sq.insertSq(6,12,sq);

    // sq.deleteSq(0,sq);
    // sq.deleteSq(4,sq);

    cout<<sq.isEmpty(sq)<<endl;
    cout<<sq.isInSq(sq,12)<<endl;
    cout<<sq.getIndex(sq,12)<<endl;
    sq.printSq(sq);
}
int main(){
    testSq();
    return 0;
}