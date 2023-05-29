// 202 Sudoku Solver

// Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

// A sudoku solution must satisfy all of the following rules:

//     Each of the digits 1-9 must occur exactly once in each row.
//     Each of the digits 1-9 must occur exactly once in each column.
//     Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

#include <bits/stdc++.h>
using namespace std;

#define N 9

bool isValid(int grid[N][N], int row, int col, int key)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == key)
            return false;
        if (grid[i][col] == key)
            return false;
        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == key)
            return false;
    }
    return true;
}

// Function to find a solved Sudoku.
bool SolveSudoku(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int k = 1; k <= N; k++)
                {
                    if (isValid(grid, i, j, k))
                    {
                        grid[i][j] = k;
                        if(SolveSudoku(grid) == true)
                            return true;
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << ' ';
        }
    }
}

int main()
{
    int grid[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }
    if (SolveSudoku(grid) == true)
    {
        printGrid(grid);
    }
    else
    {
        cout << 0 << endl;
    }
}
