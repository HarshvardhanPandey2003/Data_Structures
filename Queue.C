// Online C compiler to run C program online
// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];

int front=-1,rear=-1;

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
    int a,val,c;
    do{
        printf("\nOperations to be performed :");
        printf("\n1-Insert \n2-Delete \n3-Peek \n4-Display \n5-Exit");
        printf("\nSelect the option :");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
                insert();
                break;
            case 2:
                val= delete_element();
                if(val != -1)
                printf("\n The number deleted is : %d", val);
                break;
            case 3:
                val = peek();
                if (val != -1)
                printf("\n The first value in queue is : %d", val);
                break;
            case 4:
                display();
                break;
        }
    }while(c != 5);

    getchar();
    return 0;
}

void insert()
{
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);

    if(rear == MAX-1)
    printf("\n Overflow");

    else if(front ==-1 && rear ==-1)
    front=rear=0;

    else
    rear++;    

    queue[rear]=num;
}

int delete_element()
{
    int val;

    if(front==-1 || front>rear)    
    {   printf("Queue is Underflow");
        return -1;   
    }

    else 
    {
        val=queue[front];
        front++;
        if(front>rear)
            front=rear=-1;
        return val; 
    }
}

int peek()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    int i;
    printf("\n");
    if(front==-1 || front>rear)
        printf("The Queue is Empty");
    else
    {
        printf("The Elements are :");
        for(int i=front;i<=rear;i++)
        {
            printf("\n%d",queue[i]);
        }
    }
}
    


