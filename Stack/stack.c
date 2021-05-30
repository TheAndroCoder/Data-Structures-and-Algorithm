/**
 * Stack Basic functions
 * @author TheAndroCoder
 * */
#include<stdio.h>
#define MAX_SIZE 10
int a[MAX_SIZE];
int top=-1;
void printStack(){
    if(top==-1){
        printf("Stack is empty, No elements to print\n");
        return;
    }
    for(int i=0;i<=top;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void push(int data){
    if(top==MAX_SIZE-1){
        printf("Stack overflow\n");
        return;
    }
    a[++top]=data;
}
int pop(){
    if(top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return a[top--];
}
int peek(){
    if(top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return a[top];
}
int isEmpty(){
    return top==-1;
}

// int main(){
//     push(10);
//     push(20);
//     push(10);
//     push(50);
//     push(10);
//     pop();
//     //pop();
//     printStack();
//     return 0;
// }