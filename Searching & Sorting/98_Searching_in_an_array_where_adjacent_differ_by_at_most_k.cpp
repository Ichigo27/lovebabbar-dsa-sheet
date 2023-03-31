// 98 Searching in an array where adjacent differ by at most k

// A step array is an array of integers where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence of the key.

#include <bits/stdc++.h>
using namespace std;

// A Simple Approach is to traverse the given array one by one and compare every element with the given element ‘x’. If matches, then return index.

// The above solution can be Optimized using the fact that the difference between all adjacent elements is at most k. The idea is to start comparing from the leftmost element and find the difference between the current array element and x. Let this difference be ‘diff’. From the given property of the array, we always know that x must be at least ‘diff/k’ away, so instead of searching one by one, we jump ‘diff/k’.

// Time Complexity: O(n)
// Auxiliary Space: O(1)
int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
            return i;
        i = i + max(1, abs(arr[i] - x) / k);
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;
    cout << search(arr, n, x, k);
}