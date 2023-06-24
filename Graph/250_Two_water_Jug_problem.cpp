// 250 Water Jug problem using BFS

// You are at the side of a river. You are given a m litre jug and a n litre jug . Both the jugs are initially empty. The jugs dont have markings to allow measuring smaller quantities. You have to use the jugs to measure d litres of water . Determine the minimum no of operations to be performed to obtain d litres of water in one of the jugs.

// The operations you can perform are:
//      Empty a Jug
//      Fill a Jug
//      Pour water from one jug to the other until one of the jugs is either empty or full.

#include <bits/stdc++.h>
using namespace std;

// time complexity: O(V+E)
// space complexity: O(V)

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int minSteps(int m, int n, int d)
{
    if (m > n)
        swap(m, n);
    if (d == 0)
        return 0;
    if (d > n)
        return -1;
    if ((d % gcd(n, m)) != 0)
        return -1;
    vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    visited[0][0] = true;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int curr = q.front().first;
            int j1 = q.front().second.first;
            int j2 = q.front().second.second;
            q.pop();

            if (j1 == d || j2 == d)
                return curr;

            if (!visited[j1][0])
            {
                q.push({curr + 1, {j1, 0}});
                visited[j1][0] = true;
            }
            if (!visited[0][j2])
            {
                q.push({curr + 1, {0, j2}});
                visited[0][j2] = true;
            }
            if (!visited[m][j2])
            {
                q.push({curr + 1, {m, j2}});
                visited[m][j2] = true;
            }
            if (!visited[j1][n])
            {
                q.push({curr + 1, {j1, n}});
                visited[j1][n] = true;
            }

            int d1 = min(j1, n - j2);
            if (!visited[j1 - d1][j2 + d1])
            {
                q.push({curr + 1, {j1 - d1, j2 + d1}});
                visited[j1 - d1][j2 + d1] = true;
            }
            int d2 = min(m - j1, j2);
            if (!visited[j1 + d2][j2 - d2])
            {
                q.push({curr + 1, {j1 + d2, j2 - d2}});
                visited[j1 + d2][j2 - d2] = true;
            }
        }
    }
    return -1;
}

int main()
{
    int m, n, d;
    cin >> m >> n >> d;
    cout << minSteps(m, n, d);
}