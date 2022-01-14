#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//进行构建大顶堆
void maxHeap(vector<int>&arr,int i,int heapSize){
    //设置左右序号
    int left=i*2+1,right=i*2+2;
    //默认父节点 的数值是最大的数
    int largest=i;
    //使得largest的数值是当前节点中的最大数值
    if(left<heapSize&&arr[left]>arr[largest])largest=left;
    if(right<heapSize&&arr[right]>arr[largest])largest=right;
    //如果largest的数值不等于i 则表明需要进行交换操作
    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxHeap(arr,largest,heapSize);
    }
}
void buildHeap(vector<int>&arr,int heapSize){
    for(int i=heapSize/2;i>=0;--i)maxHeap(arr,i,heapSize);
    // for(int i=0;i<=heapSize/2;++i)maxHeap(arr,i,heapSize);
}

void printHeap(const vector<int>&arr){
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>arr={3,2,3,1,2,4,5,5,6};
    //对于队的构建
    int heapSize=arr.size();
    buildHeap(arr,heapSize);
    for(int i=heapSize-1;i>=arr.size()-4+1;--i){
        swap(arr[i],arr[0]);
        --heapSize;
        maxHeap(arr,0,heapSize);
    }
    cout<<arr[0]<<endl;
    printHeap(arr);
    return 0;
}