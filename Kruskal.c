#include <stdio.h>

#define MAX 10

struct Edge
{
    int u, v, w;
};

int parent[MAX];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n, e, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Edge edge[e], temp;

    for(i = 0; i < e; i++)
    {
        printf("Enter source, destination and weight: ");
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }

    // Sort edges by weight
    for(i = 0; i < e - 1; i++)
    {
        for(j = 0; j < e - i - 1; j++)
        {
            if(edge[j].w > edge[j + 1].w)
            {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
        parent[i] = i;

    int minCost = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for(i = 0; i < e; i++)
    {
        int a = find(edge[i].u);
        int b = find(edge[i].v);

        if(a != b)
        {
            printf("%d - %d : %d\n", edge[i].u, edge[i].v, edge[i].w);
            minCost += edge[i].w;
            unionSet(a, b);
        }
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}

Enter number of vertices: 3
Enter number of edges: 3

Enter source, destination and weight:
0 1 2
0 2 3
1 2 1

Edges in Minimum Spanning Tree:
1 - 2 : 1
0 - 1 : 2

Minimum Cost = 3
