// 191 CHOCOLA –Chocolate

//  We are given a bar of chocolate composed of m*n square pieces. One should break the chocolate into single squares. Parts of the chocolate may be broken along the vertical and horizontal lines as indicated by the broken lines in the picture.
// A single break of a part of the chocolate along a chosen vertical or horizontal line divides that part into two smaller ones. Each break of a part of the chocolate is charged a cost expressed by a positive integer. This cost does not depend on the size of the part that is being broken but only depends on the line the break goes along. Let us denote the costs of breaking along consecutive vertical lines with x1, x2, ..., xm-1 and along horizontal lines with y1, y2, ..., yn-1.
// The cost of breaking the whole bar into single squares is the sum of the successive breaks. One should compute the minimal cost of breaking the whole chocolate into single squares.
//  For example, if we break the chocolate presented in the picture first along the horizontal lines, and next each obtained part along vertical lines then the cost of that breaking will be y1+y2+y3+4*(x1+x2+x3+x4+x5).

// Task

// Write a program that for each test case:
//     Reads the numbers x1, x2, ..., xm-1 and y1, y2, ..., yn-1
//     Computes the minimal cost of breaking the whole chocolate into single squares, writes the result.

// Input

// One integer in the first line, stating the number of test cases, followed by a blank line. There will be not more than 20 tests.
// For each test case, at the first line there are two positive integers m and n separated by a single space, 2 <= m,n <= 1000. In the successive m-1 lines there are numbers x1, x2, ..., xm-1, one per line, 1 <= xi <= 1000. In the successive n-1 lines there are numbers y1, y2, ..., yn-1, one per line, 1 <= yi <= 1000.
// The test cases will be separated by a single blank line.

// Output

// For each test case : write one integer - the minimal cost of breaking the whole chocolate into single squares.

#include <bits/stdc++.h>
using namespace std;

long long minCost(int m, int n, vector<int> &x, vector<int> &y)
{
    long long cost = 0;
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());
    int i = 0, j = 0, xpieces = 1, ypieces = 1;
    while (i < m && j < n)
    {
        if ((xpieces * x[i]) > (ypieces * y[j]))
        {
            cost += xpieces * x[i];
            ypieces++;
            i++;
        }
        else
        {
            cost += ypieces * y[j];
            xpieces++;
            j++;
        }
    }
    while (i < m)
    {
        cost += xpieces * x[i];
        ypieces++;
        i++;
    }
    while (j < n)
    {
        cost += ypieces * y[j];
        xpieces++;
        j++;
    }
    return cost;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> x(m - 1), y(n - 1);
        for (int i = 0; i < m - 1; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> y[i];
        }
        cout << minCost(m - 1, n - 1, x, y) << endl;
    }
}