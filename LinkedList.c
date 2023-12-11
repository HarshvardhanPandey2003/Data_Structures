// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node *create_ll(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_before(struct node *start);
void display(struct node *start);
struct node{
    int data;
    struct node *next;
};

void main()
{
    int c;
    struct node *start;
    do
    {
    
    printf("\nEnter Choice : ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            start=create_ll(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            insert_after(start);
            break;
        case 13:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Enter a correct value ");
    }
    }while(c!=13);
}

struct node *insert_after(struct node *start)
{
    int value,num;
    struct node *ptr,*new_node,*preptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value : ");
    scanf("%d",&value);
    
    printf("Enter value after which you want to add the number :");
    scanf("%d",&num);
    
    ptr=start;
    preptr=start;
    new_node->data = value;
    new_node->next = NULL;
    //We use preptr->data because we have value and not pointer
    // So we cant use '-> next'
    while(preptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    new_node->next=ptr;
    preptr->next=new_node;
    
    return start;
}
struct node *create_ll(struct node *start)
{
    int value;
    struct node *ptr,*new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value : ");
    scanf("%d",&value);
    
    new_node->data = value;
    new_node->next = NULL;
    
    if(start==NULL)
        start=new_node;
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->next=NULL;
    }
    printf("\nNew Element has been added : %d ",new_node->data);
    return start;
}
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    printf("So the list is :\n");
    while(ptr!=NULL)
    {
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
}