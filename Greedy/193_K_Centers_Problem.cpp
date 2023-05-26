// 193 K Centers Problem

// You have given N cities numbered from 0 to N-1. The distance between each pair of cities is given by N * N matrix MAT where MAT[i][j] denotes the distance between city i and j.
// The task is to select K (K<= N) ATM servers  in such a way that the maximum distance of a city from the ATM Server is minimized.

#include <bits/stdc++.h>
using namespace std;

int selectKcities(int n, int k, vector<vector<int>> &mat)
{
    // code here
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(k));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << selectKcities(n, k, mat);
}