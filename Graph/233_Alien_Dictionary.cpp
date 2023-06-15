// 233 Given a sorted Dictionary of an Alien Language, find order of characters

// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N + K)
// Space Complexity: O(K)
string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string word1 = dict[i];
        string word2 = dict[i + 1];
        for (int j = 0; j < min(word1.length(), word2.length()); j++)
        {
            if (word1[j] != word2[j])
            {
                adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                break;
            }
        }
    }
    vector<int> indegree(K, 0);
    for (int i = 0; i < K; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    string ans = "";
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr + 'a');
        for (auto it : adj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string dict[n];
    for (int i = 0; i < n; i++)
        cin >> dict[i];
    cout << findOrder(dict, n, k);
}