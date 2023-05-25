// 189 GERGOVIA -Wine trading in Gergovia

// Gergovia consists of one street, and every inhabitant of the city is a wine salesman. Everyone buys wine from other inhabitants of the city. Every day each inhabitant decides how much wine he wants to buy or sell. Interestingly, demand and supply is always the same, so that each inhabitant gets what he wants.
// There is one problem, however: Transporting wine from one house to another results in work. Since all wines are equally good, the inhabitants of Gergovia don't care which persons they are doing trade with, they are only interested in selling or buying a specific amount of wine.
// In this problem you are asked to reconstruct the trading during one day in Gergovia. For simplicity we will assume that the houses are built along a straight line with equal distance between adjacent houses. Transporting one bottle of wine from one house to an adjacent house results in one unit of work.

// Input

// The input consists of several test cases.
// Each test case starts with the number of inhabitants N (2 ≤ N ≤ 100000).
// The following line contains n integers ai (-1000 ≤ ai ≤ 1000).
// If ai ≥ 0, it means that the inhabitant living in the ith house wants to buy ai bottles of wine. If ai < 0, he wants to sell -ai bottles of wine.
// You may assume that the numbers ai sum up to 0.
// The last test case is followed by a line containing 0.

// Output

// For each test case print the minimum amount of work units needed so that every inhabitant has his demand fulfilled.

#include <bits/stdc++.h>
using namespace std;

long long minWork(int n, vector<int> &arr)
{
    vector<pair<int, int>> buyer, seller;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            buyer.push_back({arr[i], i});
        else
            seller.push_back({arr[i], i});
    }
    long long res = 0;
    int i = 0, j = 0;
    while (i < buyer.size() && j < seller.size())
    {
        int trade = min(buyer[i].first, -seller[j].first);
        buyer[i].first -= trade;
        seller[j].first += trade;
        res += (trade * abs(buyer[i].second - seller[j].second));
        if (buyer[i].first == 0)
            i++;
        if (seller[j].first == 0)
            j++;
    }
    return res;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << minWork(n, arr) << endl;
    }
}