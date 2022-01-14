#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//进行构建大顶堆
void maxHeap(vector<int>&arr,int start,int end){
    int dad=start;  //父节点从0 开始
    int son=dad*2+1;
    while(son<=end){
        if(son+1<=end&&arr[son]<arr[son+1])++son;
        if(arr[dad]>arr[son]) return;
        else{
            swap(arr[dad],arr[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}
void heapSort(vector<int>&arr){
    int len=arr.size();
    for(int i=len/2-1;i>=0;--i)maxHeap(arr,i,len-1);

    for(int i=len-1;i>0;--i){
        swap(arr[i],arr[0]);
        maxHeap(arr,0,i-1);
    }
}
void printHeap(const vector<int>&arr){
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>res={1,6,10,2,3,4,5};
    maxHeap(res,0,res.size());
    printHeap(res);
    return 0;
}