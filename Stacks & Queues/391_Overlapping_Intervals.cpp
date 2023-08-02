// 391 Merge Overlapping Intervals

// Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=UZde3ApgsUc

vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    stack<vector<int>> st;
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
         {if(a[0] != b[0]) return a[0] < b[0];
         return a[1] < b[1]; });
    st.push(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (!st.empty() && intervals[i][0] < st.top()[1])
        {
            vector<int> mergedInterval = {st.top()[0], max(st.top()[1], intervals[i][1])};
            st.pop();
            st.push(mergedInterval);
        }
        else
        {
            st.push(intervals[i]);
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<vector<int>> merged = overlappedInterval(intervals);
    for (int i = 0; i < n; i++)
    {
        cout << merged[i][0] << ' ' << merged[i][1] << endl;
    }
}