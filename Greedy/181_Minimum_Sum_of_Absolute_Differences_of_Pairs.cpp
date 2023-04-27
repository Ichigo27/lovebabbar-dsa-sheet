// 181 Minimum sum of absolute difference of pairs of two arrays

// You are given two arrays A and B of equal length N. Your task is to pair each element of array A to an element in array B, such that the sum of the absolute differences of all the pairs is minimum.

#include <bits/stdc++.h>
using namespace std;

long long findMinSum(vector<int> &A, vector<int> &B, int N)
{
    long long res = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++)
    {
        res += abs(A[i] - B[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cout << findMinSum(a, b, n);
}