// Word Break Problem | (Trie solution)

// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;

    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
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
    void insertUtil(TrieNode *root, string key)
    {
        if (key.length() == 0)
        {
            root->isLeaf = true;
            return;
        }
        int index = key[0] - 'a';
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
        insertUtil(child, key.substr(1));
    }

public:
    void insert(string key)
    {
        insertUtil(root, key);
    }

private:
    bool searchUtil(TrieNode *root, string key)
    {
        if (key.length() == 0)
        {
            return root->isLeaf;
        }
        int index = key[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, key.substr(1));
    }

public:
    bool search(string key)
    {
        return searchUtil(root, key);
    }
};

bool solve(Trie *t, string &A, int pos)
{
    if (pos >= A.size())
        return true;
    for (int i = pos; i < A.length(); i++)
    {
        string prefix = A.substr(pos, i - pos + 1);
        if ((t->search(prefix) && solve(t, A, i + 1)) == true)
            return true;
    }
    return false;
}

int wordBreak(string A, vector<string> &B)
{
    Trie *t = new Trie();
    for (int i = 0; i < B.size(); i++)
    {
        t->insert(B[i]);
    }
    return solve(t, A, 0);
}

int main()
{
    int n;
    cin >> n;
    vector<string> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];
    string A;
    cin >> A;
    cout << wordBreak(A, B) << endl;
}