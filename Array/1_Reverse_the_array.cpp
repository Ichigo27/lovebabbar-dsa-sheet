// 1 Reverse the array

// Given an array (or string), the task is to reverse the array/string.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int arr[N];

// Time Complexity : O(n)
void reverse_arr(int start, int end)
{
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverse_arr(start + 1, end - 1);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse_arr(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}