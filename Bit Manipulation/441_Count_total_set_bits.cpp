// 441 Count total set bits in all numbers from 1 to n

// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

#include <bits/stdc++.h>
using namespace std;

int largestPowerof2(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return x - 1;
}

int countSetBits(int n)
{
    if (n == 0)
        return 0;
    int x = largestPowerof2(n);
    int bitsuptox = (1 << (x - 1)) * x;
    int msb2n = n - (1 << x) + 1;
    int rest = n - (1 << x);
    int ans = bitsuptox + msb2n + countSetBits(rest);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
}