// 180 Maximize sum of consecutive differences in a circular array

// Given an array a[ ] of N elements. Consider array as a circular array i.e. element after an is a1. The task is to find maximum sum of the absolute difference between consecutive elements with rearrangement of array elements allowed i.e. after any rearrangement of array elements find |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1|.

#include <bits/stdc++.h>
using namespace std;

long long int maxSum(int arr[], int n)
{
    long long res = 0;
    sort(arr, arr + n);
    int i = 0, j = n - 1, flag = 1;
    while (i < j)
    {
        res += abs(arr[i] - arr[j]);
        if (flag)
        {
            i++;
        }
        else
        {
            j--;
        }
        flag = !flag;
    }
    res += abs(arr[i] - arr[0]);
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSum(arr, n);
}