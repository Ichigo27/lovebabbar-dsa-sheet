// Print unique rows in a given boolean matrix

// Given a binary matrix your task is to find all unique rows of the given matrix in the order of their appearance in the matrix.

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

// https://www.youtube.com/watch?v=GixyVinjtFk

#define SIZE 2

class TrieNode
{
public:
    TrieNode *children[SIZE];
    bool isLeaf;

    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < SIZE; i++)
            children[i] = NULL;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

private:
    bool insertUtil(TrieNode *root, int M[MAX][MAX], int n, int m, int i, int j)
    {
        if (j == m)
        {
            if (root->isLeaf == false)
            {
                root->isLeaf = true;
                return true;
            }
            else
            {
                return false;
            }
        }
        int index = M[i][j];
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode();
            root->children[index] = child;
        }
        return insertUtil(child, M, n, m, i, j + 1);
    }

public:
    bool insert(int M[MAX][MAX], int n, int m, int i, int j)
    {
        return insertUtil(root, M, n, m, i, j);
    }
};

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    vector<vector<int>> ans;
    Trie *t = new Trie();
    for (int i = 0; i < row; i++)
    {
        if(t->insert(M, row, col, i, 0) == true)
        {
            vector<int> v(col);
            for (int j = 0; j < col; j++)
                v[j] = M[i][j];
            ans.push_back(v);
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int M[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
    vector<vector<int>> ans = uniqueRow(M, n, m);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}