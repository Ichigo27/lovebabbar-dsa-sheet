// 270 Assembly Line Scheduling Problem

// A car factory has two assembly lines, and also given an  2D array a[2][] of size N which represent the time taken by each station. Each station is dedicated to some sort of work like engine fitting, body fitting, painting, and so on. So, a car chassis must pass through each of the n stations in order before exiting the factory. The two parallel assemble line perform same task.
// From any line one can switch another line diagonally. A 2D array T[2][] of size N is also given, which represent  exit time to switch line 1 to line 2 diagonally.
// Also each assembly line takes an entry time ei and exit time xi which may be different for the two lines.

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &e, vector<int> &x)
{
    if (j == n)
        return x[i];
    if (i == 0)
        return min(a[i][j] + solve(i, j + 1, n, a, T, e, x), a[i][j] + T[i][j] + solve(i + 1, j + 1, n, a, T, e, x));
    else
        return min(a[i][j] + solve(i, j + 1, n, a, T, e, x), a[i][j] + T[i][j] + solve(i - 1, j + 1, n, a, T, e, x));
}

int carAssembly(vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &e, vector<int> &x)
{
    return min(e[0] + solve(0, 0, a[0].size() - 1, a, T, e, x), e[1] + solve(1, 0, a[0].size() - 1, a, T, e, x));
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<vector<int>> T(2, vector<int>(n - 1));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n - 1; j++)
            cin >> T[i][j];
    vector<int> e(2);
    for (int i = 0; i < 2; i++)
        cin >> e[i];
    vector<int> x(2);
    for (int i = 0; i < 2; i++)
        cin >> x[i];
    cout << carAssembly(a, T, e, x) << endl;
}