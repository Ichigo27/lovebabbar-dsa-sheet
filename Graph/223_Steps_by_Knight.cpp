// 223 Minimum Step by Knight

// Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

// Note:
// The initial and the target position coordinates of Knight have been given according to 1-base indexing.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^2)
// Auxiliary Space: O(N^2)

// Backtracking does not work because in some cases then knight will be stuck in a loop and will never reach the target. So we use BFS.

vector<int> xMoves = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> yMoves = {1, -1, 1, -1, 2, 2, -2, -2};

bool isValid(int i, int j, vector<vector<int>> &board)
{
    int n = board.size();
    if (i < 0 || j < 0 || i >= n || j >= n || board[i][j] == 0)
        return false;
    return true;
}

int solve(int cx, int cy, int dx, int dy, vector<vector<int>> &board)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{cx, cy}, 0});
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int w = q.front().second;
        q.pop();
        if(board[x][y] == 0)
            continue;
        board[x][y] = 0;
        if (x == dx && y == dy)
        {
            return w;
        }
        for (int i = 0; i < 8; i++)
        {
            int nx = x + xMoves[i];
            int ny = y + yMoves[i];
            int nw = w + 1;
            if (isValid(nx, ny, board) == true)
                q.push({{nx, ny}, nw});
        }
    }
    return -1;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    vector<vector<int>> board(N, vector<int>(N, 1));
    return solve(KnightPos[0] - 1, KnightPos[1] - 1, TargetPos[0] - 1, TargetPos[1] - 1, board);
}

int main()
{
    int N;
    cin >> N;
    vector<int> KnightPos(2);
    vector<int> TargetPos(2);
    cin >> KnightPos[0] >> KnightPos[1];
    cin >> TargetPos[0] >> TargetPos[1];
    cout << minStepToReachTarget(KnightPos, TargetPos, N);
}