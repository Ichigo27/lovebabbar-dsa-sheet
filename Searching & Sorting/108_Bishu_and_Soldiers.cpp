// 108 Bishu and Soldiers

// Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round, Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in the previous round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and the total sum of their powers.

// INPUT:

// The first line of the input contains N, the number of soldiers.
// The second line contains an array of N numbers denoting the power of each soldier
// This third line contains Q, which denotes the number of rounds.
// Q lines follow, each line having one number denoting the power of Bishu.

// OUTPUT:

// For each round, the output should be an array of two numbers. The first number should be the number of soldiers that Bishu can beat, and the second number denotes the cumulative strength of all the soldiers that Bishu can beat.

// CONSTRAINTS:

// 1<=N<=10000
// 1<=power of each soldier<=100
// 1<=Q<=10000
// 1<=power of bishu<=100

#include <bits/stdc++.h>
using namespace std;

// Prefix Sum and Binary Search
// Time Complexity: O(NlogN)
// Space Complexity: O(N)

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int pf[n + 1];
    pf[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + arr[i - 1];
    }
    int r;
    cin >> r;
    while (r--)
    {
        int p;
        cin >> p;
        int res = upper_bound(arr, arr + n, p) - arr;
        cout << res  << ' ' << pf[res] << endl;
    }
}