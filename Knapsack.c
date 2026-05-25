#include <stdio.h>

// Structure for Object
struct KnapsackObject
{
    int profit;
    int weight;
    float ratio;
};

int main()
{
    int i, j, n;
    printf("Enter number of objects: ");
    scanf("%d", &n);
    struct KnapsackObject obj[n], temp;
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Profit and Weight of Object %d: ",i + 1);
        scanf("%d %d", &obj[i].profit,&obj[i].weight);
        // Calculate P/W ratio
        obj[i].ratio = (float)obj[i].profit / obj[i].weight;
    }

    int capacity;
    printf("\nEnter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort objects according to decreasing P/W ratio (Bubble Sort)
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(obj[j].ratio < obj[j + 1].ratio)
            {
                temp = obj[j];
                obj[j] = obj[j + 1];
                obj[j + 1] = temp;
            }
        }
    }

    // Display objects after sorting
    printf("\nObjects after sorting by P/W ratio:\n");
    printf("\nObject\tProfit\tWeight\tRatio\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%.2f\n",
               i + 1,
               obj[i].profit,
               obj[i].weight,
               obj[i].ratio);
    }

    int U = capacity;
    float totalProfit = 0.0;
    float x[n];
   
    for(i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }
    
    for(i = 0; i < n; i++)
    {
        if(U < obj[i].weight)
        {
            break;
        }
        x[i] = 1.0;
        U = U - obj[i].weight;
        totalProfit = totalProfit + obj[i].profit;
    }
    if(i < n)
    {
        x[i] = (float)U / obj[i].weight;
        totalProfit = totalProfit + (x[i] * obj[i].profit);
    }
    printf("\nSelected Objects:\n");
    printf("\nObject\tProfit\tWeight\tFraction Selected\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%.2f\n",
               i + 1,
               obj[i].profit,
               obj[i].weight,
               x[i]);
    }
    printf("\nMaximum Profit = %.2f\n",totalProfit);

    return 0;
}
