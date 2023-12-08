#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert_node(struct Node* root,int value)
{
    if(root==NULL)
    {   return create_node(value); }
    else
    {
        if(value<root->data)
        {
            root->left = insert_node(root->left,value);
        }
        else if(value>root->data)
        {
            root->right = insert_node(root->right,value);
        }
    }
    return root;
}

struct Node* search_node(struct Node* root,int key)
{
    if(root==NULL || root->data == key)
    {
        return root;
    }
    
    else  
    {
        if(key<root->data)
        {
            search_node(root->left,key);
        }
        else if(key>root->data)
        {
            search_node(root->right,key);
        }
    }
        
    
}

void transversal(struct Node* root)
{
    if(root != NULL)
    {
        transversal(root->left);
        printf("%d ",root->data);
        transversal(root->right);
    
    }
    
}

int main()
{
    struct Node* root=NULL;
    
    root= create_node(10);
    insert_node(root, 20);
    insert_node(root, 30);
    insert_node(root, 40);
    insert_node(root, 50);
    
    printf("The inorder transversal is : ");
    transversal(root);
    int key;
    printf("\n Enter a value to search in the BST: ");
    scanf("%d", &key);
    
    struct Node* result = search_node(root , key);
    
    if(result==NULL)
    {
        printf("Value cannot be found in the tree");
    }
    else
    {
        printf("Value %d is found in the tree",key);
    }
    return 0;
}