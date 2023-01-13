// 42 Maximum size rectangle

// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

#include <bits/stdc++.h>
using namespace std;

// Approach: 
// An interesting method is discussed that uses largest rectangle under histogram as a subroutine.
// If the height of bars of the histogram is given then the largest area of the histogram can be found. This way in each row, the largest area of bars of the histogram can be found. To get the largest rectangle full of 1's, update the next row with the previous row and find the largest area under the histogram, i.e. consider each 1's as filled squares and 0's with an empty square and consider each row as the base.
// https://www.youtube.com/watch?v=X0X6G-eWgQ8
// https://www.youtube.com/watch?v=jC_cWLy7jSI
// https://www.youtube.com/watch?v=tOylVCugy9k
// Time Complexity : O(n*m)
// Auixiliary Space : O(m)
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxA = 0;
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, height * width);
        }
        st.push(i);
    }
    return maxA;
}

int maxArea(vector<vector<int>> &matrix, int n, int m)
{
    int maxA = 0;
    vector<int> heights(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
                heights[j] += matrix[i][j];
            else
                heights[j] = 0;
        }
        int area = largestRectangleArea(heights);
        maxA = max(maxA, area);
    }
    return maxA;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << maxArea(arr, n, m);
}