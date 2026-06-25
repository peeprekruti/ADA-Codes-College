#include <stdio.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};

int main()
{
    int n, i, j;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job job[n], temp;

    for(i = 0; i < n; i++)
    {
        printf("Enter Deadline and Profit of Job %d: ", i + 1);
        scanf("%d %d", &job[i].deadline, &job[i].profit);
        job[i].id = i + 1;
    }

    // Sort jobs by profit (descending)
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(job[j].profit < job[j + 1].profit)
            {
                temp = job[j];
                job[j] = job[j + 1];
                job[j + 1] = temp;
            }
        }
    }

    int maxDeadline = 0;
    for(i = 0; i < n; i++)
    {
        if(job[i].deadline > maxDeadline)
            maxDeadline = job[i].deadline;
    }

    int slot[maxDeadline + 1];
    for(i = 1; i <= maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for(i = 0; i < n; i++)
    {
        for(j = job[i].deadline; j >= 1; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = job[i].id;
                totalProfit += job[i].profit;
                break;
            }
        }
    }

    printf("\nSelected Jobs: ");
    for(i = 1; i <= maxDeadline; i++)
    {
        if(slot[i] != -1)
            printf("J%d ", slot[i]);
    }

    printf("\nMaximum Profit = %d\n", totalProfit);

    return 0;
}

Enter number of jobs: 4
Enter Deadline and Profit of Job 1: 2 100
Enter Deadline and Profit of Job 2: 1 19
Enter Deadline and Profit of Job 3: 2 27
Enter Deadline and Profit of Job 4: 1 25

Selected Jobs: J3 J1
Maximum Profit = 127
