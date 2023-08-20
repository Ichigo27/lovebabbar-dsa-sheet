// 442 Program to find whether a no is power of two

// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some integer x.

#include <bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n)
{
    if (n == 0)
        return false;
    return !(n & (n - 1));
}

int main()
{
    long long n;
    cin >> n;
    cout << isPowerofTwo(n) << endl;
}