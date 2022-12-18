// 16 Count Inversion

// Given an array of integers. Find the Inversion Count in the array. 

#include <bits/stdc++.h>
using namespace std;

// method 1: brute force
//     Time complexity : O(n^2)
//     Space complexity : O(1)

// method 2: merge sort
// https://www.youtube.com/watch?v=kQ1mJlwW-c0
//     Time complexity : O(nlogn)
//     Space complexity : O(n)
long long int merge(long long arr[], int left, int mid, int right)
{
    long long int ans = 0;
    int n = mid - left + 1;
    int m = right - mid;
    long long temp1[n + 1], temp2[m + 1];
    for (int i = 0; i < n; i++)
    {
        temp1[i] = arr[left + i];
    }
    for (int i = 0; i < m; i++)
    {
        temp2[i] = arr[mid + 1 + i];
    }
    temp1[n] = INT64_MAX;
    temp2[m] = INT64_MAX;
    int i = 0;
    int j = 0;
    for (int k = left; k <= right; k++)
    {
        if (temp1[i] <= temp2[j])
        {
            arr[k] = temp1[i];
            i++;
        }
        else
        {
            arr[k] = temp2[j];
            j++;

            ans += n - i;
        }
    }
    return ans;
}

long long int mergesort(long long arr[], int left, int right)
{
    long long int ans = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        ans += mergesort(arr, left, mid);
        ans += mergesort(arr, mid + 1, right);
        ans += merge(arr, left, mid, right);
    }
    return ans;
}

long long int inversionCount(long long arr[], long long N)
{
    int start = 0;
    int end = N - 1;
    return mergesort(arr, start, end);
}

int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << inversionCount(arr, n);
}