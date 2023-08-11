// 417 “k” largest element in an array

// Given an array Arr of N positive integers and an integer K, find K largest elements from the array.  The output elements should be printed in decreasing order.

#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < k; i++)
        minHeap.push(arr[i]);
    for (int i = k; i < n; i++)
        if(arr[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    vector<int> result;
    while(!minHeap.empty())
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> result = kLargest(arr, n, k);
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
}