// 12 Merge 2 sorted arrays without using Extra space.

// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#include <bits/stdc++.h>
using namespace std;

// method 1: Use Array 3 of size n+m and two pointer at the beginning of each array to compare
// Time Complexity : O(n+m)
// Auxilliary Space : O(n+m)

// method 2: Insertion sort like algo where we choose smaller element else we swap and reorder it
// Time Complexity : O(n*m)
// Auxilliary Space : O(1)

// method 3: Gap Method
// https://www.youtube.com/results?search_query=Merge+Without+Extra+Space
// Time Complexity :  O((n+m) log(n+m))
// Auxilliary Space : O(1)
void merge(long long arr1[], long long arr2[], int n, int m)
{
    float gap = (n + m + 0.0) / 2;
    while (gap >= 1)
    {
        int step = ceil(gap);
        for (int i = 0, j = step; i < n + m && j < n + m; i++, j++)
        {
            if (i < n && j < n)
            {
                if (arr1[i] > arr1[j])
                    swap(arr1[i], arr1[j]);
            }
            else if (i < n && j >= n)
            {
                if (arr1[i] > arr2[j - n])
                    swap(arr1[i], arr2[j - n]);
            }
            else if (i >= n && j >= n)
            {
                if (arr2[i - n] > arr2[j - n])
                    swap(arr2[i - n], arr2[j - n]);
            }
        }
        gap = step * 1.0 / 2;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    long long arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    merge(arr1, arr2, n, m);
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
}