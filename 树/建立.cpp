#include <stdio.h>

//使用数组进行建立树 使用index=0的位置
void creatBtree01(int *bTree,int*node,int len){
    bTree[0]=node[0];
    for(int i=1;i<len;++i){
        int level=0;
        while(bTree[level]!=0){
            if(node[i]<bTree[level]){
                level=2*level+1;
            }else{
                level=2*level+2;
            }
        }
        bTree[level]=node[i];
    }
}
//使用数组进行建立树 不使用index=0的位置 相应的 node也不使用index=0的位置
void creatBtree02(int *bTree,int*node,int len){
    bTree[1]=node[1];
    for(int i=2;i<len;++i){
        int level=1;
        while(bTree[level]!=0){
            if(node[i]<bTree[level]){
                level=2*level;
            }
            else{
                level=2*level+1;
            }
        }bTree[level]=node[i];
    }
}
//打印输出树 length长度表示树有效长度 flag为了区分index=0 位置的使用
void printBtree(int *bTree,int len,int length,bool flag){
    int cnt=0;
    for(int i=0;i<len;++i){
        printf("%d ",bTree[i]);
        if(bTree[i]!=0){
            ++cnt;
            if(flag){
                if(cnt==length){
                    printf("\n");
                    return ;
                }
            }else{
                if(cnt==length-1){
                    printf("\n");
                    return ;
                }
            }
        }
    }
    printf("\n");
}
void testBtree(){
    const int sz01=7;
    int node01[sz01]={3,1,2,6,4,5,7};
    //理论上的最大长2^n-1
    int maxSz01=2*sz01*sz01-1;
    int bTree01[maxSz01]={};
    creatBtree01(bTree01,node01,sz01);
    printBtree(bTree01,maxSz01,sz01,true);

    const int sz02=8;
    int node02[sz02]={0,3,1,2,6,4,5,7};
    //理论上的最大长2^n-1 因为会多出来一个0 所以直接是2^n
    int maxSz02=2*(sz02-1)*(sz02-1);
    int bTree02[maxSz02]={};
    creatBtree02(bTree02,node02,sz02);
    printBtree(bTree02,maxSz02,sz02,false);
}
int main(){
    testBtree();
    printf("hello word!");
}