// 408 First negative integer in every window of size “k”

// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> res;
    queue<long long> q;
    for (int i = 0; i < K; i++)
        if (A[i] < 0)
            q.push(i);
    res.push_back(!q.empty() ? A[q.front()] : 0);
    for (int i = K; i < N; i++)
    {
        if (!q.empty() && i - q.front() >= K)
            q.pop();
        if (A[i] < 0)
            q.push(i);
        res.push_back(!q.empty() ? A[q.front()] : 0);
    }
    return res;
}

int main()
{
    long long int N;
    cin >> N;
    long long int A[N];
    for (long long int i = 0; i < N; i++)
        cin >> A[i];
    long long int K;
    cin >> K;
    vector<long long> ans = printFirstNegativeInteger(A, N, K);
    for (auto it : ans)
        cout << it << " ";
}