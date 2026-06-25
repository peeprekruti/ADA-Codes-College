#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, i, j;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    int profit[n + 1], weight[n + 1];

    for(i = 1; i <= n; i++)
    {
        printf("Enter Profit and Weight of Object %d: ", i);
        scanf("%d %d", &profit[i], &weight[i]);
    }

    int capacity;
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    int K[n + 1][capacity + 1];

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= capacity; j++)
        {
            if(i == 0 || j == 0)
                K[i][j] = 0;
            else if(weight[i] <= j)
                K[i][j] = max(profit[i] + K[i - 1][j - weight[i]],
                              K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    printf("\nMaximum Profit = %d\n", K[n][capacity]);

    return 0;
}
