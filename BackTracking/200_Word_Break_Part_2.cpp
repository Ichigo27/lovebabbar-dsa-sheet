// 200 Word Break Problem using Backtracking

// Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<string>> dp;

vector<string> solve(int pos, string s, unordered_set<string> &dict)
{
    if (dp.find(pos) != dp.end())
        return dp[pos];

    vector<string> res;
    if (pos == s.size())
    {
        res.push_back("");
    }
    for (int i = pos; i < s.size(); i++)
    {
        string prefix = s.substr(pos, i - pos + 1);
        if (dict.find(prefix) != dict.end())
        {
            vector<string> suffix = solve(i + 1, s, dict);
            for (int j = 0; j < suffix.size(); j++)
            {
                res.push_back(prefix + (suffix[j] == "" ? "" : " ") + suffix[j]);
            }
        }
    }
    return dp[pos] = res;
}

vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    unordered_set<string> hsh;
    for (int i = 0; i < n; i++)
    {
        hsh.insert(dict[i]);
    }
    return solve(0, s, hsh);
}

int main()
{
    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    string s;
    cin >> s;
    vector<string> ans = wordBreak(n, dict, s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
