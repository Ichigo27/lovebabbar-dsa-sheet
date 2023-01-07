// 6 Find the Union and Intersection of the two sorted arrays.

// Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

#include <bits/stdc++.h>
using namespace std;

// Method 1 (Using Set):
// Time Complexity: O(m * log(m) + n * log(n))
// Auxiliary Space: O(m + n)

// Method 2: We can improve performance of getUnion method by iterating over both the arrays for index from 0 to min(n, m)-1 adding all the elements in both the arrays to the set, and then iterate over the other array with the remaining elements and add them to the set.
// Time Complexity: O( max(m,n) )
// Auxiliary Space: O(max(m, n))

// Method 2: (Using map data structure)
// Time Complexity : O(m + n)
// Auxiliary Space : O(m + n)
int doUnion(int a[], int n, int b[], int m)
{
    unordered_set<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        ans.insert(b[i]);
    }
    return ans.size();
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << doUnion(a, n, b, m);
}