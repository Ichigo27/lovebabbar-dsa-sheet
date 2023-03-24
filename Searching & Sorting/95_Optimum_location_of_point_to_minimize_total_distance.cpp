// 95 Optimum location of point to minimize total distance

// Given a set of coordinates points of the form [p, q] and a line L of the form ax + by + c = 0. The task is to find a point on a given line for which the sum of distances from a given set of coordinates is minimum.

#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, pair<int, int> p)
{
    return sqrt(((x1 - p.first) * (x1 - p.first)) + ((y1 - p.second) * (y1 - p.second)));
}

double compute(tuple<int, int, int> l, vector<pair<int, int>> p, int n, double x)
{
    double res = 0;
    double y = (-(get<0>(l) * x) - get<2>(l)) / get<1>(l);
    for (int i = 0; i < n; i++)
    {
        res += dist(x, y, p[i]);
    }
    return res;
}

double findOptimumCost(tuple<int, int, int> l, vector<pair<int, int>> p, int n)
{
    double low = -1e6;
    double high = 1e6;
    while ((high - low) > 1e-6)
    {
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;

        double dist1 = compute(l, p, n, mid1);
        double dist2 = compute(l, p, n, mid2);

        if (dist1 < dist2)
            high = mid2;
        else
            low = mid1;
    }
    return round(compute(l, p, n, (low + high) / 2) * 100.0) / 100.0;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    tuple<int, int, int> l(a, b, c);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    cout << findOptimumCost(l, p, n);
}