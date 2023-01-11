// 40 Find row with maximum no. of 1's

// Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

#include <bits/stdc++.h>
using namespace std;

// Simple Method
// Do a row-wise traversal of the matrix, count the number of 1s in each row, and compare the count with max Finally, return the index of the row with maximum 1s.
// Time Complexity:  O(m*n)
// Space Complexity:  O(1)

// Binary Search
// Since each row is sorted, we can use Binary Search to count of 1s in each row. We find the index of first instance of 1 in each row.
// Time Complexity: O(m*log(n)) where m is number of rows and n is number of columns in matrix.
// Auxiliary Space:  O(log(n)), as implicit stack is created due to recursion.

// Optimized Version
//   Time Complexity: O(N+M)
//   Space Complexity: O(1)

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int ans = -1;
    int max = 0;
    int ones = 0;
    int j = m - 1;
    for (int i = 0; i < n; i++)
        {
            while (arr[i][j] == 1)
            {
                ones++;
                j--;
            }
            if (j < 0)
                return i;
            if (ones > max)
            {
                max = ones;
                ans = i;
            }
        }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << rowWithMax1s(arr, n, m);
}