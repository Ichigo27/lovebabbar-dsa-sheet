// 17 Best time to buy and Sell stock

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
//  we need to find max⁡(prices[j]−prices[i]), for every i and j such that j>i
// Time complexity: O(n^2). Loop runs n(n−1)/2​ times.
// Space complexity: O(1). Only two variables are used.

// Approach 2: One Pass
    // Time complexity: O(n). Only a single pass is needed.
    // Space complexity: O(1). Only two variables are used.
int maxProfit(vector<int> &prices)
{
    int low = INT_MAX;
    int ans = 0;

    for(auto price: prices)
    {
        if(price < low)
        {
            low = price;
        }
        else
        {
            if(price - low > ans)
            {
                ans = max(ans, price - low);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(prices);
}