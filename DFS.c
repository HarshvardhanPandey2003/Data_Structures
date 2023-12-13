#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack{
    int items[MAX_SIZE];
    int top;
};
int isEmpty(struct Stack* s)
{
    return s->top == -1;
}

int isFull(struct Stack* s)
{
    return s->top == MAX_SIZE-1;
}
void initializeStack(struct Stack* s){
    s->top = -1;
}
void push(struct Stack *s, int value)
{
    if(isFull(s))
    {
        printf("Stackoverflow cannot push");
    }
    else
    {
        if(isEmpty(s))
        {
            s->top=0;
        }
        else
        s->items[++s->top] = value;
        
    }
}
int pop(struct Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack is Empty");
        return -1;
    }
    else
    {
        return s->items[s->top--];
    }
}

void DFS(int graph[][MAX_SIZE],int vertices,int start)
{
    struct Stack s;
    initializeStack(&s);
    // First take the start elemnt and psuh it in the Stcak
    // And Mark its visited = 1
    
    int visited[MAX_SIZE] = {0};
    printf("Depth-First Search starting from vertex %d:\n", start);
    
    push(&s,start);
    visited[start]=1;
    
    while(!isEmpty(&s)){
        int currentvector=pop(&s);
        printf("%d",currentvector);
        
        for(int i=vertices-1;i>=0;--i)
        {
            if(!visited[i] && graph[currentvector][i]==1)
            {
                push(&s,i);
                visited[i]=1;
            }
        }
    }
    
    // Then those iterations which are 1 
}
int main() {
    int vertices,edges,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_SIZE][MAX_SIZE] = {0};
    
    printf("Enter the adjecent MAtrix :\n");
    
    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int startVertex;
    printf("Enter strating of DFS : ");
    scanf("%d",&startVertex);
    
    DFS(graph,vertices,startVertex);  
    return 0;
}