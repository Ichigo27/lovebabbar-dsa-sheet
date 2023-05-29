// 199 Printing all solutions in N-Queen Problem

// The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

#include <bits/stdc++.h>
using namespace std;

// optimized solution using hashing
// https://www.youtube.com/watch?v=i05Ju7AftcM
// Time Complexity: O(n!)
// Auxiliary Space: O(n)
void solve(int i, int n, vector<int> &l, vector<int> &tl, vector<int> &bl, vector<int> &pos, vector<vector<int>> &ans)
{
    if (i == n)
    {
        ans.push_back(pos);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (l[j] == 0 && tl[i + j] == 0 && bl[n - 1 + i - j] == 0)
        {
            pos.push_back(j + 1);
            l[j] = 1;
            tl[i + j] = 1;
            bl[n - 1 + i - j] = 1;
            solve(i + 1, n, l, tl, bl, pos, ans);
            l[j] = 0;
            tl[i + j] = 0;
            bl[n - 1 + i - j] = 0;
            pos.pop_back();
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> ans;
    vector<int> pos;
    vector<int> left(n, 0), topleft(2 * n - 1, 0), bottomleft(2 * n - 1, 0);
    solve(0, n, left, topleft, bottomleft, pos, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans = nQueen(n);
    for(auto &ele: ans)
    {
        for (int i = 0; i < ele.size(); i++)
        {
            cout << ele[i] << ' ';
        }
        cout << endl;
    }
}
