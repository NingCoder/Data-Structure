#include <iostream>
using namespace std;
//静态实现栈
const int initLenght=10;
struct Stack {
    int top;
    int arr[initLenght];
};
void initStack(Stack&stk){
    stk.top=0;
}
int getTop(const Stack&stk){
    return stk.top;
}
int getStackTop(Stack&stk){
    return stk.arr[stk.top-1];
}
int deleteStackTop(Stack&stk){
    if(stk.top==0){
        return -1;
    }
    return stk.arr[--stk.top];
}
bool InsertStackTop(Stack&stk,int val){
    if(stk.top>=initLenght){
        return false;
    }
    stk.arr[stk.top++]=val;
    return true;
}
void testStack(){
    Stack stk;
    initStack(stk);
    InsertStackTop(stk,1);
    InsertStackTop(stk,2);
    InsertStackTop(stk,3);
    cout<<getTop(stk)<<endl;
    cout<<getStackTop(stk)<<endl;
    cout<<deleteStackTop(stk)<<endl;
    cout<<getTop(stk)<<endl;
}
int main(){
    testStack();
    return 0;
}