#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
int top = -1;
int stk[MAX];
char pop();
void push(char);

void main()
{
char exp[MAX],temp;
int i, flag=1;
// Now in this algorithm we keep push the openening stack and
// when we find a closing stack then we pop the last element and check 
// wheter is it the closing bracket of of the popped elemen
printf("Enter an expression : ");
fgets(exp, sizeof(exp), stdin);
for(i=0;i<strlen(exp);i++)
{
    push(exp[i]);
}
printf("\n");
for(i=0;i<strlen(exp);i++)
{
    printf("%d"&exp[i]);
}
}
void push(char item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stk[++top] = item;
    }
}