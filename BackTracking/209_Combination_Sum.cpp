// 209 Combinational Sum

// Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

// Note:
// 1. All numbers will be positive integers.
// 2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// 3. The combinations themselves must be sorted in ascending order.

#include <bits/stdc++.h>
using namespace std;

void solve(int pos, vector<int> &a, int b, int curr, vector<int> &nums, vector<vector<int>> &res)
{
    if (curr == b)
    {
        res.push_back(nums);
        return;
    }

    for (int i = pos; i < a.size(); i++)
    {
        if(curr + a[i] > b)
            break;
        if (i > 0 && a[i] == a[i - 1])
            continue;
        nums.push_back(a[i]);
        solve(i, a, b, curr + a[i], nums, res);
        nums.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> nums;
    solve(0, A, B, 0, nums, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int b;
    cin >> b;
    vector<vector<int>> res = combinationSum(arr, b);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}