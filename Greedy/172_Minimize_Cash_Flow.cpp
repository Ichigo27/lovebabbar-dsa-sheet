// 172 Minimize Cash Flow among a given set of friends who have borrowed money from each other

// Given a number of friends who have to give or take some amount of money from one another. Design an algorithm by which the total cash flow among all the friends is minimized.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n)
{
    vector<vector<int>> ans(n, vector<int>(n));
    vector<int> person(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            person[i] += -transaction[i][j] + transaction[j][i];
        }
    }
    // for(auto ele: person)
    //     cout << ele << ' ';
    // cout << endl;
    while (true)
    {
        int maxDebit = 0, maxCredit = 0;
        int idxDebit = 0, idxCredit = 0;
        for (int i = 0; i < n; i++)
        {
            if (maxDebit > person[i])
            {
                maxDebit = person[i];
                idxDebit = i;
            }
            if (maxCredit < person[i])
            {
                maxCredit = person[i];
                idxCredit = i;
            }
        }
        if (maxDebit == 0 || maxCredit == 0)
            break;
        int amount = min(-maxDebit, maxCredit);
        person[idxCredit] -= amount;
        person[idxDebit] += amount;
        ans[idxDebit][idxCredit] += amount;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    vector<vector<int>> ans = minCashFlow(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}