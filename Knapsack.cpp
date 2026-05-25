#include<iostream>
using namespace std;

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

    cout << "Enter number of objects: ";
    cin >> n;

    KnapsackObject obj[n], temp;

    // Input Objects
    for(i = 0; i < n; i++)
    {
        cout << "\nEnter Profit and Weight of Object "
             << i + 1 << ": ";

        cin >> obj[i].profit >> obj[i].weight;

        // Calculate Profit/Weight Ratio
        obj[i].ratio =
        (float)obj[i].profit / obj[i].weight;
    }

    int capacity;

    cout << "\nEnter capacity of knapsack: ";
    cin >> capacity;

    // Sorting according to decreasing ratio
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

    // Display sorted objects
    cout << "\nObjects after sorting by P/W ratio:\n";

    cout << "\nObject\tProfit\tWeight\tRatio\n";

    for(i = 0; i < n; i++)
    {
        cout << i + 1 << "\t"
             << obj[i].profit << "\t"
             << obj[i].weight << "\t"
             << obj[i].ratio << endl;
    }

    int U = capacity;

    float totalProfit = 0.0;

    float x[n];

    // Initialize selection array
    for(i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    // Select objects
    for(i = 0; i < n; i++)
    {
        if(U < obj[i].weight)
        {
            break;
        }

        x[i] = 1.0;

        U = U - obj[i].weight;

        totalProfit =
        totalProfit + obj[i].profit;
    }

    // Fractional selection
    if(i < n)
    {
        x[i] = (float)U / obj[i].weight;

        totalProfit =
        totalProfit +
        (x[i] * obj[i].profit);
    }

    // Display selected objects
    cout << "\nSelected Objects:\n";

    cout << "\nObject\tProfit\tWeight\tFraction Selected\n";

    for(i = 0; i < n; i++)
    {
        cout << i + 1 << "\t"
             << obj[i].profit << "\t"
             << obj[i].weight << "\t"
             << x[i] << endl;
    }

    cout << "\nMaximum Profit = "
         << totalProfit << endl;

    return 0;
}