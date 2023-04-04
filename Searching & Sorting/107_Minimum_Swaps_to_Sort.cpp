// 107 minimum no. of swaps required to sort the array

// Given an array of n distinct elements.Find the minimum number of swaps required to sort the array in strictly increasing order.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/1BxbBgNSwHo
// Time Complexity: O(n Log n)
// Auxiliary Space: O(n)
int minSwaps(vector<int> &nums)
{
    int ans = 0;
    vector<pair<int, int>> arr(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        arr[i] = {nums[i], i};
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != arr[i].second)
        {
            swap(arr[i], arr[arr[i].second]);
            ans++;
            i--;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minSwaps(arr);
}