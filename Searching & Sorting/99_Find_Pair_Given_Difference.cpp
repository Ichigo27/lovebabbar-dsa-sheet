// 99 find a pair with a given difference

// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*log(n))
// Auxiliary Space: O(1)
bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
    {
        int low = 0;
        int high = size - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] - arr[i] == n && mid != i)
                return 1;
            else if (arr[mid] - arr[i] > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return 0;
}

int main()
{
    int n, num;
    cin >> n >> num;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findPair(arr, n, num);
}