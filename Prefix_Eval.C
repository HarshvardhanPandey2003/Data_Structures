#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define MAX 30

int st[MAX];
int top = -1;

void push(int n){
    st[++top] = n;
}

int pop(){
    return st[top--];
}

void main(){
    char s[100];
    printf("Enter prefix expression : ");
    gets(s);
    for(int i=strlen(s)-1;i>=0;i--){
        if(isdigit(s[i])){
            int num = (int)(s[i]) - 48;
            // printf("%d\n",num);
            push(num);
        }
        else{
            char exp = s[i];
            int num1 = pop();
            int num2 = pop();
            // printf("%d %d %c ",num1,num2,exp);
            if(exp == '+'){
                push(num2+num1);
            }
            else if(exp == '-'){
                push(num1-num2);
            }
            else if(exp == '*'){
                push(num2*num1);
            }
            else if(exp == '/'){
                push(num1/num2);
            }
            
        }
    }
    printf("%d\n",st[top]);
    
}
