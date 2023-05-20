// 186 DEFKIN -Defense of a Kingdom

// Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.

// The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.

// This position has a penalty of 12.

// Help Theodore write a program that calculates the penalty of the given position.
// Input

// The first line of the input file contains the number of test cases.

// Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

// Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).
// Output

// For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.

#include <bits/stdc++.h>
using namespace std;

int calcPenalty(int h, int w, int n, vector<int> &x, vector<int> &y)
{
    int maxHeight = 0, maxWidth = 0;
    x.push_back(0);
    x.push_back(h + 1);
    y.push_back(0);
    y.push_back(w + 1);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < x.size() - 1; i++)
    {
        maxHeight = max(maxHeight, x[i + 1] - x[i] - 1);
        maxWidth = max(maxWidth, y[i + 1] - y[i] - 1);
    }
    return maxHeight * maxWidth;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, w, n;
        cin >> h >> w >> n;
        vector<int> X, Y;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            X.push_back(x);
            Y.push_back(y);
        }
        cout << calcPenalty(h, w, n, X, Y) << endl;
    }
}