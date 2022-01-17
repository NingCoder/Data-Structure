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
ListNode*initLinkList(){
    //带头接点
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
bool insertLinkList(int index,int val,ListNode*&head){
    int lenght=0;
    ListNode*node=head;
    while(lenght!=index&&node){
        ++lenght;
        node=node->next;
    }
    if(node==nullptr){
        return false;
    }
    ListNode *newNode=new ListNode(val);
    newNode->next=node->next;  
    node->next=newNode;
    return true;
}
bool deleteLinkList(int index,ListNode*&head){
    int lenght=0;
    ListNode*node=head;
    if(index<0){
        return false;
    }
    while(lenght!=index&&node!=nullptr){
        ++lenght;
        node=node->next;
    }
    if(node==nullptr||node->next==nullptr){
        return false;
    }
    node->next=node->next->next;
    return true;
}
int getLength(ListNode*head){
    int lenght=0;
    ListNode*node=head;
    while(node){
        ++lenght;
        node=node->next;
    }return lenght;
}
bool isInLinkList(ListNode*head,int val){
    ListNode*node=head;
    while(node){
        if(val==node->val){
            return true;
        }
        node=node->next;
    }return false;
}
int  getIndex(ListNode*head,int val){
    ListNode*node=head;
    int lenght=0;
    while(node){

        if(val==node->val){
            return lenght;
        }
        node=node->next;
        ++lenght;
    }return -1;
}
bool isEmpty(ListNode*head){
    return head==nullptr;
}
int getLength(ListNode*head){
    int lenght=0;
    ListNode*node=head;
    while(node){
        ++lenght;
        node=node->next;
    }return lenght;
}
void printLinkList(ListNode*head){
    head=head->next;
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }cout<<endl;
}
int main(){
    ListNode *head=initLinkList();
    printLinkList(head);
    // insertLinkList(0,12,head);
    // printLinkList(head);
    // insertLinkList(11,12,head);
    // printLinkList(head);
    // deleteLinkList(10,head);
    // printLinkList(head); 
    return 0;
}