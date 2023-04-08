// 122 Subset Sums

// Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S (including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.
// Input

// The first line of standard input contains the three integers N, A, and B. The following N lines contain S1 through SN, in order.
// Output

// Print a single integer to standard output representing the number of subsets satisfying the above property. Note that the answer may overflow a 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=VCZ4lqfZRPk

void solve(long long arr[], long long start, long long end, vector<long long> &v)
{
    long long s = 0;
    long long n = end - start + 1;
    for (long long i = 0; i < (1 << n); i++)
    { // pow(2,n)
        s = 0;
        long long x = i;
        long long j = start;
        while (x)
        {
            long long l = x & 1; // odd or even nothing but x%2
            if (l)
                s += arr[j];
            j++;
            x = x >> 1; // nothing but n/2
        }
        v.push_back(s);
    }
}

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> v1, v2;
    solve(arr, 0, (n / 2) - 1, v1);
    solve(arr, (n / 2), n - 1, v2);
    sort(v2.begin(), v2.end());
    long long count = 0;
    for (long long i = 0; i < v1.size(); i++)
    {
        long long low = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin();
        long long high = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin();
        count += (high - low);
    }
    cout << count;
    return 0;
}