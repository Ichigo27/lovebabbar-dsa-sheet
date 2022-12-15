// 8 find Largest sum contiguous Subarray [V. IMP]

// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

#include <bits/stdc++.h>
using namespace std;

// method 1: Brute force approach I : Using 3 nested loops

// int maxSubarraySum(int A[], int n)
// {
//     int max_sum = 0 for (i = 0 to n - 1)
//     {
//         for (j = i to n - 1)
//         {
//             int sum = 0 for (k = i to j)
//                 sum = sum + A[k] if (sum > max_sum)
//                                 max_sum = sum
//         }
//     }
//     return max_sum
// }

// Time Complexity: O(n^3)
// Space Complexity: O(1)

// method 2: Brute force approach II : Using 2 nested loops

// int maxSubarraySum(int A[], int n)
// {
//     int max_sum = 0 for (i = 0 to n - 1)
//     {
//         sum = 0 for (j = i to n - 1)
//         {
//             sum = sum + A[j] if (sum > max_sum)
//                             max_sum = sum
//         }
//     }
//     retun max_sum
// }

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// method 3: Dynamic Programming
// Time complexity: O(n)
// Auxiliary Space: O(1)
long long maxSubarraySum(int arr[], int n)
{
    long long ans = INT64_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max((long long)arr[i], sum + arr[i]);
        ans = max(ans, sum);
    }
    return ans;
}

// method 4: Kadane's Algorithm

// check Q13

// Time complexity: O(n)
// Auxiliary Space: O(1)

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxSubarraySum(arr, n);
}