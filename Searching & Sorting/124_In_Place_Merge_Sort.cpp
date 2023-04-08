// 124 Implement Merge-sort in-place

// Implement Merge Sort i.e. standard implementation keeping the sorting algorithm as in-place. In-place means it does not occupy extra memory for merge operation as in the standard case.

#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/in-place-merge-sort/
// Time Complexity: O(log n*nlog n)

int nextGap(int gap)
{
    if(gap <= 1)
        return 0;
    return ceil(gap / 2.0);
}

void merge(int arr[], int low, int mid, int high)
{
    for (int gap = high - low + 1; gap > 0; gap = nextGap(gap))
    {
        for (int i = low; i + gap <= high; i++)
        {
            int j = i + gap;
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
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
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}