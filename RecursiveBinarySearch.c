#include<stdio.h>

// Function Prototype
int Binary_Search(int arr[], int l, int h, int num);

int main()
{
    int i, n, num;

    printf("Enter number of values stored in Array: ");
    scanf("%d", &n);

    int arr[n];

    // Input Array
    for(i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter Value to be searched: ");
    scanf("%d", &num);

    i = Binary_Search(arr, 0, n - 1, num);

    if(i == -1)
    {
        printf("%d not found in array", num);
    }
    else
    {
        printf("%d found at position %d in array", num, i + 1);
    }

    return 0;
}

int Binary_Search(int arr[], int l, int h, int num)
{
    if(l > h)
    {
        return -1;
    }

    int mid = (l + h) / 2;

    if(arr[mid] == num)
    {
        return mid;
    }
    else if(arr[mid] < num)
    {
        return Binary_Search(arr, mid + 1, h, num);
    }
    else
    {
        return Binary_Search(arr, l, mid - 1, num);
    }
}
