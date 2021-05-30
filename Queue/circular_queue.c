/**
 * Circular Queue
 * @author TheAndroCoder
 * */

#include<stdio.h>
#define MAX_SIZE 5
int a[MAX_SIZE];
int front=-1;
int rear=-1;

int isEmpty(){
    return rear==front;
}
int isFull(){
    return (rear==front-1) ||(front==-1 && rear==MAX_SIZE-1);
}
void enqueue(int x){
    if(isFull()){
        printf("Queue Full, cannot enqueue %d\n",x);
        return;
    }
    rear=(rear+1)%MAX_SIZE;
    a[rear]=x;
}
int dequeue(){
    if(isEmpty()){
        printf("Queue Empty\n");
        return -1;
    }
    front=(front+1)%MAX_SIZE;
    return a[front];
}
void printQueue(){
    int i=front==-1?0:front;
    while((front==-1 && i!=MAX_SIZE) && (i!=rear-1)){
        printf("%d\t",a[i]);
        i=(i+1)%MAX_SIZE;
    }
}
// WRONG IMPL : LinkedList better
int main(){
    // enqueue loop
    for(int i=0;i<5;i++){
        enqueue(i); 
        //  if(i%2!=0){
        //      int x=dequeue();
        //      printf("Dequeued %d\n",x);
        //  }
    }
    printQueue();
    return 0;
}