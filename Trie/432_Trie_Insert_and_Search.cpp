// Construct a trie from scratch

// Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.

#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;

    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

void insertUtil(TrieNode *root, string key)
{
    if (key.length() == 0)
    {
        root->isLeaf = true;
        return;
    }
    int index = key[0] - 'a';
    TrieNode *child;
    if(root->children[index]  != NULL)
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

// Function to insert string into TRIE.
void insert(TrieNode *root, string key)
{
    insertUtil(root, key);
}

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

// Function to use TRIE data structure and search the given string.
bool search(TrieNode *root, string key)
{
    return searchUtil(root, key);
}

int main()
{
    int n;
    cin >> n;
    string keys[n];
    for(int i = 0; i < n; i++)
        cin >> keys[i];
    struct TrieNode *root = new TrieNode();
    for(int i = 0; i < n; i++)
        insert(root, keys[i]);
    string abc;
    cin >> abc;
    cout << search(root, abc) << endl;
}