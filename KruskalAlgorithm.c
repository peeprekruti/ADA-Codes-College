#include <stdio.h>

#define MAX 20
#define INF 9999

typedef struct
{
    int u;
    int v;
    int cost;
} Edge;

int parent[MAX];

/* Find operation */
int Find(int x)
{
    while(parent[x] > 0)
        x = parent[x];

    return x;
}

/* Union operation */
void Union(int i, int j)
{
    parent[j] = i;
}

int main()
{
    int n, i, j;
    int cost[MAX][MAX];
    Edge edge[MAX * MAX];
    Edge mst[MAX];
    int edgeCount = 0;
    int mstEdges = 0;
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Cost Adjacency Matrix:\n");
    printf("(Enter %d for no edge)\n", INF);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    /* Create edge list */
    for(i = 1; i <= n; i++)
    {
        for(j = i + 1; j <= n; j++)
        {
            if(cost[i][j] != INF)
            {
                edge[edgeCount].u = i;
                edge[edgeCount].v = j;
                edge[edgeCount].cost = cost[i][j];
                edgeCount++;
            }
        }
    }

    /* Sort edges by ascending cost (Bubble Sort) */
    for(i = 0; i < edgeCount - 1; i++)
    {
        for(j = 0; j < edgeCount - i - 1; j++)
        {
            if(edge[j].cost > edge[j + 1].cost)
            {
                Edge temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }

    /* Initialize parent array */
    for(i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }

    /* Kruskal Algorithm */
    for(i = 0; i < edgeCount && mstEdges < n - 1; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;

        int jRoot = Find(u);
        int kRoot = Find(v);

        if(jRoot != kRoot)
        {
            mst[mstEdges] = edge[i];
            mstEdges++;

            minCost += edge[i].cost;

            Union(jRoot, kRoot);
        }
    }

    if(mstEdges != n - 1)
    {
        printf("\nNo Spanning Tree Exists\n");
    }
    else
    {
        printf("\nEdges in Minimum Spanning Tree:\n");

        for(i = 0; i < mstEdges; i++)
        {
            printf("%d -> %d  Cost = %d\n",
                   mst[i].u,
                   mst[i].v,
                   mst[i].cost);
        }

        printf("\nMinimum Cost = %d\n", minCost);
    }

    return 0;
}

/*
Sample Input
7

9999 25 9999 9999 9999 5    9999
25   9999 12   9999 9999 9999 10
9999 12   9999 8    9999 9999 9999
9999 9999 8    9999 16   9999 14
9999 9999 9999 16   9999 20   18
5    9999 9999 9999 20   9999 9999
9999 10   9999 14   18   9999 9999
Sample Output
Edges in Minimum Spanning Tree:
1 -> 6  Cost = 5
3 -> 4  Cost = 8
2 -> 7  Cost = 10
2 -> 3  Cost = 12
4 -> 5  Cost = 16
1 -> 2  Cost = 25

Minimum Cost = 76
*
