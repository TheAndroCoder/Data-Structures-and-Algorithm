/**
 * Postfix Evaluation
 * @author TheAndroCoder
 * */

#include "stack.c"

int main(){
    char postfix[]="53+62/*35*+";
    int len = (int)sizeof(postfix)/sizeof(char);
    for(int i=0;i<len-1;i++){
        char ch = postfix[i];
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            int a=pop();
            int b=pop();
            if(ch=='+')push(b+a);
            else if(ch=='-')push(b-a);
            else if(ch=='*')push(b*a);
            else push(b/a);
        }else{
            push(ch-'0');
        }
    }
    printf("%d\n",pop());
    return 0;
}