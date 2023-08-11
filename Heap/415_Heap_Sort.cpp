// 415 Sort an Array using heap. (HeapSort)

// Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/NKJnHewiGdc?t=2935

class Heap
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
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

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(arr, n, i);
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for (int i = n - 1; i >= 0; --i)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    Heap obj;
    obj.heapSort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}