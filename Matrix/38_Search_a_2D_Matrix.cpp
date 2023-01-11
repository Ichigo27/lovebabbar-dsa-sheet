// 38 Search an element in a matriix

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

//     Integers in each row are sorted from left to right.
//     The first integer of each row is greater than the last integer of the previous row.

#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 BRUTE FORCE
// Iterate each row and column in search of target. If found return true or return false.
// Time Complexity: O(m*n)
// Space Complexity: O(1)

// APPROACH 2 BINARY SEARCH
// Time Complexity: O(log(m*n)) =O(log(m) + log(n))
// Auxiliary Space: O(1). 
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() == 0)
        return false;
    int r = matrix.size();
    int c = matrix[0].size();
    int low = 0, high = (r * c) - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        int i = mid / c;
        int j = mid % c;
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

// Another appraoch works for gfg question as well (https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)
// https://youtu.be/ZYpYur0znng
// Traverse using while loop till i is less than n and j is greater than equal to zero.
// if mat[i][j] == 0 return true;
// if greater than it means the element exists in another row therefore increment i.
// if less than decrement j because this means element exist in that row only.
// at end if not found return false.
// Time Complexity: O(n*m)
// Auxiliary Space: O(1)
// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     int n = matrix.size();
//     int i = 0;
//     int j = matrix[0].size() - 1;

//     while (i < n && j >= 0)
//     {
//         if (matrix[i][j] == target)
//             return true;
//         if (target < matrix[i][j])
//             --j;
//         else
//             ++i;
//     }
//     return false;
// }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int x;
    cin >> x;
    cout << searchMatrix(arr, x);
}