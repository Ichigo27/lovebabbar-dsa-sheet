// 6 Find the Union and Intersection of the two sorted arrays.

// Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

#include <bits/stdc++.h>
using namespace std;

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