#include <iostream>
#include <cstring>
using namespace std;

struct huffmanTree{
    int weight;
    int parent,lchild,rchild;
};
const int n=4;
const int m=2*n-1;
void createHuffmanTree(huffmanTree ht[],int n,int weight[]){
    if(n<=1){
        return ;
    }
    for(int i=0;i<m;++i){          //进行初始化操作
        ht[i].lchild=ht[i].rchild=ht[i].parent=-1;
        ht[i].weight=0;
    }
    for(int i=0;i<n;++i){          //权值的传入
        ht[i].weight=weight[i];
    }
    for(int i=n;i<m;++i){
        int min1,min2,lchild,rchild;
        min1=min2=INT_MAX;
        lchild=rchild=-1;
        for(int j=0;j<i;++j){       //寻找最小和次最小节点 
            if(ht[j].parent==-1){
                if(min1>ht[j].weight){
                    min2=min1;
                    rchild=lchild;
                    min1=ht[j].weight;
                    lchild=j;
                }else if(min2>ht[j].weight){
                    min2=ht[j].weight;
                    rchild=j;
                }
            }
        }
        ht[lchild].parent=i;
        ht[rchild].parent=i;
        ht[i].weight=ht[lchild].weight+ht[rchild].weight;
        ht[i].lchild=lchild;
        ht[i].rchild=rchild;
    }
}
void printHuffmanTree(huffmanTree*ht){
    cout<<"node"<<" "<<"parent"<<" "<<"lchild"<<" "<<"rchild"<<" "<<"weight"<<endl;
    for(int i=0;i<m;++i){
            cout<<i<<" "<<ht[i].parent<<" "<<ht[i].lchild<<" "<<ht[i].rchild<<" "<<ht[i].weight<<endl;
    }
}
void test(huffmanTree*ht,int i){
    if(ht[i].lchild!=0&&ht[i].rchild!=0){
        test(ht,ht[i].lchild);
        cout<<ht[i].weight<<endl;
        test(ht,ht[i].rchild);
    }
}
void testHuffmanTree(){
    huffmanTree hfmTree[m];
    int weight[n]={5,10,15,30};
    createHuffmanTree(hfmTree,n,weight);
    printHuffmanTree(hfmTree);
}
int main(){
    testHuffmanTree();
    return 0;
}