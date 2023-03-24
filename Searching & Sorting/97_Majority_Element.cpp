// 97 find majority element

// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity : O(n^2)
// Space Complexity : O(1)


// Using Hashing
// Time Complexity : O(n)
// Space Complexity : O(n)


// Using Moore's Voting Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)
// int majorityElement(int a[], int size)
// {
//     int count = 1;
//     int res = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (a[res] == a[i])
//             count++;
//         else
//             count--;
//         if (count == 0)
//         {
//             res = i;
//             count = 1;
//         }
//     }
//     count = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (a[res] == a[i])
//             count++;
//     }
//     if (count <= size / 2)
//         return -1;
//     else
//         return a[res];
// }

// Using Binary Search
// Time Complexity : O(nlogn)
// Space Complexity : O(1)
int majorityElement(int a[], int size)
{
    sort(a, a + size);
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == a[size / 2])
            count++;
    }
    if (count <= size / 2)
        return -1;
    else
        return a[size / 2];
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << majorityElement(arr, n);
}
