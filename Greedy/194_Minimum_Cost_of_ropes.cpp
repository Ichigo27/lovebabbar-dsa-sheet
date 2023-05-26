// 194 Minimum Cost of ropes

// There are given N ropes of different lengths, we need to connect these ropes into one rope.The cost to connect two ropes is equal to sum of their lengths.The task is to connect the ropes with minimum cost.Given N size array arr[] contains the lengths of the ropes.

#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    long long cost = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while(pq.size() > 1)
    {
        long long n1 = pq.top();
        pq.pop();
        long long n2 = pq.top();
        pq.pop();
        pq.push(n1 + n2);
        cost += n1 + n2;
    }
    return cost;
}

int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minCost(arr, n);
}