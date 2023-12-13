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
                printf("The Deleted element is %d",&val);
            // case 3:
            //     val= peek();
            //     if(val != -1)
            //     printf("The First element is %d",&val);    
            // case 4:
            //     display();
            //     break;
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

    if(front == 0 && rear == MAX-1)
    printf("\n Overflow");

    else if(front !=0 && rear == MAX-1)
    {
        rear==0;        
    }
    else if(front ==-1 && rear == -1)
    {
        front=rear=0;        
    }

    else
    //Cases where rear can range from 0 to n and front is n+1
    {
        rear++;   
    }
    queue[rear]=num; 
}

int delete_element()
{   // We don't use front>rear because it comes back to the 0th position
    int val;
    if(front==-1 && rear==-1)
    {
        printf("\n Underflow");
        return -1;
    }
    val=queue[front];

    if(front==rear)
        front=rear=-1;
    else if(front== MAX-1)
        front==0;
    else
        front++;
return val;
}

int peek()
{
    if(front==-1 && rear==-1)
    {
        printf("\n QUEUE IS EMPTY");
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
    if (front ==-1 && rear ==-1)
    printf ("\n QUEUE IS EMPTY");
}
