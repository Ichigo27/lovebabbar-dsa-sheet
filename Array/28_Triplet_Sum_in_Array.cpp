// 28 Find the triplet that sum to a given value

// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

#include <bits/stdc++.h>
using namespace std;

// Method 1: naive approach
// A simple method is to generate all possible triplets and compare the sum of every triplet with the given value.
// Time Complexity: O(n^3)
// Auxiliary Space: O(1)

// Method 2: using hashing
// Time Complexity: O(n^2)
// Auxiliary Space: O(n)
// bool find3Numbers(int A[], int n, int X)
// {
//     unordered_map<int, int> hsh;
//     for (int i = 0; i < n; i++)
//     {
//         hsh[A[i]] = i;
//     }
//     for (int i = 0; i < n - 2; i++)
//     {
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             if(hsh[X-A[i]-A[j]] > j)
//                 return true;
//         }
//     }
//     return false;
// }

// Method 3: two-pointer technique
// By Sorting the array the efficiency of the algorithm can be improved. This efficient approach uses the two-pointer technique. Traverse the array and fix the first element of the triplet. Now use the Two Pointers algorithm to find if there is a pair whose sum is equal to x – array[i].
// Time Complexity: O(n^2)
// Auxiliary Space: O(1)
bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
    sort(A, A + arr_size);
    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < arr_size - 2; i++)
    {

        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the
        // remaining elements
        r = arr_size - 1; // index of the last element
        while (l < r)
        {
            if (A[i] + A[l] + A[r] == sum)
            {
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    // If we reach here, then no triplet was found
    return false;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << find3Numbers(arr, n, x);
}