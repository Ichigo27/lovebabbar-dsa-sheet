// 44 Rotate matrix by 90 degrees

// Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.

#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-image/solutions/1037232/rotate-image/?orderBy=most_votes

// Approach 1: Rotate Groups of Four Cells
// We can iterate over each group of four cells and rotate them.
// Time Complexity: O(n*n)
// Auxiliary Space: O(1)
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = temp;
        }
    }
}

// Approach 2: Reverse on Diagonal and then Reverse Left to Right
// Rotating the matrix is to firstly reverse the matrix around the main diagonal, and then reverse it from left to right. These operations are called transpose and reflect in linear algebra.
// Time Complexity: O(n*n)
// Auxiliary Space: O(1)
// void rotate(vector<vector<int>> &matrix)
// {
//     transpose(matrix);
//     reflect(matrix);
// }

// void transpose(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             int tmp = matrix[j][i];
//             matrix[j][i] = matrix[i][j];
//             matrix[i][j] = tmp;
//         }
//     }
// }

// void reflect(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n / 2; j++)
//         {
//             int tmp = matrix[i][j];
//             matrix[i][j] = matrix[i][n - j - 1];
//             matrix[i][n - j - 1] = tmp;
//         }
//     }
// }

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    rotate(arr);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}