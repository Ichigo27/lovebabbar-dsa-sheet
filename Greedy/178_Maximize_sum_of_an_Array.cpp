// 178 Maximize the sum of arr[i]*i

// Given an array A of N integers. Your task is to write a program to find the maximum value of ∑arr[i]*i, where i = 0, 1, 2,., n 1.
// You are allowed to rearrange the elements of the array.
// Note: Since output could be large, hence module 109+7 and then print answer.

#include <bits/stdc++.h>
using namespace std;

int Maximize(int a[], int n)
{
    long long int res = 0;
    long long int m = 1e9 + 7;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int temp = ((i % m) * (a[i] % m)) % m;
        res = ((res % m) + (temp % m)) % m;
    }
    return res % m;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Maximize(arr, n);
}