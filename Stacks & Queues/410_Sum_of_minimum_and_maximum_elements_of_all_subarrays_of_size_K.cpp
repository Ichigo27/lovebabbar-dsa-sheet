// 410 Sum of minimum and maximum elements of all subarrays of size “k”.

// You are given an array consisting of N integers, and an integer, K. Your task is to determine the total sum of the minimum element and the maximum element of all subarrays of size K.

// The array may contain duplicate elements.
// The array can also contain negative integers.
// The size of the array is at least 2.
// There exists at least one such subarray of size k.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/_gJ3to4RyeQ?t=7342

long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
    long long res = 0;
    deque<int> mini, maxi;
    for (int i = 0; i < k; i++)
    {
        while (!mini.empty() && nums[mini.back()] >= nums[i])
            mini.pop_back();
        while (!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();
        mini.push_back(i);
        maxi.push_back(i);
    }
    res += nums[mini.front()] + nums[maxi.front()];
    for (int i = k; i < n; i++)
    {
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while (!mini.empty() && nums[mini.back()] >= nums[i])
            mini.pop_back();
        while (!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();
        mini.push_back(i);
        maxi.push_back(i);
        res += nums[mini.front()] + nums[maxi.front()];
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << sumOfMaxAndMin(nums, n, k) << endl;
}
