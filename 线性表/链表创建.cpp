#include <iostream>
using namespace std;

const int initLenght=10;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
ListNode*initLinkList01(){
    //带头接点 尾插法
    ListNode *head=new ListNode(-1),*tail=nullptr;
    for(int i=0;i<10;++i){
        if(head->next==nullptr){
            head->next=tail=new ListNode(i);
        }else{
            tail->next=new ListNode(i);
            tail=tail->next;
        }
    }
    return head;
}
ListNode*initLinkList02(){
    //带头接点 头插法
    ListNode *head=new ListNode(-1),*tail=nullptr;
    for(int i=0;i<10;++i){
        tail=new ListNode(i);
        tail->next=head->next;
        head->next=tail;
    }
    return head;
}
ListNode*initLinkList03(){
    //不带头接点 尾插法
    ListNode *head=nullptr,*tail=nullptr;
    for(int i=0;i<10;++i){
        if(head==nullptr){
            head=tail=new ListNode(i);
        }else{
            tail->next=new ListNode(i);
            tail=tail->next;
        }
    }
    return head;
}
ListNode*initLinkList04(){
    //不带头接点 头插法
    ListNode *head=nullptr,*tail=nullptr;
    for(int i=0;i<10;++i){
        tail=new ListNode(i);
        tail->next=head;
        head=tail;
    }
    return head;
}
void printLinkList01(ListNode*head){
    head=head->next;
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }cout<<endl;
}
void printLinkList02(ListNode*head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }cout<<endl;
}
int main(){
    ListNode *head01=initLinkList01();
    printLinkList01(head01);
    ListNode *head02=initLinkList02();
    printLinkList01(head02);
    ListNode *head03=initLinkList03();
    printLinkList02(head03);
    ListNode *head04=initLinkList04();
    printLinkList02(head04);
    return 0;
}