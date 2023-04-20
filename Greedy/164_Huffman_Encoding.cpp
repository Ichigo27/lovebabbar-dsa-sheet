// 164 Huffman Coding

// Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
// Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

#include <bits/stdc++.h>
using namespace std;

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
    // Code here
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];
    vector<string> ans = huffmanCodes(s, f, n);
    for(auto ele: ans)
        cout << ele << ' ';
}