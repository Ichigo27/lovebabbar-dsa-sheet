// Given a sequence of words, print all anagrams together

// Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.
// Note: The final output will be in lexicographic order.

#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

class IndexNode
{
public:
    int index;
    IndexNode *next;

    IndexNode(int index)
    {
        this->index = index;
        this->next = NULL;
    }
};

class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
    IndexNode *head;

    TrieNode()
    {
        head = NULL;
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
    void insertUtil(TrieNode *root, string key, int i)
    {
        if (key.length() == 0)
        {
            root->isLeaf = true;
            if (root->head == NULL)
            {
                root->head = new IndexNode(i);
            }
            else
            {
                IndexNode *curr = root->head;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = new IndexNode(i);
            }
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
        insertUtil(child, key.substr(1), i);
    }

public:
    void insert(string key, int i)
    {
        insertUtil(root, key, i);
    }

private:
    void findAnagramsUtil(TrieNode *root, vector<string> &string_list, vector<vector<string>> &ans)
    {
        if (root == NULL)
            return;
        if (root->isLeaf)
        {
            vector<string> temp2;
            IndexNode *curr = root->head;
            while (curr != NULL)
            {
                temp2.push_back(string_list[curr->index]);
                curr = curr->next;
            }
            ans.push_back(temp2);
        }
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            findAnagramsUtil(root->children[i], string_list, ans);
        }
    }

public:
    vector<vector<string>> findAnagrams(vector<string> &string_list)
    {
        vector<vector<string>> ans;
        findAnagramsUtil(root, string_list, ans);
        return ans;
    }
};

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    Trie *t = new Trie();
    for (int i = 0; i < string_list.size(); i++)
    {
        string temp = string_list[i];
        sort(temp.begin(), temp.end());
        t->insert(temp, i);
    }
    return t->findAnagrams(string_list);
}

int main()
{
    int n;
    cin >> n;
    vector<string> string_list(n);
    for (int i = 0; i < n; i++)
        cin >> string_list[i];
    vector<vector<string>> result = Anagrams(string_list);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
}