#include<iostream>
using namespace std;

// Function Prototypes
void Merge_Sort(int arr[], int l, int h);
void Merge(int arr[], int l, int mid, int h);

int main()
{
    int i, n;

    cout << "Enter number of values: ";
    cin >> n;

    int arr[n];

    // Input Array
    for(i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Calling Merge Sort
    Merge_Sort(arr, 0, n - 1);

    // Printing Sorted Array
    cout << "\nSorted Array is:\n";

    for(i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    return 0;
}

// Merge Sort Function
void Merge_Sort(int arr[], int l, int h)
{
    int mid;

    if(l < h)
    {
        mid = (l + h) / 2;

        Merge_Sort(arr, l, mid);
        Merge_Sort(arr, mid + 1, h);

        Merge(arr, l, mid, h);
    }
}

// Merge Function
void Merge(int arr[], int l, int mid, int h)
{
    int i, j, k;

    int b[h + 1];

    i = l;
    j = mid + 1;
    k = l;

    while(i <= mid && j <= h)
    {
        if(arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements of left side
    while(i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right side
    while(j <= h)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    // Copy back to original array
    for(i = l; i <= h; i++)
    {
        arr[i] = b[i];
    }
}