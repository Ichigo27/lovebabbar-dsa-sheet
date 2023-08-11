// 418 Kth smallest and largest element in an unsorted array

// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

// Note :-  l and r denotes the starting and ending index of the array.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/_9F2VgZcvdw

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < k; i++)
        maxHeap.push(arr[i]);
    for (int i = k; i <= r; i++)
        if(arr[i] < maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    return maxHeap.top();
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << kthSmallest(arr, 0, n - 1, k);
}