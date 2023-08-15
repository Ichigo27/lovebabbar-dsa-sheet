// Implement a Phone Directory

// Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
// Note: If there is no match between query and contacts, print "0".

#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

// https://www.youtube.com/watch?v=SK2S5lQegVg

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

private:
    void getSuggestionsUtil(TrieNode *curr, string key, vector<string> &temp)
    {
        if (curr->isLeaf)
        {
            temp.push_back(key);
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (curr->children[ch - 'a'] != NULL)
            {
                key.push_back(ch);
                getSuggestionsUtil(curr->children[ch - 'a'], key, temp);
                key.pop_back();
            }
        }
    }

public:
    vector<vector<string>> getSuggestions(string key)
    {
        TrieNode *prev = root;
        vector<vector<string>> ans;
        string prefix = "";
        for (int i = 0; i < key.length(); i++)
        {
            char ch = key[i];
            prefix.push_back(ch);
            TrieNode *curr = prev->children[ch - 'a'];
            if (curr == NULL)
            {
                while (i < key.length())
                {
                    ans.push_back({"0"});
                    i++;
                }
                return ans;
            }
            vector<string> temp;
            getSuggestionsUtil(curr, prefix, temp);
            ans.push_back(temp);
            prev = curr;
        }
        return ans;
    }
};

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    Trie *t = new Trie();
    for (int i = 0; i < n; i++)
    {
        t->insert(contact[i]);
    }
    return t->getSuggestions(s);
}

int main()
{
    int n;
    cin >> n;
    string contact[n];
    for (int i = 0; i < n; i++)
        cin >> contact[i];
    string s;
    cin >> s;
    vector<vector<string>> ans = displayContacts(n, contact, s);
    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
}