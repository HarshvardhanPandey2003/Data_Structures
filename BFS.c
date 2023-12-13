#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
struct Queue{
    int front;
    int rear;
    int items[MAX_SIZE];
};

int isEmpty(struct Queue* q)
{
    return q->front==-1;
}
int isFull(struct Queue *q)
{
    return q->front==MAX_SIZE-1;
}

void initialize(struct Queue* q)
{
    q->front=-1;
    q->rear=-1;
}

int dequeue(struct Queue *q)
{
    int item;
    if(isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else
    {
        item=q->items[q->front];
        q->front++;
        if(q->front > q->rear)
        {   initialize(q);   }
    }
    return item;
}

void enqueue(struct Queue *q,int value)
{
    int item;
    if(isFull(q))
    {
        printf("Queue is Full.\n");
    }
    else
    {
        if (isEmpty(q))
            q->front = 0;
        q->items[++q->rear]=value;
    }
}

int BFS(int graph[][MAX_SIZE],int vertices,int start)
{
    struct Queue q;
    int currentindex=0,i;
    initialize(&q);

    int is_visited[MAX_SIZE]={0};

    printf("\nBreadth First Search Algorithm :");
    while(!isEmpty(&q))
    {
        currentindex=dequeue(&q);
        is_visited[currentindex]=1;
        printf("%d ",currentindex);

        for(i=0;i<vertices;++i)
        {
                if(is_visited[i] == 0 && graph[currentindex][i]==1)
                {
                        enqueue(&q,i);
                        is_visited[i]=1;    
                }
        }
    }
printf("\n");

}

int main()
{
    int vertices,i,j;
    int graph[MAX_SIZE][MAX_SIZE]={0};

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; ++i) {
        for (j = 0; j < vertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(graph, vertices, startVertex);

    return 0;
}