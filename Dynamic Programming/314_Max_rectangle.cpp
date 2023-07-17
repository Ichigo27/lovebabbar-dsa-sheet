// 314 Largest area rectangular sub-matrix with equal number of 1’s and 0’s [ IMP ]

// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=X0X6G-eWgQ8
// https://www.youtube.com/watch?v=jC_cWLy7jSI
// https://www.youtube.com/watch?v=tOylVCugy9k
// Time Complexity: O(N*M)
// Space Complexity: O(M)
long long getMaxArea(long long arr[], int n)
{
    long long ans = 0;
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] > arr[i]))
        {
            int height = arr[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            ans = max(ans, height * 1LL * width);
        }
        st.push(i);
    }
    return ans;
}

int maxArea(int a[1000][1000], int n, int m)
{
    long long area = 0;
    long long arr[m];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
                arr[i] += 1;
            else
                arr[i] = 0;
        }
        for (int j = 0; j < m; j++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
        long long curr = getMaxArea(arr, m);
        area = max(area, curr);
    }
    return area;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[1000][1000];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cout << maxArea(a, n, m) << endl;
}