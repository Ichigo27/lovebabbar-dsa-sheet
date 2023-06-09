// 206 The Knight’s tour problem

// Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules of chess knight must visit each square exactly once. Print the order of each cell in which they are visited.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : There are N2 Cells and for each, we have a maximum of 8 possible moves to choose from, so the worst running time is O(8N^2).

// Auxiliary Space: O(N2)

vector<int> xMoves = {2, 1, -1, -2, -2, -1, 1, 2};
vector<int> yMoves = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, vector<vector<int>> &sol)
{
    int n = sol.size();
    if (x >= 0 && y >= 0 && x < n && y < n && sol[x][y] == -1)
        return true;
    return false;
}

bool solve(int x, int y, int total, vector<vector<int>> &sol)
{
    int n = sol.size();
    if (total == n * n)
        return true;
    for (int k = 0; k < 8; k++)
    {
        int newX = x + xMoves[k];
        int newY = y + yMoves[k];
        if (isValid(newX, newY, sol))
        {
            sol[newX][newY] = total;
            if (solve(newX, newY, total + 1, sol) == true)
                return true;
            sol[newX][newY] = -1;
        }
    }
    return false;
}

void printAns(vector<vector<int>> &sol)
{
    int n = sol.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << sol[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> sol(n, vector<int>(n, -1));
    sol[0][0] = 1;
    if (solve(0, 0, 1, sol) == true)
    {
        printAns(sol);
    }
    else
    {
        cout << "Solution does not exist";
    }
}