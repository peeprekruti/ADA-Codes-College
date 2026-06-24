#include <stdio.h>

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int n, i;

    printf("Enter number of values: ");
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("\nSorted Array is:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}

void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    while(i <= j)
    {
        while(i <= high && arr[i] <= pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}
