#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

int top = -1;
char stk[MAX];

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0'; // Return a null character to indicate an error
    }
    return stk[top--];
}

void push(char item) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else 
        stk[++top] = item;
}

int main() {
    char exp[MAX];
    int i, flag = 1;

    printf("Enter an expression : ");
    fgets(exp, sizeof(exp), stdin);

    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            char popped = pop();
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == ']' && popped != '[') ||
                (exp[i] == '}' && popped != '{')) {
                flag = 0;
                break;
            }
        }
    }
    //Important to remeber function
    if (top != -1) {
        flag = 0; // Unmatched opening brackets
    }

    if (flag) {
        printf("Expression is balanced.\n");
    } else {
        printf("Expression is not balanced.\n");
    }

    return 0;
}
