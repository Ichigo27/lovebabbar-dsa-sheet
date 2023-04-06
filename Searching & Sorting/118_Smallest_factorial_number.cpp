// 118 Smallest number with atleastn trailing zeroes infactorial

// Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=0y6Hy5zLSkk
// Time Complexity: O(logN), using binary search
// Auxiliary Space: O(1)
bool is_possible(int num, int n)
{
    int prod = 5, cnt = 0;
    while (num >= prod)
    {
        cnt += num / prod;
        prod *= 5;
    }
    if (cnt >= n)
        return true;
    return false;
}

int findNum(int n)
{
    int low = 0, high = 5 * n, mid, res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (is_possible(mid, n))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << findNum(n);
}