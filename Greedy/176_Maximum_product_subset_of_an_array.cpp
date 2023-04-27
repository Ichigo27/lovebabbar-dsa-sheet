// 176 Maximum product subset of an array

// Given an array A[]. The task is to find the maximum product possible with the subset of elements present in the array. The maximum product can be a single element also.
// Since the product can be large, return it modulo (109 + 7).

#include <bits/stdc++.h>
using namespace std;

long long int findMaxProduct(vector<int> &a, int n)
{
    if (n == 1)
        return a[0];
    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    long long int prod = 1;
    int m = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            count_zero++;
            continue;
        }
        if (a[i] < 0)
        {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
        prod = (prod * a[i]) % m;
    }
    if (count_zero == n)
        return 0;
    if (count_neg & 1)
    {
        if (count_neg == 1 && count_zero > 0 && count_zero + count_neg == n)
            return 0;
        prod = prod / max_neg;
    }
    return prod;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findMaxProduct(arr, n);
}