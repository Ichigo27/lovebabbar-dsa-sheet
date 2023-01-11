// 37 Spiral traversal on a Matrix

// Given a matrix of size r*c. Traverse the matrix in spiral form.

#include <bits/stdc++.h>
using namespace std;

// Optimal 6Approach
// The problem can be solved by dividing the matrix into loops or squares or boundaries. It can be seen that the elements of the outer loop are printed first in a clockwise manner then the elements of the inner loop is printed. So printing the elements of a loop can be solved using four loops that print all the elements. Every 'for' loop defines a single direction movement along with the matrix. The first for loop represents the movement from left to right, whereas the second crawl represents the movement from top to bottom, the third represents the movement from the right to left, and the fourth represents the movement from bottom to up.
// https://www.youtube.com/watch?v=1ZGJzvkcLsA
// Time Complexity: O(m*n). 
// Auxiliary Space: O(1). 
vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    // code here
    vector<int> ans;
    int left = 0, top = 0, right = c - 1, bottom = r - 1;
    int direction = 0;
    while (left <= right && top <= bottom)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        else if (direction == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        direction = (direction + 1) % 4;
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
    vector<int> ans = spirallyTraverse(arr, n, m);
    for (auto x : ans)
        cout << x << ' ';
}