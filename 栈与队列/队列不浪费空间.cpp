#include <iostream>
using namespace std;
//静态实现栈 这样来写会空出一个 index 不被赋值
const int initLenght=5;
struct Queue{
    int front,rear,size;
    int arr[initLenght];
};
void initQueue(Queue&queue){
    queue.front=queue.rear=queue.size=0;
}
int getLength(const Queue&queue){
    return queue.size;
}
int getQueueFront(Queue&queue){
    if(queue.size==0){
        return -1;
    }
    return queue.arr[queue.front];
}
int getQueueRear(const Queue&queue){
    //直接返回 queue.arr[queue.rear] 可能属于越界访问 因为这个数值可能没有被赋值
    if(queue.rear==0){
        return queue.arr[initLenght-1];
    }
    return queue.arr[(queue.rear-1)%initLenght];
}
int  deleteQueue(Queue&queue){
    if(queue.size==0){
        return -1;
    }
    --queue.size;
    int temp=queue.arr[queue.front];
    queue.front=(queue.front+1)%initLenght;
    return temp;
}
bool InsertQueue(Queue&queue,int val){
    if(queue.size==initLenght){
        return false;
    }
    ++queue.size;
    queue.arr[queue.rear]=val;
    queue.rear=(queue.rear+1)%initLenght;
    return true;
}
void testQueue(){
    Queue queue;
    initQueue(queue);
    for(int i=0;i<5;++i){
        InsertQueue(queue,i);
        cout<<queue.front<<" "<<queue.rear<<endl;
        cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
    }
    //不会再去添加
    InsertQueue(queue,5);
    cout<<queue.front<<" "<<queue.rear<<endl;
    cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
    for(int i=0;i<3;++i){
        deleteQueue(queue);
        cout<<queue.front<<" "<<queue.rear<<endl;
        cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
    }
}
int main(){
    testQueue();
    return 0;
}