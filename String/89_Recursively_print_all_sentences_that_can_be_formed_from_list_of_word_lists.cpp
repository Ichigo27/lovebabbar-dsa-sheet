// 89 Recursively print all sentences that can be formed from list of word lists

// Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion?

#include <bits/stdc++.h>
using namespace std;

void func(vector<vector<string>> &arr, int r, int i, string s, vector<string> &ans)
{
    if (i == r)
    {
        ans.push_back(s);
        return;
    }
    for (int j = 0; j < arr[i].size(); j++)
    {
        func(arr, r, i + 1, s + arr[i][j] + " ", ans);
    }
}

void printSentence(vector<vector<string>> &arr, int n)
{
    vector<string> temp;
    func(arr, n, 0, "", temp);
    for (auto s : temp)
        cout << s << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<string> temp(m);
        for (int j = 0; j < m; j++)
        {
            cin >> temp[j];
        }
        arr[i] = temp;
    }
    printSentence(arr, n);
}