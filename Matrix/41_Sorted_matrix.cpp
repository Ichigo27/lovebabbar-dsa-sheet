// 41 Print elements in sorted order using row - column wise sorted matrix

// Given an NxN matrix Mat. Sort all elements of the matrix.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N2LogN)
// Auxillary Space: O(N2)
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    vector<int> nums(N * N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            nums[(N * i) + j] = Mat[i][j];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Mat[i][j] = nums[(N * i) + j];
    return Mat;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    vector<vector<int>> ans = sortedMatrix(n, arr);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}