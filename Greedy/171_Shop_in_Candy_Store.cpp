// 171 Find the minimum and maximum amount to buy all N candies

// In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
// You are now provided with an attractive offer.
// For every candy you buy from the store and get at most K other candies ( all are different types ) for free.
// Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
// In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(NLogN)
// Auxiliary Space: O(1)
vector<int> candyStore(int candies[], int N, int K)
{
    int n = N, k = K;
    sort(candies, candies + N);
    int mn = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        // Buy current candy
        mn += candies[i];

        // And take k candies for free
        // from the last
        n = n - k;
    }
    n = N, k = K;
    int index = 0;
    for (int i = n - 1; i >= index; i--)
    {
        // Buy candy with maximum amount
        mx += candies[i];

        // And get k candies for free from
        // the starting
        index += k;
    }
    return {mn, mx};
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
    vector<int> ans = candyStore(arr, n, k);
    for (auto ele : ans)
        cout << ele << ' ';
}