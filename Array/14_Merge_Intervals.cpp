// 14 Merge Intervals

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

#include <bits/stdc++.h>
using namespace std;

// method 1: brute force
// Time complexity : O(n^2)
// Space complexity : O(n)

// method 2: optimal
// https://www.youtube.com/watch?v=2JzRBPFYbKE
// Time complexity : O(nlogn)
// Space complexity : O(n)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    if(intervals.size() == 0)
        return ans;
    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];
    for (auto &it : intervals)
    {
        if(it[0] <= temp[1])
        {
            temp[1] = max(temp[1], it[1]);
        }
        else
        {
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    vector<vector<int>> output = merge(intervals);
    for(auto &x: output)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}