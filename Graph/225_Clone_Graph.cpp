// 225 Clone a graph

// Given a reference of a node in a connected undirected graph.
// Return a deep copy (clone) of the graph.
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};


// Time complexity: O(V + E)
// Space complexity: O(V)


// bfs
Node *cloneGraph(Node *node)
{
    if(node == NULL)
        return NULL;
    if(node->neighbors.size() == 0)
        return new Node(node->val);
    unordered_map<Node *, Node *> mp;
    queue<Node *> q;
    q.push(node);
    mp[node] = new Node(node->val);
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        for(auto &neighbor: node->neighbors)
        {
            if(mp.find(neighbor) == mp.end())
            {
                mp[neighbor] = new Node(neighbor->val);
                q.push(neighbor);
            }
            mp[curr]->neighbors.push_back(mp[neighbor]);
        }
    }
    return mp[node];
}

// dfs
// https://www.youtube.com/watch?v=mQeF6bN8hMk
Node *cloneGraph(Node *node)
{
    if(node == NULL)
        return NULL;
    if(node->neighbors.size() == 0)
        return new Node(node->val);
    unordered_map<Node *, Node *> mp;
    stack<Node *> st;
    st.push(node);
    mp[node] = new Node(node->val);
    while(!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        for(auto &neighbor: node->neighbors)
        {
            if(mp.find(neighbor) == mp.end())
            {
                mp[neighbor] = new Node(neighbor->val);
                st.push(neighbor);
            }
            mp[curr]->neighbors.push_back(mp[neighbor]);
        }
    }
    return mp[node];
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<Node *> adj(v + 1);
    for (int i = 1; i <= v; i++)
        adj[i] = new Node(i);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u]->neighbors.push_back(adj[v]);
        adj[v]->neighbors.push_back(adj[u]);
    }
    Node *ans = cloneGraph(adj[1]);
}
