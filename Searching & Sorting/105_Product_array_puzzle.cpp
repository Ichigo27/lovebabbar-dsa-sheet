// 105 Product array Puzzle

// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=bNvIQI2wAjk
// Time Complexity: O(n)
// Auxiliary Space: O(1)
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> ans(n, 1);
    int left = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] *= left;
        left *= nums[i];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<long long int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<long long int> ans = productExceptSelf(arr, n);
    for (auto ele : ans)
        cout << ele << ' ';
}