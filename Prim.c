#include <stdio.h>

#define INF 9999

int main()
{
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter Cost Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int visited[n];
    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    int edges = 0, minCost = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1)
    {
        int min = INF, a = -1, b = -1;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", a, b, min);

        visited[b] = 1;
        minCost += min;
        edges++;
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}

Enter number of vertices: 3
Enter Cost Matrix:
0 2 3
2 0 1
3 1 0

Edges in Minimum Spanning Tree:
0 - 1 : 2
1 - 2 : 1

Minimum Cost = 3
