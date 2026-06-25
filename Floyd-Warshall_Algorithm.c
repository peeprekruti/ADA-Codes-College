#include <stdio.h>

#define MAX 20
#define INF 9999

int main()
{
    int n;
    int A[MAX][MAX];
    int i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    printf("(Use %d for no edge)\n", INF);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    /* Floyd-Warshall Algorithm */
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }

    printf("\nAll-Pairs Shortest Path Matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(A[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}



Sample Input
4

0 5 9999 10
9999 0 3 9999
9999 9999 0 1
9999 9999 9999 0
Sample Output
All-Pairs Shortest Path Matrix:

0   5   8   9
INF 0   3   4
INF INF 0   1
INF INF INF 0


