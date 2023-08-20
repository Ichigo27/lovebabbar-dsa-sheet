// 447 Power Set

// Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

#include <bits/stdc++.h>
using namespace std;

// youtube.com/watch?v=h4zNvA4lbtc


// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
vector<string> AllPossibleStrings(string s)
{
    vector<string> subsets;
    int n = s.size();
    for (int i = 0; i < (1 << n); i++)
    {
        string temp = "";
        for (int j = 0; j < n; j++)
        {
            if(i & (1 << j))
                temp.push_back(s[j]);
        }
        if(temp.size() > 0)
            subsets.push_back(temp);
    }
    sort(subsets.begin(), subsets.end());
    return subsets;
}

int main()
{
    string s;
    cin >> s;
    vector<string> res = AllPossibleStrings(s);
    for (auto i : res)
        cout << i << " ";
}