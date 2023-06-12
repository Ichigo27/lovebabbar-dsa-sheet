// 215 Partition of a set intoK subsets with equal sum

// Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
// Note : All elements of this array should be part of exactly one partition.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=3qN3bonkCG4
// https://www.youtube.com/watch?v=mBk4I0X46oI
// Time Complexity: O(N*2^N)
// Auxiliary Space: O(2^N)

bool solve(int a[], int n, int k, int idx, int curr, vector<bool> &visited, int target)
{
    if (k == 0)
        return true;
    if (curr > target)
        return false;
    if (curr == target)
    {
        return solve(a, n, k - 1, 0, 0, visited, target);
    }
    for (int i = idx; i < n; i++)
    {
        if (i > idx && visited[i - 1] == false && a[i] == a[i - 1])
            continue;
        if (visited[i] == false)
        {
            visited[i] = true;
            if (solve(a, n, k, i + 1, curr + a[i], visited, target) == true)
                return true;
            visited[i] = false;
        }
    }
    return false;
}

bool isKPartitionPossible(int a[], int n, int k)
{
    sort(a, a + n, greater<int>());
    if (k > n)
        return false;
    if (k == 1)
        return true;
    int total = accumulate(a, a + n, 0);
    if (total % k != 0)
        return false;
    vector<bool> visited(n, false);
    return solve(a, n, k - 1, 0, 0, visited, total / k);
}

// bool solve(int idx, int target, int arr[], int n, int k, vector<int> &part)
// {
//     if (idx == n)
//     {
//         int sum1 = part[0];
//         for (int i = 1; i < k; i++)
//         {
//             if (part[i] != sum1)
//                 return false;
//         }
//         return true;
//     }
//     for (int i = 0; i < k; i++)
//     {
//         if (part[i] + arr[idx] > target)
//             continue;
//         part[i] += arr[idx];
//         if (solve(idx + 1, target, arr, n, k, part) == true)
//             return true;
//         part[i] -= arr[idx];
//     }
//     return false;
// }

// bool isKPartitionPossible(int a[], int n, int k)
// {
//     if (k > n)
//         return false;
//     if (k == 1)
//         return true;
//     int total = accumulate(a, a + n, 0);
//     if (total % k != 0)
//         return false;
//     vector<int> partition(k, 0);
//     return solve(0, total / k, a, n, k, partition);
// }

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << isKPartitionPossible(arr, n, k);
}