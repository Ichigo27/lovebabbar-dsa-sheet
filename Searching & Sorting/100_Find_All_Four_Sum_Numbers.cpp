// 100 find four elements that sum to a given value

// Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

#include <bits/stdc++.h>
using namespace std;

// Sorting + 2 pointer
//  Time Complexity : O(N^3), Here Three nested loop creates the time complexity. Where N is the size of the array(nums).
//  Space Complexity : O(1), Constant space. Extra space is only allocated for the Vector(output), however the output does not count towards the space complexity.
vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int l = j + 1;
            int r = n - 1;
            while (l < r)
            {
                long long target = (long long)k - arr[i] - arr[j];
                long long current = arr[l] + arr[r];
                if (current < target)
                    l++;
                else if (current > target)
                    r--;
                else
                {
                    int left = arr[l], right = arr[r];
                    ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                    while (l < r && arr[l] == left)
                        l++;
                    while (l < r && arr[r] == right)
                        r--;
                }
            }
            while (j + 1 < n - 2 && arr[j + 1] == arr[j])
                j++;
        }
        while (i + 1 < n - 3 && arr[i + 1] == arr[i])
            i++;
    }
    return ans;
}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> ans = fourSum(arr, k);
    for (auto &nums : ans)
    {
        for (auto ele : nums)
        {
            cout << ele << ' ';
        }
        cout << '$';
    }
}