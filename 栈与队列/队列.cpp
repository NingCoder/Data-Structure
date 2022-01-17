#include <iostream>
using namespace std;
//静态实现栈 这样来写会空出一个 index 不被赋值
const int initLenght=5;
struct Queue{
    int front,rear;
    int arr[initLenght];
};
void initQueue(Queue&queue){
    queue.front=queue.rear=0;
}
int getLength(const Queue&queue){
    return (queue.rear-queue.front+initLenght)%initLenght;
}
int getQueueFront(Queue&queue){
    if(queue.front==queue.rear){
        return -1;
    }
    return queue.arr[queue.front];
}
int getQueueRear(Queue&queue){
    //直接返回 queue.arr[queue.rear] 可能属于越界访问 因为这个数值可能没有被赋值
    return queue.arr[(queue.rear-1)%initLenght];
}
bool deleteQueue(Queue&queue){
    if(queue.rear==queue.front){
        return false;
    }
    int temp=queue.arr[queue.front];
    queue.front=(queue.front+1)%initLenght;
    return true;
}
bool InsertQueue(Queue&queue,int val){
    if((queue.rear+1)%initLenght==queue.front){
        return false;
    }
    queue.arr[queue.rear]=val;
    queue.rear=(queue.rear+1)%initLenght;
    return true;
}
void testQueue(){
    Queue queue;
    initQueue(queue);
    InsertQueue(queue,0);
    cout<<queue.front<<" "<<queue.rear<<endl;
    cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
    InsertQueue(queue,1);
    cout<<queue.front<<" "<<queue.rear<<endl;
    cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
    InsertQueue(queue,2);
    cout<<queue.front<<" "<<queue.rear<<endl;
    cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
    InsertQueue(queue,3);
    cout<<queue.front<<" "<<queue.rear<<endl;
    cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
    InsertQueue(queue,4);
    cout<<queue.front<<" "<<queue.rear<<endl;
    cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
    // deleteQueue(queue);
    // cout<<queue.front<<" "<<queue.rear<<endl;
    // cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
    // deleteQueue(queue);
    // cout<<queue.front<<" "<<queue.rear<<endl;
    // cout<<"Element Queue Front:"<<getQueueFront(queue)<<" Element Queue Rear:"<<getQueueRear(queue)<<endl;
}
int main(){
    testQueue();
    return 0;
}