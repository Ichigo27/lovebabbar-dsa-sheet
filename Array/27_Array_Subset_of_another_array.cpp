// 27 Find whether an array is a subset of another array

// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. 

#include <bits/stdc++.h>
using namespace std;

// Naive Approach
// Use two loops: The outer loop picks all the elements of arr2[] one by one. The inner loop linearly searches for the element picked by the outer loop. If all elements are found then return 1, else return 0.
// Time Complexity: O(m*n)
// Auxiliary Space: O(1)

// using Sorting and Merging
// The idea is to sort the two arrays and then iterate on the second array looking for the same values on the first array using two pointers. Whenever we encounter the same values we will increment both the pointer and if we encounter any values less than that of the second array, we will increment the value of the pointer pointing to the first array. If the value is greater than that of the second array, we know the second array is not the subset of the first array.
// Time Complexity: O(mLog(m) + nlog(m))
// Auxiliary Space: O(1)

// using Maps
// The idea is to store the frequency of the elements present in the first array, then look for the elements present in arr2[] in the frequency array. As no new elements are found in arr2[] hence is the subset.
// Time Complexity: O(m+n)
// Auxiliary Space: O(n)
string isSubset(int a1[], int a2[], int n, int m)
{
    if (n < m)
        return "No";
    unordered_map<int, int> hsh;
    for (int i = 0; i < n; i++)
    {
        hsh[a1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (hsh[a2[i]] > 0)
            hsh[a2[i]]--;
        else
            return "No";
    }
    return "Yes";
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    cout << isSubset(arr1, arr2, n1, n2);
}