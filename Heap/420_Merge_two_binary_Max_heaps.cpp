// 420 Merge 2 Binary Max Heaps

// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/_9F2VgZcvdw?t=2310

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

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> merged(n + m);
    for (int i = 0; i < n; ++i)
        merged[i] = a[i];
    for (int i = 0; i < m; ++i)
        merged[n + i] = b[i];
    for (int i = (n + m) / 2 - 1; i >= 0; --i)
        heapify(merged, n + m, i);
    return merged;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    vector<int> merged = mergeHeaps(a, b, n, m);
    for (int i = 0; i < n + m; ++i)
        cout << merged[i] << " ";
}