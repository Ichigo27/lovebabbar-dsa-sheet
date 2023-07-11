// 294

// Given an array arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the minimum sum and return its sum.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Auxiliary Space: O(1)
int smallestSumSubarray(vector<int> &a)
{
    int n = a.size();
    int sum = a[0];
    int res = a[0];
    for (int i = 1; i < n; i++)
    {
        sum = min(a[i], sum + a[i]);
        res = min(res, sum);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << smallestSumSubarray(a) << endl;
}