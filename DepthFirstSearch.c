#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for(i = 1; i <= n; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
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

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}

Enter number of vertices: 3

Enter adjacency matrix:
0 1 1
1 0 0
1 0 0

Enter starting vertex: 1

DFS Traversal: 1 2 3
