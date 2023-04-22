// 170 Buy Maximum Stocks if i stocks can be bought on i-th day

// In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where price[i] denotes the price of the stock on the ith day.
// There is a rule that a customer can buy at most i stock on the ith day.
// If the customer has an amount of k amount of money initially. The task is to find out the maximum number of stocks a customer can buy.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(NlogN)
// Auxiliary Space: O(N)
int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> stocks;
    for (int i = 0; i < n; i++)
    {
        stocks.push_back({price[i], i + 1});
    }
    sort(stocks.begin(), stocks.end());
    int res = 0;
    for (int i = 0; i < stocks.size(); i++)
    {
        res += min(stocks[i].second, k / stocks[i].first);
        k -= stocks[i].first * min(stocks[i].second, (k / stocks[i].first));
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << buyMaximumProducts(n, k, arr);
}