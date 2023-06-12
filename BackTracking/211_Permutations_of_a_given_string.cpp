// 211 Print all permutations of a string

// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O((N! * log N) + (N! * log N!)),  As recursion takes O(N!)  time because we generate every possible permutation and another O(log N)  time is required to insert every permutation in the set. Also, O(N! Log N!)  time is required to sort the array.
// Auxiliary Space: O(N*N!), To store all permutations O(N!) space is required and every permutation is of N size string so total space will be O(N*N!).

void solve(int idx, string s, unordered_set<string> &res)
{
    if (idx == s.size())
    {
        res.insert(s);
        return;
    }
    for (int i = idx; i < s.size(); i++)
    {
        if (i > idx && s[i] == s[i - 1])
            continue;
        swap(s[idx], s[i]);
        solve(idx + 1, s, res);
        swap(s[idx], s[i]);
    }
}

vector<string> find_permutation(string S)
{
    unordered_set<string> res;
    solve(0, S, res);
    vector<string> ans;
    for (auto &permutation : res)
    {
        ans.push_back(permutation);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> res = find_permutation(s);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
}
