// 57 Print all the permutations of the given string

// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/f2ic2Rsc9pU
// Time Complexity: O(n! * n)
// Space Complexity: O(n)
void permute(int i, string s, vector<string> &ans)
{
    if(i >= s.size())
        ans.push_back(s);
    for (int idx = i; idx < s.size(); idx++)
    {
        if(idx > i && s[idx] == s[idx-1]) continue;
        swap(s[idx], s[i]);
        permute(i + 1, s, ans);
        swap(s[idx], s[i]);
    }
}

vector<string> find_permutation(string S)
{
    sort(S.begin(), S.end());
    vector<string> ans;
    permute(0, S, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = find_permutation(s);
    for(auto ele: ans)
        cout << ele << ' ';
}