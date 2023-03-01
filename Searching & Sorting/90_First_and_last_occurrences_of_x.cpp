// 90 Find first and last positions of an element in a sorted array

// Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log n)
// Auxiliary Space: O(1)
int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

int last(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}

vector<int> find(int arr[], int n, int x)
{
    vector<int> ans;
    ans.push_back(first(arr, x, n));
    ans.push_back(last(arr, x, n));
    return ans;
}

// vector<int> find(int arr[], int n, int x)
// {
//     vector<int> ans;
//     int first = lower_bound(arr, arr + n, x) - arr;
//     int last = upper_bound(arr, arr + n, x) - arr - 1;
//     if (first == n)
//     {
//         first = -1;
//         last = -1;
//     }
//     ans.push_back(first);
//     ans.push_back(last);
//     return ans;
// }

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = find(arr, n, x);
    cout << ans[0] << ' ' << ans[1];
}