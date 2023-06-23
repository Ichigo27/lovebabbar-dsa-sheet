// 249 Oliver and the Game

// Oliver and Bob are best friends. They have spent their entire childhood in the beautiful city of Byteland. The people of Byteland live happily along with the King.
// The city has a unique architecture with total N houses. The King's Mansion is a very big and beautiful bungalow having address = 1. Rest of the houses in Byteland have some unique address, (say A), are connected by roads and there is always a unique path between any two houses in the city. Note that the King's Mansion is also included in these houses.
// Oliver and Bob have decided to play Hide and Seek taking the entire city as their arena. In the given scenario of the game, it's Oliver's turn to hide and Bob is supposed to find him.
// Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person, for finding Oliver, he either goes towards the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible path till the last house on that path.
// Oliver runs and hides in some house (say X) and Bob is starting the game from his house (say Y). If Bob reaches house X, then he surely finds Oliver.

// Given Q queries, you need to tell Bob if it is possible for him to find Oliver or not.
// The queries can be of the following two types:
// 0 X Y : Bob moves towards the King's Mansion.
// 1 X Y : Bob moves away from the King's Mansion

// INPUT :
// The first line of the input contains a single integer N, total number of houses in the city. Next N-1 lines contain two space separated integers A and B denoting a road between the houses at address A and B.
// Next line contains a single integer Q denoting the number of queries.
// Following Q lines contain three space separated integers representing each query as explained above.

// OUTPUT :
// Print "YES" or "NO" for each query depending on the answer to that query.

// CONSTRAINTS :
// 1 ≤ N ≤ 10^5
// 1 ≤ A,B ≤ N
// 1 ≤ Q ≤ 5*10^5
// 1 ≤ X,Y ≤ N

#include <bits/stdc++.h>
using namespace std;

// Euler tour technique
// used to find if a node is ancestor of another node
// https://www.youtube.com/watch?v=5h1JYjin_4o
// time complexity : O(n+q)
// space complexity : O(n)

void dfs(int node, int par, vector<int> &intime, vector<int> &outtime, vector<int> adj[], int &timer)
{
    intime[node] = timer++;
    for (auto it : adj[node])
    {
        if (it != par)
        {
            dfs(it, node, intime, outtime, adj, timer);
        }
    }
    outtime[node] = timer++;
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> intime(n + 1), outtime(n + 1);
    int timer = 1;
    dfs(1, 0, intime, outtime, adj, timer);
    int q;
    cin >> q;
    while (q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0)
        {
            if (intime[y] > intime[x] && outtime[y] < outtime[x])
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            if (intime[y] < intime[x] && outtime[y] > outtime[x])
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}