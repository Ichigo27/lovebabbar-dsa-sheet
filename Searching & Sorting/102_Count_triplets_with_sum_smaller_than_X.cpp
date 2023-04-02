// 102 Count triplet with sum smaller than a given value

// Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(N^2).
// Auxiliary Space: O(1).
long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (arr[i] >= sum)
            continue;
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if(arr[i] + arr[l] + arr[r] < sum)
            {
                ans += r - l;
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return ans;
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countTriplets(arr, n, sum);
}