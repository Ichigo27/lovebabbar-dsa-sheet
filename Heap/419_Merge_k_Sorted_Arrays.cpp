// 419 Merge “K” sorted arrays. [ IMP ]

// Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/eccAKrmffh8?t=940

class Node
{
public:
    int i;
    int j;
    int data;
    Node(int i, int j, int data)
    {
        this->i = i;
        this->j = j;
        this->data = data;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> ans;
    priority_queue<Node *, vector<Node *>, Compare> minHeap;
    for (int i = 0; i < K; i++)
        minHeap.push(new Node(i, 0, arr[i][0]));
    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp->data);
        if (temp->j + 1 < K)
        {
            minHeap.push(new Node(temp->i, temp->j + 1, arr[temp->i][temp->j + 1]));
        }
    }
    return ans;
}

int main()
{
    int K;
    cin >> K;
    vector<vector<int>> arr(K, vector<int>(K));
    for (int i = 0; i < K; ++i)
        for (int j = 0; j < K; ++j)
            cin >> arr[i][j];
    vector<int> output = mergeKArrays(arr, K);
    for (int i = 0; i < K * K; ++i)
        cout << output[i] << " ";
}