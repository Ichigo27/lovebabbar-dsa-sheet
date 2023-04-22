// 168 Maximum trains for which stoppage can be provided

// You are given n-platform and two main running railway tracks for both directions. Trains that need to stop at your station must occupy one platform for their stoppage and the trains which need not stop at your station will run away through either of the main track without stopping. Now, each train has three values first arrival time, second departure time, and the third required platform number. We are given m such trains you have to tell the maximum number of trains for which you can provide stoppage at your station.

// Note: Trains are given in the form of {arrival time, departure time, platform Number} and the arrival time and departure time are represented by a 4-digit integer as 1030 will represent 10:30 and 912 will represent 09:12 (24 hour Clock).

#include <bits/stdc++.h>
using namespace std;

int maxStop(int n, int m, vector<vector<int>> &trains)
{
    int res = 0;
    vector<vector<pair<int, int>>> platforms(n + 1);
    for (int i = 0; i < m; i++)
    {
        platforms[trains[i][2]].push_back({trains[i][1], trains[i][0]});
    }
    for (int i = 1; i <= n; i++)
    {
        if (platforms[i].empty())
            continue;

        sort(platforms[i].begin(), platforms[i].end());

        res++;
        int prevIdx = 0;

        for (int j = 1; j < platforms[i].size(); j++)
        {
            if (platforms[i][prevIdx].first <= platforms[i][j].second)
            {
                prevIdx = j;
                res++;
            }
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> trains(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> trains[i][0] >> trains[i][1] >> trains[i][2];
    }
    cout << maxStop(n, m, trains);
}