#include<stdio.h>
#include<string.h>

int stk[10];
int pop();
int top = -1;
void push(int val);
int get_type(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else 
        return 0;
}
int pop()
{
    return(stk[top--]);
}
 void push(int val)
 {
 stk[++top] = val;
 }
 
 int main()
 {
    char prefix[10];
    int len, val, i, opr1, opr2, res;
     printf("\n Enter the prefix expression : ");
    fgets(prefix, sizeof(prefix),stdin);
    len = strlen(prefix);
    
    for(i=len-1;i>=0;i--)
    {
        switch(get_type(prefix[i]))
        {
            case 0:
                val = prefix[i]-'0';
                push(val);
                break;
            case 1:
                opr1=pop();
                opr2=pop();
                switch(prefix[i])
                {
                 case '+': 
                 res = opr1 + opr2;
                 break;
                 case '-': 
                    res = opr1 - opr2;
                    break;
                 case '*': 
                    res = opr1 * opr2;
                    break;
                 case '/': 
                    res = opr1 / opr2;
                    break;
                 }
                push(res);
                break;
        }
        
         //Come out of the loop as soon as the operation is done 
    }
            printf("\n RESULT = %d",stk[0]);
            return 0;
 }
