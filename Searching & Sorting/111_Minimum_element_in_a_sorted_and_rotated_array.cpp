// 111 Find pivot element in a sorted array

// A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/j3187M1P2Xg
// Time Complexity: O(logN), using binary search
// Auxiliary Space: O(1)
int findMin(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = low + ((high - low) >> 1);
        if (arr[mid] > arr[high])
            low = mid + 1;
        else if (arr[mid] < arr[high])
            high = mid;
        else
            high--;
    }
    return arr[low];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findMin(arr, n);
}