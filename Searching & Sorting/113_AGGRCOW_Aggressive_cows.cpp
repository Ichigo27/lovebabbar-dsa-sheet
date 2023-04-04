// 113 Aggressive cows

// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
// Input

// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi
// Output

// For each test case output one integer: the largest minimum distance.

#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> &pos, int c, int k)
{
    int prev = pos[0];
    int cnt = 1;
    for (int i = 1; i < pos.size(); i++)
    {
        if (pos[i] - prev < k)
            continue;
        cnt++;
        prev = pos[i];
        if (cnt == c)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> pos(n);
        int low = 0, high = 0, mid;
        for (int i = 0; i < n; i++)
        {
            cin >> pos[i];
            high =max(high, pos[i]);
        }
        sort(pos.begin(), pos.end());
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (is_possible(pos, c, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        if(is_possible(pos,c,high))
           cout << high << endl;
        else
           cout << low << endl;
    }
}