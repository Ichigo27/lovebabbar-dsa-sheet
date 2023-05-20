// 184 Smallest subset with sum greater than all other elements

// You are given an array Arr of size N containing non-negative integers. Your task is to choose the minimum number of elements such that their sum should be greater than the sum of the rest of the elements of the array.

#include <bits/stdc++.h>
using namespace std;

int minSubset(vector<int> &Arr, int N)
{
    long long halfSum = 0, currSum = 0;
    double temp = 0;
    for (int i = 0; i < N; i++)
    {
        temp += Arr[i] / 2.0;
    }
    halfSum = ceil(temp);
    sort(Arr.begin(), Arr.end(), greater<int>());
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        currSum += Arr[i];
        res++;
        if (currSum > halfSum)
            return res;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minSubset(arr, n);
}