#include <iostream>
using namespace std;
const int maximum=10;
//顺序表查找
int seqSearch(int *arr,int k,int maximum){
    for(int i=0;i<maximum;++i){
        if(arr[i]==k){
            return i;
        }
    }return -1;
}
//折半查找01
int biSearch(int *arr,int k,int maximum){
    int i=0,j=maximum-1;
    while(i<j){
        int mid=(i+j)>>1;
        if(arr[mid]==k){
            return mid;
        }else if(arr[mid]<k){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }return -1;
}
//折半查找02 只是适合于有序的
int biSearch(int *arr,int k,int i,int j){
    int mid=(i+j)>>1;
    if(arr[mid]==k){
        return mid;
    }
    if(i==j){
        return -1;
    }
    if(arr[mid]>k){
        return biSearch(arr,k,i,mid);
    }else{
        return biSearch(arr,k,mid,j);
    }
}
void testSearch(){
    int arr[maximum];
    for(int i=maximum-1;i>=0;--i){
        arr[i]=maximum-i;
    }
    for(int i=0;i<maximum;++i){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<seqSearch(arr,5,maximum)<<endl;
    //折半查找只适合于  顺序  序号递增 
    cout<<biSearch(arr,5,maximum)<<endl;
    cout<<biSearch(arr,5,0,maximum-1)<<endl;
}
int main(){
    testSearch();
    return 0;
}