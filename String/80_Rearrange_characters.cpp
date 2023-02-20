// 80 Rearrange characters in a string such that no two adjacent are same

// Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
// Note : The string has only lowercase English alphabets and it can have multiple solutions.Return any one of them.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(NlogN)
// Auxiliary Space : O(N)
string rearrangeString(string str)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < str.size(); i++)
    {
        mp[str[i]]++;
    }
    string ans(str.size(), ' ');
    cout << ans << endl;
    priority_queue<pair<int, int>> pq;
    for (auto &ele : mp)
    {
        pq.push({ele.second, ele.first});
    }
    pair<int, int> ele = pq.top();
    pq.pop();
    if (ele.first > (str.size() + 1) / 2)
        return "-1";
    int idx = 0;
    while (true)
    {
        while (ele.first > 0)
        {
            ans[idx] = (char)ele.second;
            idx += 2;
            if (idx >= str.size())
                idx = 1;
            ele.first--;
        }
        if (pq.empty())
            break;
        ele = pq.top();
        pq.pop();
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << rearrangeString(s);
}