// 73 Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    int m = strs[0].size();
    string ans = "";
    for (int i = 0; i < m; i++)
    {
        char check = strs[0][i];
        int flag = 0;
        for (int j = 1; j < n; j++)
        {
            if(i >= strs[j].size() || strs[j][i] != check)
                flag = 1;
        }
        if(flag == 1)
            return ans;
        ans.push_back(check);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << longestCommonPrefix(arr);
}