// 165 Water Connection Problem

// There are n houses and p water pipes in Geek Colony. Every house has at most one pipe going into it and at most one pipe going out of it. Geek needs to install pairs of tanks and taps in the colony according to the following guidelines.
// 1. Every house with one outgoing pipe but no incoming pipe gets a tank on its roof.
// 2. Every house with only one incoming and no outgoing pipe gets a tap.
// The Geek council has proposed a network of pipes where connections are denoted by three input values: ai, bi, di denoting the pipe of diameter di from house ai to house bi.
// Find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes wherever possible.
// Note: The generated output will have the following format. The first line will contain t, denoting the total number of pairs of tanks and taps installed. The next t lines contain three integers each: house number of tank, house number of tap, and the minimum diameter of pipe between them.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
{
    // code here
}

int main()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(p), b(p), d(p);
    for (int i = 0; i < p; i++)
        cin >> a[i] >> b[i] >> d[i];
    vector<vector<int>> ans = solve(n, p, a, b, d);
    cout << ans.size() << endl;
    for(auto &ele: ans)
    {
        cout << ele[0] << ' ' << ele[1] << ' ' << ele[2] << endl;
    }
}
