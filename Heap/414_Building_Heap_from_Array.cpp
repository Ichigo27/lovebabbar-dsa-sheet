// 414 Implement a Maxheap/MinHeap using arrays and recursion.

// Given an array of N elements. The task is to build a Binary Heap from the given array. The heap can be either Max Heap or Min Heap.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/NKJnHewiGdc?t=577

class Heap
{
public:
    int *arr;
    int size;

    Heap(int n)
    {
        arr = new int[n];
        size = -1;
    }

    void heapify(int *arr, int n, int i)
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

    void push(int val)
    {
        size++;
        int i = size;
        arr[i] = val;
        while ((i != 0) && (arr[(i - 1) / 2] < arr[i]))
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void pop()
    {
        swap(arr[0], arr[size]);
        size--;
        heapify(arr, size + 1, 0);
    }
};

int main()
{
    int n;
    cin >> n;
    Heap h(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        h.push(x);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << h.arr[i] << " ";
    }
    h.pop();
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << h.arr[i] << " ";
    }
}