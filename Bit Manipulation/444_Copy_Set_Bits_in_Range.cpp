// 444 Copy set bits in a range

// Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 32. You have to copy the set bits of 'Y' in the range L to R in 'X'. Return this modified X.
// Note: Range count will be from Right to Left & start from 1.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=v7pUZw-ZOYU
int setSetBit(int x, int y, int l, int r)
{
    int mask = ((1 << (r - l + 1)) - 1) << (l - 1);
    return (y & mask) | x;
}

int main()
{
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    cout << setSetBit(x, y, l, r);
}