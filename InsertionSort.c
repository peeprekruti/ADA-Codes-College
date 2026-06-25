#include <stdio.h>

int main()
{
    int n, i, j, key;

    printf("Enter number of values: ");
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Insertion Sort
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    printf("\nSorted Array is:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}


Enter number of values: 5
Enter value 1: 5
Enter value 2: 2
Enter value 3: 8
Enter value 4: 1
Enter value 5: 4

Sorted Array is:
1    2    4    5    8
