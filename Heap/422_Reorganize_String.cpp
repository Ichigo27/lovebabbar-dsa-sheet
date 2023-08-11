// 422 Leetcode- reorganize strings

// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.

#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string str)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < str.size(); i++)
    {
        mp[str[i]]++;
    }
    string ans(str.size(), ' ');
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
    cout << reorganizeString(s);
}