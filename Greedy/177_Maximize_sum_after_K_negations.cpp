// 177 Maximize array sum after K negations

// Given an array of integers of size N and a number K., You must modify array arr[] exactly K number of times. Here modify array means in each operation you can replace any array element either arr[i] by -arr[i] or -arr[i] by arr[i]. You need to perform this operation in such a way that after K operations, the sum of the array must be maximum.

#include <bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int a[], int n, int k)
{
    long long res = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            a[i] = -a[i];
            k--;
        }
        if (k == 0)
            break;
    }
    sort(a, a + n);
    if (k % 2 == 1)
    {
        a[0] = -a[0];
    }
    for (int i = 0; i < n; i++)
    {
        res += a[i];
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    long long int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maximizeSum(arr, n, k);
}