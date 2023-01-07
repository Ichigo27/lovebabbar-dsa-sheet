// 3 Find the "Kth" max and min element of an array

// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

#include <bits/stdc++.h>
using namespace std;

// K’th smallest element in an unsorted array using sorting:
// Time Complexity: O(N log N)
// Auxiliary Space: O(1) 

// K’th smallest element in an unsorted array using heap data structure:
// https://www.youtube.com/watch?v=4BfL2Hjvh8g
// Time Complexity : O(n log k)
// // Auxiliary Space: O(k) 

// K’th smallest element in an unsorted array using QuickSelect:
// https://www.youtube.com/watch?v=BP7GCALO2v8
// Time Complexity: O(N^2) in worst case and O(N) on average 
// Auxiliary Space: O(1)

int quick_select(int arr[], int start, int end, int pivot, int k)
{
    int i = start - 1;
    int j = i + 1;
    while(j < pivot)
    {
        if(arr[j] < arr[pivot])
            swap(arr[++i], arr[j]);
        j++;
    }
    swap(arr[i+1], arr[pivot]);
    pivot = i+1;
    if(pivot + 1 == k)
        return pivot;
    else if (pivot + 1 > k)
        return quick_select(arr, start, pivot-1, pivot-1, k);
    else
        return quick_select(arr, pivot+1, end, end, k);
}

int kthSmallest(int arr[], int l, int r, int k)
{
    int p = quick_select(arr, l, r, r, k);
    return arr[p];
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
    int k;
    cin >> k;
    cout << kthSmallest(arr, 0, n - 1, k);
}