// 9 Minimise the maximum difference between heights [V.IMP]

// Given an array arr[] denoting heights of N towers and a positive integer K.
// For each tower, you must perform exactly one of the following operations exactly once.
// Increase the height of the tower by K
// Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

#include <bits/stdc++.h>
using namespace std;

// Follow the steps below to solve the given problem:

// 1. Sort the array 
// 2. Try to make each height of the tower maximum by decreasing the height of all the towers to the right by k and increasing all the height of the towers to the left by k. Check whether the current index tower has the maximum height or not by comparing it with a[n]-k. If the tower's height is greater than the a[n]-k then it's the tallest tower available.
// 3. Similarly, find the shortest tower and minimize the difference between these two towers.

// Time Complexity: O(N * log(N)), Time is taken for sorting
// Auxiliary Space: O(1)

// editorial - https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
// video - https://www.youtube.com/watch?v=Av7vSnPSCtw

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;
    for (int i = 1; i < n; i++)
    {
        int temp1 = max(arr[i - 1] + k, largest);
        int temp2 = min(arr[i] - k, smallest);
        if (temp2 < 0)
            continue;
        ans = min(ans, temp1 - temp2);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << getMinDiff(arr, n, k);
}