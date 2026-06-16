#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = -1, rear = -1;
int n;

void enqueue(int item)
{
    if(rear == MAX - 1)
        return;

    if(front == -1)
        front = 0;

    queue[++rear] = item;
}

int dequeue()
{
    int item = queue[front];

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }

    return item;
}

int isEmpty()
{
    return (front == -1);
}

void BFS(int start)
{
    int i, v;

    visited[start] = 1;
    enqueue(start);

    while(!isEmpty())
    {
        v = dequeue();

        printf("%d ", v);

        for(i = 1; i <= n; i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for(i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nBFS Traversal: ");
    BFS(start);

    printf("\n");

    return 0;
}

/*
Sample Input
Enter number of vertices: 5

0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0

Enter starting vertex: 1
Sample Output
BFS Traversal: 1 2 3 4 5
*/
