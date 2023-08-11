// 421 Kth largest sum continuous subarrays

// You are given an array Arr of size N. You have to find the K-th largest sum of contiguous subarray within the array elements.

#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> &Arr, int N, int K)
{
    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        prefix[i] = prefix[i - 1] + Arr[i - 1];
    }
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {

            if (minHeap.size() < K)
            {
                minHeap.push(prefix[i] - prefix[j - 1]);
            }
            else
            {
                if (prefix[i] - prefix[j - 1] > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(prefix[i] - prefix[j - 1]);
                }
            }
        }
    }
    return minHeap.top();
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> Arr(N);
    for (int i = 0; i < N; i++)
        cin >> Arr[i];
    cout << kthLargest(Arr, N, K);
}