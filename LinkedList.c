// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node *create_ll(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_node(struct node *start);
struct node *sort_list(struct node *start);
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
            start=insert_after(start);
            break;
        case 4:
            start=delete_node(start);
            break;
        case 5:
            start=sort_list(start);
            break;
        case 13:
            printf("Exiting the program.\n");
            break;
        default:
            printf("\nEnter a correct value ");
    }
    }while(c!=13);
}
struct node *delete_node(struct node *start)
{
    int num;
    struct node *ptr,*preptr;
    printf("\nEnter value of which you want to remove the number :");
    scanf("%d",&num);
    
    if(start==NULL)
    {
        start=delete_beg(start);
        return start;
    }
    else{
        ptr=start;
        while(ptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start -> next;
    free(ptr);
    return start;
}
struct node *insert_after(struct node *start)
{
    int value,num;
    struct node *ptr,*new_node,*preptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value : ");
    scanf("%d",&value);
    
    printf("\nEnter value after which you want to add the number :");
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

struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while(ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data < ptr2->data)
            {
                temp = ptr1 -> data;
                ptr1 -> data = ptr2 -> data;
                ptr2 -> data = temp;
            }
            //Iterate ptr2
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }

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