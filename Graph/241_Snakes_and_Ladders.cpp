// 241 Snake and Ladders Problem

// You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

// You start on square 1 of the board. In each move, starting from square curr, do the following:

//     Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
//         This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
//     If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
//     The game ends when you reach the square n2.

// A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

// Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

//     For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.

// Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

#include <bits/stdc++.h>
using namespace std;

// approach 1
// time complexity O(n^2)
// space complexity O(n^2)
int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    vector<int> moves(n * n + 1, INT_MAX);
    moves[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == n * n)
            return moves[curr];
        for (int i = curr + 1; i <= min(curr + 6, n * n); i++)
        {
            int row = (i - 1) / n;
            int col = (i - 1) % n;
            int next = board[n - 1 - row][row % 2 ? n - 1 - col : col];
            if (next == -1)
                next = i;
            if (moves[next] > moves[curr] + 1)
            {
                moves[next] = moves[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

// approach 2
// time complexity O(n^2)
// space complexity O(n^2)
int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    vector<int> flattendBoard(n * n + 1, 0);
    int i = n - 1, j = 0, k = 1;
    bool leftToRight = true;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == -1)
            flattendBoard[k] = k;
        else
            flattendBoard[k] = board[i][j];
        k++;
        if (leftToRight)
        {
            j++;
            if (j == n)
            {
                j--;
                i--;
                leftToRight = false;
            }
        }
        else
        {
            j--;
            if (j == -1)
            {
                j++;
                i--;
                leftToRight = true;
            }
        }
    }
    vector<int> moves(n * n + 1, INT_MAX);
    moves[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == n * n)
            return moves[curr];
        for (int i = curr + 1; i <= min(curr + 6, n * n); i++)
        {
            int next = flattendBoard[i];
            if (moves[next] > moves[curr] + 1)
            {
                moves[next] = moves[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

    int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << snakesAndLadders(board);
}