// Find shortest unique prefix for every word in a given list

// Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

// https://www.youtube.com/watch?v=CB-WeyCFjlc

class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
    int freq;

    TrieNode()
    {
        freq = 0;
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
        child->freq++;
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

private:
    string buildPrefixUtil(TrieNode *root, string key, int i)
    {
        if (root->freq == 1)
            return key.substr(0, i);
        int index = key[i] - 'a';
        return buildPrefixUtil(root->children[index], key, i + 1);
    }

public:
    string buildPrefix(string key)
    {
        return buildPrefixUtil(root, key, 0);
    }
};

vector<string> findPrefixes(string arr[], int n)
{
    Trie *t = new Trie();
    for (int i = 0; i < n; i++)
        t->insert(arr[i]);
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(t->buildPrefix(arr[i]));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<string> ans = findPrefixes(arr, n);
    for (auto i : ans)
        cout << i << " ";
}