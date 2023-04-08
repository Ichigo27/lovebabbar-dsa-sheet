// 123 Findthe inversion count

// Given an array of integers. Find the Inversion Count in the array.

// Inversion Count : For an array, inversion count indicates how far(or close) the array is from being sorted.If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

#include <bits/stdc++.h>
using namespace std;

long long int merge(long long arr[], long long low, long long mid, long long high)
{
    long long int ans = 0;
    long long n = mid - low + 1;
    long long m = high - mid;
    long long arr1[n + 1], arr2[m + 1];
    for (long long i = 0; i < n; i++)
    {
        arr1[i] = arr[low + i];
    }
    arr1[n] = INT64_MAX;
    for (long long i = 0; i < m; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }
    arr2[m] = INT64_MAX;
    int i = 0, j = 0;
    for (int k = low; k <= high; k++)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i++];
        }
        else
        {
            arr[k] = arr2[j++];
            ans += n - i;
        }
    }
    return ans;
}

long long int mergesort(long long arr[], long long low, long long high)
{
    long long ans = 0;
    if (low < high)
    {
        long long mid = low + (high - low) / 2;
        ans += mergesort(arr, low, mid);
        ans += mergesort(arr, mid + 1, high);
        ans += merge(arr, low, mid, high);
    }
    return ans;
}

long long int inversionCount(long long arr[], long long N)
{
    return mergesort(arr, 0, N - 1);
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