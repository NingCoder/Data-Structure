#include <iostream>
using namespace std;

const int initLenght=10;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
public:
    ListNode*initLinkList();
    bool insertLinkList(int index,int val,ListNode*&head);
    bool deleteLinkList(int index,ListNode*&head);
    int getLength(ListNode*head);
    bool isInLinkList(ListNode*head,int val);
    int  getIndex(ListNode*head,int val);
    bool isEmpty(ListNode*head);
    void printLinkList(ListNode*head);
};
ListNode*ListNode::initLinkList(){
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
bool ListNode::insertLinkList(int index,int val,ListNode*&head){
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
bool ListNode::deleteLinkList(int index,ListNode*&head){
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
int ListNode::getLength(ListNode*head){
    int lenght=0;
    ListNode*node=head;
    while(node){
        ++lenght;
        node=node->next;
    }return lenght;
}
bool ListNode::isInLinkList(ListNode*head,int val){
    ListNode*node=head;
    while(node){
        if(val==node->val){
            return true;
        }
        node=node->next;
    }return false;
}
int  ListNode::getIndex(ListNode*head,int val){
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
bool ListNode::isEmpty(ListNode*head){
    return head==nullptr;
}
void ListNode::printLinkList(ListNode*head){
    head=head->next;
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }cout<<endl;
}
int main(){
    ListNode Node;
    ListNode *node=Node.initLinkList();
    Node.printLinkList(node);
    Node.insertLinkList(0,-1,node);
    Node.printLinkList(node);

    cout<<Node.isEmpty(node)<<endl;
    cout<<Node.getLength(node)<<endl;
    cout<<Node.getIndex(node,12)<<endl;
    cout<<Node.isInLinkList(node,12)<<endl;
    return 0;
}