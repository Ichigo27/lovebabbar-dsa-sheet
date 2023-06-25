// 258 Minimise the cashflow among a given set of friends who have borrowed money from each other

// Given a number of friends who have to give or take some amount of money from one another. Design an algorithm by which the total cash flow among all the friends is minimized.

#include <bits/stdc++.h>
using namespace std;

// time complexity: O(n^2)
// space complexity: O(n^2)
vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int numPeople)
{
    // net[i] is the net balance of person i
    vector<int> net(numPeople, 0);
    for (int i = 0; i < numPeople; i++)
    {
        for (int j = 0; j < numPeople; j++)
        {
            net[i] += transaction[j][i] - transaction[i][j];
        }
    }
    vector<vector<int>> ans;
    while (true)
    {
        // maxCredit is the person who is owed the most
        int maxCredit = max_element(net.begin(), net.end()) - net.begin();
        // maxDebit is the person who owes the most
        int maxDebit = min_element(net.begin(), net.end()) - net.begin();
        // If both maxCredit and maxDebit have a net balance of 0,
        // then everyone has a net balance of 0, and we are done.
        if (net[maxCredit] == 0 && net[maxDebit] == 0)
        {
            break;
        }
        // minAmount is the minimum amount that we need to balance
        // the net balances of maxCredit and maxDebit
        int minAmount = min(-net[maxDebit], net[maxCredit]);
        net[maxCredit] -= minAmount;
        net[maxDebit] += minAmount;
        ans.push_back({maxDebit, maxCredit, minAmount});
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