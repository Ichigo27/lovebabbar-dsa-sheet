// 429 Convert min heap to max heap

// You are given an array arr of N integers representing a min Heap. The task is to convert it to max Heap.
// A max-heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node.

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ((l < n) && (arr[l] > arr[largest]))
        largest = l;
    if ((r < n) && (arr[r] > arr[largest]))
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for (int i = N / 2 - 1; i >= 0; --i)
        heapify(arr, N, i);
}

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    convertMinToMaxHeap(arr, N);
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
}