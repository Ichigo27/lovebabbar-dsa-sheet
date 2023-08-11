// 427 Connect “n” ropes with minimum cost

// There are given N ropes of different lengths, we need to connect these ropes into one rope.The cost to connect two ropes is equal to sum of their lengths.The task is to connect the ropes with minimum cost.Given N size array arr[] contains the lengths of the ropes.

#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int i = 0; i < n; i++)
        minHeap.push(arr[i]);
    while (minHeap.size() > 1)
    {
        long long r1 = minHeap.top();
        minHeap.pop();
        long long r2 = minHeap.top();
        minHeap.pop();
        minHeap.push(r1 + r2);
    }
    return minHeap.top();
}

int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    cout << minCost(arr, n) << endl;
}