// 264 Program for nth Catalan Number

// Given a number N. The task is to find the Nth catalan number.
// The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
// Catalan Number for N is equal to the number of expressions containing N pairs of paranthesis that are correct matched, i.e., for each of the N '(' there exist N ')' on there right and vice versa.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=ncZrBVWgnIA
// Catalan number is given by:
// C(n) = (2n)! / ((n + 1)! * n!)
// C(n) = (2nCn) / (n + 1)
// C(n) = summation(i = 0 to n - 1) C(i) * C(n - i - 1)
// time complexity: O(n^2)
// space complexity: O(n)
int findCatalan(int n)
{
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << findCatalan(n) << endl;
}