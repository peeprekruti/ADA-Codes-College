#include <stdio.h>

#define INF 9999

int main()
{
    int n, i, j, u, v, count;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n], dist[n], visited[n];

    printf("Enter Cost Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(count = 1; count < n; count++)
    {
        int min = INF;
        u = -1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(v = 0; v < n; v++)
        {
            if(!visited[v] && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest Distances from Vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}

Enter number of vertices: 4
Enter Cost Matrix:
0 5 9 0
5 0 2 8
9 2 0 7
0 8 7 0
Enter source vertex: 0

Shortest Distances from Vertex 0:
To 0 = 0
To 1 = 5
To 2 = 7
To 3 = 13
