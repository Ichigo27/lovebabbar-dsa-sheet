// 315 Maximum sum rectangle in a 2D matrix

// Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=Lz_EB2xsrwA
// Time Complexity: O(R*R*C)
// Space Complexity: O(C)
int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    int ans = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        vector<int> arr(C, 0);
        for (int j = i; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                arr[k] += M[j][k];
            }
            int sum = 0;
            for (int k = 0; k < C; k++)
            {
                sum += arr[k];
                ans = max(ans, sum);
                if(sum < 0)
                    sum = 0;
            }
        }
    }
    return ans == INT_MIN ? -1 : ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
    cout << maximumSumRectangle(n, m, M) << endl;
}