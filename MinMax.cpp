#include<iostream>
using namespace std;

// Function Prototype
void MinMax(int arr[], int l, int h, int *min, int *max);

int main()
{
    int arr[] = {20, 3, 4, 5, 1};

    int min, max;

    MinMax(arr, 0, 4, &min, &max);

    cout << "Min = " << min << " and Max = " << max;

    return 0;
}

// Function to find Minimum and Maximum
void MinMax(int arr[], int l, int h, int *min, int *max)
{
    // If array contains only one element
    if(l == h)
    {
        *min = *max = arr[l];
    }

    // If array contains two elements
    else if(l == h - 1)
    {
        if(arr[l] < arr[h])
        {
            *min = arr[l];
            *max = arr[h];
        }
        else
        {
            *min = arr[h];
            *max = arr[l];
        }
    }

    // If array contains more than two elements
    else
    {
        int mid = (l + h) / 2;

        int min1, min2, max1, max2;

        MinMax(arr, l, mid, &min1, &max1);

        MinMax(arr, mid + 1, h, &min2, &max2);

        // Compare minimum values
        if(min1 < min2)
        {
            *min = min1;
        }
        else
        {
            *min = min2;
        }

        // Compare maximum values
        if(max1 < max2)
        {
            *max = max2;
        }
        else
        {
            *max = max1;
        }
    }
}