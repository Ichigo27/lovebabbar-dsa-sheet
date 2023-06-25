// 254 Paths to travel each nodes using each edge (Seven Bridges)

// There are n nodes and m bridges in between these nodes. Print the possible path through each node using each edges (if possible), traveling through each edges only once.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=8MpoO2zA2l4
// time complexity: O(V+E)
// space complexity: O(V+E)

// Check if the graph has an Eulerian Path.
bool graphHasEulerianPath(vector<int> adj[], int v, vector<int> outdegree, vector<int> indegree)
{
    // Count how many vertices have in-degree and out-degree difference > 1.
    int start = 0, end = 0;
    for (int i = 0; i < v; i++)
    {
        if (outdegree[i] - indegree[i] > 1 || indegree[i] - outdegree[i] > 1)
            return false;
        else if (outdegree[i] - indegree[i] == 1)
            start++;
        else if (indegree[i] - outdegree[i] == 1)
            end++;
    }

    // If more than 2 vertices have in-degree and out-degree difference > 1, return false.
    return ((start == 0 && end == 0) || (start == 1 && end == 1));
}

// Find a start node for DFS traversal.
int findStartNode(int v, vector<int> indegree, vector<int> outdegree)
{
    // A start node must have one more outgoing edge than incoming edge.
    // So, we look for a node that has an outdegree that is one more than its indegree.
    // If we can't find one, we return the first node with a nonzero outdegree.
    int start = 0;
    for (int i = 0; i < v; i++)
    {
        if (outdegree[i] - indegree[i] == 1)
            return i;
        if (outdegree[i] > 0)
            start = i;
    }
    return start;
}

// DFS traversal.
void dfs(int start, vector<int> adj[], vector<int> &outdegree)
{
    //while there are edges from the start node
    while (outdegree[start] != 0)
    {
        //get the next node to go to
        int next = adj[start][--outdegree[start]];
        //go to the next node
        dfs(next, adj, outdegree);
    }
    //print the node
    cout << start << " ";
}

// Eulerian path.
void eulerianPath(int v, vector<vector<int>> edges)
{
    vector<int> adj[v];
    vector<int> outdegree(v, 0), indegree(v, 0);

    // Create adjacency list and count in-degree and out-degree of each vertex.
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        outdegree[edge[0]]++;
        indegree[edge[1]]++;
    }

    // If there is no Eulerian Path, then return
    if (!graphHasEulerianPath(adj, v, outdegree, indegree))
    {
        cout << "No Eulerian Path" << endl;
        return;
    }

    // Find the start node and call dfs
    int start = findStartNode(v, indegree, outdegree);
    dfs(start, adj, outdegree);
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    eulerianPath(v, edges);
}