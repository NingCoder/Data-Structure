#include <iostream>
using namespace std;
//链实现栈
const int initLenght=10;
struct Stack {
    int length,val;
    Stack*next;
    Stack() : val(0), next(nullptr) {}
    Stack(int x) : val(x), next(nullptr) {}
    Stack(int x, Stack *next) : val(x), next(next) {}
};
Stack*initStack(){
    Stack*stk=new Stack(-1);
    stk->length=0;
    return stk;
}
int getLength(Stack*stk){
    return stk->length;
}
int getStackTop(Stack*stk){
    if(stk->next!=nullptr){
        return stk->next->val;
    }
    return -1;
}
int deleteStackTop(Stack*&stk){
    if(stk->length==-1||stk->next==nullptr){
        return -1;
    }
    --stk->length;
    Stack*node=stk->next;
    int res=node->val;
    stk->next=node->next;
    delete node;
    return res;
}
void InsertStackTop(Stack*&stk,int val){
    Stack *node=new Stack(val);
    node->next=stk->next;
    stk->next=node;
    node=stk->next;
    ++stk->length;
}
void testStack(){
    Stack*stk=initStack();
    cout<<getStackTop(stk)<<endl;
    InsertStackTop(stk,0);
    InsertStackTop(stk,1);
    InsertStackTop(stk,2);
    cout<<getStackTop(stk)<<" "<<getLength(stk)<<endl;
    cout<<deleteStackTop(stk)<<endl;
    cout<<getStackTop(stk)<<" "<<getLength(stk)<<endl;
    cout<<deleteStackTop(stk)<<endl;
    cout<<getStackTop(stk)<<" "<<getLength(stk)<<endl;
    cout<<deleteStackTop(stk)<<endl;
    cout<<getStackTop(stk)<<" "<<getLength(stk)<<endl;
}
int main(){
    testStack();
    return 0;
}