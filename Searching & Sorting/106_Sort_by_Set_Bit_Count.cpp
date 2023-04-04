// 106 Sort array according to count of set bits

// Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements.

// Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/mY1O1-OSLnw
// Time complexity: O(n log n)
// Auxiliary Space: O(n)

int count(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        if (n % 2)
            cnt++;
        n /= 2;
    }
    return cnt;
}

void sortBySetBitCount(int arr[], int n)
{
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int temp = count(arr[i]);
        mp[-temp].push_back(arr[i]);
    }
    int i = 0;
    for (auto &nums : mp)
    {
        for (auto ele : nums.second)
        {
            arr[i] = ele;
            i++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sortBySetBitCount(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}