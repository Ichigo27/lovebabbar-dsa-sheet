// 440 Count number of bits to be flipped to convert A to B

// You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log(max(A, B)))
// Auxiliary Space: O(1)
int countBitsFlip(int a, int b)
{
    int cnt = a ^ b;
    int res = 0;
    while (cnt)
    {
        cnt = cnt & (cnt - 1);
        res++;
    }
    return res;
}

// Time Complexity: O(1)
// Auxiliary Space: O(1)
int countBitsFlip(int a, int b)
{
    return __builtin_popcount(a ^ b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << countBitsFlip(a, b) << endl;
}