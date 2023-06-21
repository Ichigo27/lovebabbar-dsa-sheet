// 234 Implement Kruksal’sAlgorithm

#include <bits/stdc++.h>
using namespace std;

void makeSet(int v, vector<int> &parent, vector<int> &rank)
{
    parent[v] = v;
    rank[v] = 0;
}

int findParent(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank)
{
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b)
    {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}


// time complexity: O(ElogE)
// space complexity: O(E+V)
vector<pair<pair<int, int>, int>> calculateKrushkalsMST(int n, int m, vector<pair<pair<int, int>, int>> edges)
{
    vector<int> parent(n + 1);
    vector<int> rank(n + 1);
    for (int i = 1; i <= n; i++)
    {
        makeSet(i, parent, rank);
    }
    vector<pair<pair<int, int>, int>> mst;
    sort(edges.begin(), edges.end(), compare);
    for (auto it : edges)
    {
        int u = it.first.first;
        int v = it.first.second;
        int weight = it.second;
        if (findParent(u, parent) != findParent(v, parent))
        {
            unionSet(u, v, parent, rank);
            mst.push_back({{u, v}, weight});
        }
    }
    return mst;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }
    vector<pair<pair<int, int>, int>> mst = calculateKrushkalsMST(n, m, edges);
    for (auto it : mst)
    {
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    }
}