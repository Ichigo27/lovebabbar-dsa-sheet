// 23 find maximum product subarray

// Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

#include <bits/stdc++.h>
using namespace std;

// method 1: brute force
// Time Complexity: O(n^2) 
// Auxiliary Space: O(1)

// method 2: dynamic programming
// Time Complexity: O(n) 
// Auxiliary Space: O(1)

// gfg
long long maxProduct(vector<int> arr, int n)
{
    long long ans = arr[0];
    long long maxi = arr[0];
    long long mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
            swap(maxi, mini);
        maxi = max((long long)arr[i], maxi * arr[i]);
        mini = min((long long)arr[i], mini * arr[i]);
        ans = max(ans, maxi);
    }
    return ans;
}

// neetcode
// long long maxProduct(vector<int> arr, int n)
// {
//     long long ans = *max_element(arr.begin(), arr.end());
//     long long maxi = 1;
//     long long mini = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             maxi = 1;
//             mini = 1;
//             continue;
//         }
//         long long tempmax = maxi, tempmin = mini;
//         maxi = max((long long)arr[i], max(tempmax * arr[i], tempmin * arr[i]));
//         mini = min((long long)arr[i], min(tempmax * arr[i], tempmin * arr[i]));
//         ans = max(ans, maxi);
//     }
//     return ans;
// }

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxProduct(arr, n);
}