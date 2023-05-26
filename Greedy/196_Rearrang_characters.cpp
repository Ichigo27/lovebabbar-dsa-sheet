// 195 Rearrange characters in a string such that no two adjacent are same

// Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
// Note : The string has only lowercase English alphabets and it can have multiple solutions.Return any one of them.

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(N)
// Auxiliary Space: O(N+26), as there are 26 lowercase english characters

static bool cmp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}

    string rearrangeString(string str)
{
    unordered_map<char, int> hsh;
    for (int i = 0; i < str.size(); i++)
    {
        hsh[str[i]]++;
    }
    vector<pair<char, int>> freq;
    for (auto &ele : hsh)
    {
        freq.push_back({ele.first, ele.second});
    }
    sort(freq.begin(), freq.end(), cmp);
    if (freq[0].second > (str.size() + 1) / 2)
        return "-1";
    string res(str.size(), ' ');
    int i = 0;
    for (int k = 0; k < freq.size(); k++)
    {
        int j = 0;
        while (i < str.size() && j < freq[k].second)
        {
            res[i] = freq[k].first;
            i += 2;
            j++;
            if (i >= str.size())
                i = 1;
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << rearrangeString(s);
}