#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->val = val;
    head->next = NULL;
    return head;
}

struct Queue
{
    struct Node *front;
    struct Node *tail;
};

struct Queue *crateQueue()
{
    struct Queue *temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp->front = NULL;
    temp->tail = NULL;
    return temp;
}

int isEmpty(struct Queue *q);

void enqueue(struct Queue *q, int val)
{
    struct Node *newNode = createNode(val);
    if (isEmpty(q))
    {
        q->front = newNode;
        q->tail = newNode;
        return;
    }
    q->tail->next = newNode;
    q->tail = q->tail->next;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Dequeue not possible");
        return -1;
    }
    if (q->front == q->tail)
    {
        int val = q->front->val;
        q->front = NULL;
        q->tail = NULL;
        return val;
    }
    int val = q->front->val;
    q->front = q->front->next;
    return val;
}

int isEmpty(struct Queue *q)
{
    return (q->front == NULL);
}

// graph part...
#define V 5

void addEdge(int matrix[][V], int src, int dest)
{
    matrix[src][dest] = 1;
    matrix[dest][src] = 1;
}

// BFS
void BFS(int arr[][V], int startNode)
{
    int visited[V] = {0};
    struct Queue *q = crateQueue();
    enqueue(q, startNode);
    visited[startNode] = 1;
    while (!isEmpty(q))
    {
        int curr = dequeue(q);
        printf("%d ", curr);
        for (int i = 0; i < V; i++)
        {
            if(visited[i] == 0 && arr[curr][i] == 1){
                enqueue(q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    free(q);
}


//DFS
void DFS(int arr[][V], int curr, int *visited){
    printf("%d ",curr);
    visited[curr] = 1;
    for(int i = 0; i< V; i++){
        if(visited[i] == 0 && arr[curr][i] == 1){
            DFS(arr, i, visited);
        }
    }
}


//cycle detection in graph...
int isCycle(int arr[][V], int par, int curr, int *visited){
    visited[curr] = 1;
    for(int i = 0; i< V; i++){
        if(arr[curr][i] == 1){
            if(visited[i] == 1 && i != par){
                return 1;
            }
            else if(arr[curr][i] == 1 && visited[i] == 0){
                if(isCycle(arr, curr, i, visited) == 1){
                    return 1;
                }
            }
        }
    }
    return 0;
}


void printGraph(int adjMatrix[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Initialize the adjacency matrix with 0s (no edges)
    int adjMatrix[V][V] = {0};

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    // addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 3);

    printf("Adjacency Matrix for the unweighted graph:\n");
    // printGraph(adjMatrix);
    // BFS(adjMatrix, 0);

    int visited[V] = {0};
    // DFS(adjMatrix, 0, visited);
    printf("%d\n",isCycle(adjMatrix, -1, 0, visited));

    return 0;
}