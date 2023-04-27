// 179 Maximum sum of absolute difference of an array

// Given a number N. We have to find maximum sum of all permutations of numbers from 1 to N. The maximum sum will be sum of absolute difference of adjacent elements in array.

#include <bits/stdc++.h>
using namespace std;

int maxSum(int N)
{
    if (N == 1)
        return 1;
    return (N * (N - 1) / 2) - 1 + N / 2;
}

// another question
// https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/

int main()
{
    int n;
    cin >> n;
    cout << maxSum(n);
}