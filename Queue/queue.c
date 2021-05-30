/**
 * Basic functions of a queue
 * @author TheAndroCoder
 * */

#include<stdio.h>
#define MAX_SIZE 100
int front=-1;
int rear=-1;
int a[MAX_SIZE];

int isEmpty(){
    if(front==rear)return 1;
    return 0;
}
void enqueue(int x){
    if(rear==MAX_SIZE-1){
        printf("Queue Overflow\n");
        return;
    }
    a[++rear]=x;
}
int dequeue(){
    if(isEmpty()){
        printf("Empty Queue\n");
        return -1;
    }
    return a[++front];
}
int main(){
    enqueue(20);
    enqueue(23);
    printf("%d %d\n",dequeue(),dequeue());
    //dequeue();
}

