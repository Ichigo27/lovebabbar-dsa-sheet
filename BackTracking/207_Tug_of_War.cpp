// 207 Tug of War

// Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the absolute difference of the sum of two subsets is as minimum as possible. If n is even, then sizes of two subsets must be strictly n/2 and if n is odd, then size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^n)
// SpaceComplexity: O(n)

void solve(int i, int sum1, int sum2, int &diff, vector<int> &arr, vector<int> &g1, vector<int> &g2, vector<int> &res)
{
    if (i == arr.size())
    {
        if (g1.size() == (arr.size() + 1) / 2)
        {
            if (abs(sum1 - sum2) < diff)
            {
                diff = abs(sum1 - sum2);
                for (int k = 0; k < res.size(); k++)
                {
                    res[k] = 1;
                }
                for (int k = 0; k < g1.size(); k++)
                {
                    res[g1[k]] = 2;
                }
            }
        }
        return;
    }

    if (g1.size() < (arr.size() + 1) / 2)
    {
        g1.push_back(i);
        solve(i + 1, sum1 + arr[i], sum2, diff, arr, g1, g2, res);
        g1.pop_back();
    }
    g2.push_back(i);
    solve(i + 1, sum1, sum2 + arr[i], diff, arr, g1, g2, res);
    g2.pop_back();
}

void tugOfWar(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, 0);
    vector<int> g1, g2;
    int diff = INT_MAX;
    solve(0, 0, 0, diff, arr, g1, g2, res);
    for (int i = 0; i < arr.size(); i++)
    {
        if (res[i] == 1)
            cout << arr[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        if (res[i] == 2)
            cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    tugOfWar(arr);
}