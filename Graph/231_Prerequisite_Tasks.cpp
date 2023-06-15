// 231 Find whether it is possible to finish all tasks or not from given dependencies

// There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisites, for example to pick task 0 you have to first pick task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks and a list of prerequisite pairs, is it possible for you to finish all tasks?

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Auxiliary Space: O(V)
bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    vector<int> indegree(N, 0);
    vector<int> adj[N];
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
        indegree[prerequisites[i].first]++;
    }
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        count++;
        for (auto it : adj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return count == N;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> prerequisites;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        prerequisites.push_back({a, b});
    }
    cout << isPossible(n, prerequisites);
}