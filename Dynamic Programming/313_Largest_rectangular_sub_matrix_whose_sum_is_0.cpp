// 313 Largest rectangular sub-matrix whose sum is 0

// Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.
// If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one starting from minimum row index. If you still have multiple solutions return the one having greatest row number. If no such matrix is present return a zero (0) size matrix.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=xbA4E70kcKE
// Time Complexity: O(R*R*C)
// Space Complexity: O(C)
pair<int, int> maxLen(vector<int> &arr, int n)
{
    int sum = 0, start = -1, end = -1;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0)
        {
            start = i;
            end = i;
        }
        if (sum == 0)
        {
            start = 0;
            end = i;
        }
        if (mp.find(sum) != mp.end())
        {
            if (i - mp[sum] > end - start + 1)
            {
                start = mp[sum] + 1;
                end = i;
            }
        }
        else
            mp[sum] = i;
    }
    return {start, end};
}

vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
{
    int R = a.size();
    int C = a[0].size();
    int flag = 0;
    int sr, er, sc, ec;
    for (int i = 0; i < R; i++)
    {
        vector<int> arr(C, 0);
        for (int j = i; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                arr[k] += a[j][k];
            }
            // cout << "Array : ";
            // for (int k = 0; k < C; k++)
            // {
            //     cout << arr[k] << ' ';
            // }
            // cout << endl;
            pair<int, int> temp = maxLen(arr, C);
            if (temp.first == -1 || temp.second == -1)
                continue;
            int nsr = temp.first;
            int ner = temp.second;
            int nsc = i;
            int nec = j;
            if (flag == 0)
            {
                sr = nsr;
                er = ner;
                sc = nsc;
                ec = nec;
                flag = 1;
            }
            else if (((er - sr + 1) * (ec - sc + 1)) < ((ner - nsr + 1) * (nec - nsc + 1)))
            {
                sr = nsr;
                er = ner;
                sc = nsc;
                ec = nec;
            }
            else if (((er - sr + 1) * (ec - sc + 1)) == ((ner - nsr + 1) * (nec - nsc + 1)))
            {
                if(nsr < sr)
                {
                    sr = nsr;
                    er = ner;
                    sc = nsc;
                    ec = nec;
                }
                else if (nsr == sr)
                {
                    if (nsc < sc)
                    {
                        sr = nsr;
                        er = ner;
                        sc = nsc;
                        ec = nec;
                    }
                }
            }
        }
    }
    if (flag == 0)
        return vector<vector<int>>();
    vector<vector<int>> ans(ec - sc + 1, vector<int>(er - sr + 1, 0));
    for (int i = sc; i <= ec; i++)
    {
        for (int j = sr; j <= er; j++)
        {
            ans[i - sc][j - sr] = a[i][j];
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<int>> ans = sumZeroMatrix(a);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}