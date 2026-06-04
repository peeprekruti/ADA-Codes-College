# EXP1(b)

#include<iostream>
using namespace std;

// Function Prototype
int Binary_Search(int arr[], int l, int h, int num);

int main()
{
    int i, n, num;

    cout << "Enter number of values stored in Array: ";
    cin >> n;

    int arr[n];

    // Input Array
    for(i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter Value to be searched: ";
    cin >> num;

    i = Binary_Search(arr, 0, n - 1, num);

    if(i == -1)
    {
        cout << num << " not found in array";
    }
    else
    {
        cout << num << " found at position " << i + 1 << " in array";
    }

    return 0;
}

// Binary Search Function
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
