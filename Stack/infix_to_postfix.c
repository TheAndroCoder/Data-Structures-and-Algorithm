/**
 * Infix to postfix conversion
 * @author TheAndroCoder
 * */

#include<stdio.h>
//*** Character Stack ***//
#define MAX_SIZE 100
char a[MAX_SIZE];
int top=-1;

void push(int c){
    if(top==MAX_SIZE-1){
        return;
    }
    a[++top]=c;
}
char pop(){
    if(top==-1){
        return '\0';
    }
    return a[top--];
}
char peek(){
    if(top==-1){
        return '\0';
    }
    return a[top];
}
int isEmpty(){
    return top==-1;
}


//***********************//
int getPrecedence(char c){
    switch(c){
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':return 3;
        default : return -1;
    }
}
int isOperand(char c){
    return (c>='a' && c<='z');
}
int main(){
    char infix[]="a+b*(c^d-e)^(f+g*h)-i";
    int len = (int)sizeof(infix)/sizeof(char);
    for(int i=0;i<len-1;i++){
        char ch = infix[i];
        if(isOperand(ch)){
            printf("%c",ch);
        }else if(ch=='('){
            push(ch);
        }else if(ch==')'){
                while(!isEmpty() && peek()!='('){
                    printf("%c",pop());
                }
                pop();
        }else{
                // operator found
                //printf("ch=%c\n",ch);
                while(!isEmpty() && getPrecedence(ch)<=getPrecedence(peek())){
                    printf("%c",pop());
                }
                push(ch);
            }
    }
    while(!isEmpty())printf("%c",pop());
    printf("\n");
}