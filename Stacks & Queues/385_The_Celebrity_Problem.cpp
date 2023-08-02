// 385 The celebrity Problem

// A celebrity is a person who is known to all but does not know anyone at a party.If you go to a party of N people, find if there is a celebrity in the party or not .A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person.Here M[i][i] will always be 0. Note : Follow 0 based indexing.Follow Up : Can you optimize it to O(N)

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=9u2BJfmWNEg

bool rowCheck(vector<vector<int>> &M, int celeb)
{
    for (int i = 0; i < M[celeb].size(); i++)
        if (M[celeb][i] == 1)
            return false;
    return true;
}

bool colCheck(vector<vector<int>> &M, int celeb)
{
    for (int i = 0; i < M.size(); i++)
        if (celeb != i && M[i][celeb] == 0)
            return false;
    return true;
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);
    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (M[a][b] == 1)
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int celeb = s.top();
    return rowCheck(M, celeb) && colCheck(M, celeb) ? celeb : -1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    cout << celebrity(M, n);
    return 0;
}